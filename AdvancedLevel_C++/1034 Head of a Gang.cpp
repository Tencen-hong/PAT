#include <iostream>

using namespace std;

#include <unordered_map>
#include <map>
#include <vector>

struct node {
    unordered_map<string, int> member;
};

unordered_map<string, bool> visit;
vector<string> gang;
unordered_map<string, node> m;

void dfs(string v) {//深度遍历相互有联系的人，加入同一个团伙
    if (!visit[v]) {
        gang.push_back(v);
        visit[v] = true;
        for (auto item: m[v].member) {
            if (!visit[item.first])
                dfs(item.first);
        }
    }
}

int main() {

    int n, k, cnt = 0;
    cin >> n >> k;

    unordered_map<string, int> person;
    map<string, int> res;

    for (int i = 0; i < n; ++i) {
        string per1, per2;
        int templen;
        cin >> per1 >> per2 >> templen;
        if (person.find(per1) == person.end())
            person[per1] = 0;
        if (person.find(per2) == person.end())
            person[per2] = 0;
        person[per1] += templen; //统计每个人的总通话时长
        person[per2] += templen;

        visit[per1] = false;
        visit[per2] = false;
        m[per1].member[per2] = 0;//各个直接通话的人建立连接
        m[per2].member[per1] = 0;
    }

    for (auto it: m) {
        gang.clear();
        if (!visit[it.first]) {
            dfs(it.first);
        }
        int sum = 0, maxn = -1;
        string head = "";
        for (int i = 0; i < gang.size(); ++i) {//统计团伙通话总时长，和团伙中最长通话个人
            sum += person[gang[i]];
            if (person[gang[i]] > maxn) {
                maxn = person[gang[i]];
                head = gang[i];
            }
        }
        sum = sum / 2;
        if (sum > k && gang.size() >= 3) { //满足相应的条件，累加团伙数量和成员数量，记录头目
            cnt++;
            res[head] = gang.size();
        }

    }

    if (cnt == 0) {
        cout << 0;
        return 0;
    }

    cout << cnt << endl;
    for (auto it:res) {
        cout << it.first << ' ' << it.second << endl;
    }

    return 0;
}
