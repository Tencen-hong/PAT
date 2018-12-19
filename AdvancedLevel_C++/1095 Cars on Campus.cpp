#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    int time;
    string plate_number;
    int state;
};

bool cmp1(node a, node b) {
    if (a.plate_number != b.plate_number)
        return a.plate_number < b.plate_number;
    else
        return a.time < b.time;
}

bool cmp2(node a, node b) {
    return a.time < b.time;
}

int main() {
    vector<node> total, car;
    int max_time = 0;
    int n, k;
    cin >> n >> k;

    node temp;
    int hh, mm, ss;
    string state;

    total.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp.plate_number;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp.time = hh * 60 * 60 + mm * 60 + ss;
        cin >> state;
        if (state == "in")
            temp.state = 1;
        else
            temp.state = 0;

        total[i] = temp;

    }

    sort(total.begin(), total.end(), cmp1);//按各个车牌号的时间分类排序

    map<string, int> mmap;

    for (int i = 0; i < total.size() - 1; ++i) {
        if (total[i].plate_number == total[i + 1].plate_number && total[i].state == 1 && total[i + 1].state == 0) {
            car.push_back(total[i]);
            car.push_back(total[i + 1]);
            mmap[total[i].plate_number] += total[i + 1].time - total[i].time;
        }
        if (mmap[total[i].plate_number] > max_time) {
            max_time = mmap[total[i].plate_number];
        }
    }//提取有效数据存储mmap，并计算最长park时间

    sort(car.begin(), car.end(), cmp2);//按全部的时间点排序

    int index = 0, cnt = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 60 * 60 + mm * 60 + ss;
        for (int j = index; j < car.size(); ++j) {
            if (car[j].time > time) {
                index = j;
                break;
            }
            if (car[j].state == 1)
                cnt++;
            else
                cnt--;
        }
        printf("%d\n", cnt);//计算某时间点之间的parking车辆个数
    }

    for (auto it:mmap) {
        if (it.second == max_time)
            cout << it.first << " ";//输出parktime最长的车牌号
    }

    hh = max_time / 3600;
    mm = max_time % 3600 / 60;
    ss = max_time % 60;
    printf("%02d:%02d:%02d", hh, mm, ss);


    return 0;
}
