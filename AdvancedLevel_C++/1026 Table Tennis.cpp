#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
struct person {
    int arrive, start, time;//到达时间，开始服务时间，娱乐时间
    bool vip;
} tempperson;
struct tablenode {
    int end = 8 * 3600, num;//结束时间，服务人数
    bool vip;
};
vector<person> player;
vector<tablenode> table;

bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}

bool cmp2(person a, person b) {
    return a.start < b.start;
}

int findnextvip(int vipid) {
    vipid++;
    while (vipid < player.size() && !player[vipid].vip) {
        vipid++;
    }
    return vipid;
}

void alloctable(int personid, int tableid) {
    if (player[personid].arrive <= table[tableid].end)//来的比桌子结束早
        player[personid].start = table[tableid].end;
    else
        player[personid].start = player[personid].arrive;
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
}

int main() {
    int n, k, m, viptable;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int h, m, s, temptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
        tempperson.arrive = h * 3600 + m * 60 + s;
        tempperson.start = 21 * 3600;
        if (tempperson.arrive >= 21 * 3600)//到达时间超过21点
            continue;
        tempperson.time = temptime <= 120 ? temptime * 60 : 120 * 60;//不超过2h
        tempperson.vip = flag == 1;
        player.push_back(tempperson);
    }
    scanf("%d %d", &k, &m);
    table.resize(k + 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }//#
    sort(player.begin(), player.end(), cmp1);//按到达时间排序
    int i = 0, vipid = -1;
    vipid = findnextvip(vipid);//下一个要处理的vip
    while (i < player.size()) {
        int index = -1, minendtime = 9999999;
        for (int j = 1; j <= k; ++j) {
            if (table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }//找到最快结束的桌子
        if (table[index].end >= 21 * 3600)
            break;//最快结束的桌子超过21点,可以结束了
        if (player[i].vip && i < vipid) {
            i++;
            continue;
        }//vip有插队的，跳过已经处理过的vip
        if (table[index].vip) {//空出来vip桌子
            if (player[i].vip) {//空出来的是vip桌子，且等待的人是vip
                alloctable(i, index);
                if (vipid == i)
                    vipid = findnextvip(vipid);
                i++;
            } else {
                if (vipid < player.size() && player[vipid].arrive <= table[index].end) {
                    alloctable(vipid, index);
                    vipid = findnextvip(vipid);//队列中有vip，vip插队
                } else {//队列中无vip，分配给普通用户
                    alloctable(i, index);
                    i++;
                }
            }
        } else {//空出来的是普通桌子
            if (!player[i].vip) {//且当前等待的是普通用户,直接分配
                alloctable(i, index);
                i++;
            } else {//当前等待是vip，则寻找vip桌子
                int vipindex = -1, minvipendtime = 99999999;
                for (int j = 1; j <= k; ++j) {
                    if (table[j].vip && table[j].end < minvipendtime) {
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                if (vipindex != -1 && player[i].arrive >= table[vipindex].end) {//有空vip桌子,分配vip桌子给vip用户
                    alloctable(i, vipindex);
                    if (vipid == i)
                        vipid = findnextvip(vipid);
                    i++;
                } else {//无空vip桌子，分配普通桌子给vip用户
                    alloctable(i, index);
                    if (vipid == i)
                        vipid = findnextvip(vipid);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmp2);//按开始服务时间排序
    for (int i = 0; i < player.size() && player[i].start < 21 * 3600; ++i) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }
    for (int i = 1; i <= k; ++i) {
        if (i != 1)
            printf(" ");
        printf("%d", table[i].num);
    }

    return 0;
}
