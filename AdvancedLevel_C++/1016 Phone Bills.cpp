
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct node {
    string name;
    int status, month, time, day, hour, minute;
};

bool cmp(node a, node b) {
    return (a.name != b.name) ? a.name < b.name : a.time < b.time; //不同名字的按ASCII排序，同名的按时间排序
}

double billFromZero(node call, int *rate) {
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;//当前所处小时的费率 + 从月初到当日的费率
    for (int i = 0; i < call.hour; ++i) {
        total += rate[i] * 60; //计算从当日0点到当前小时的费率
    }
    return total / 100.0; //计算实际费用
}//从当月开始到现在的总费用

int main() {
    int rate[25] = {0}, n;
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &rate[i]); //输入费率
        rate[24] += rate[i]; //计算1天的费率
    }
    scanf("%d", &n);
    vector<node> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? 1 : 0;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;//计算从当月开始到现在所经历的 分钟数
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node>> custom;
    for (int i = 1; i < n; ++i) {
        if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
            custom[data[i - 1].name].push_back(data[i - 1]);
            custom[data[i].name].push_back(data[i]);
        }
    }//保存合法数据到map中，保证on 和 off 一一对应
    for (auto it:custom) {
        vector<node> temp = it.second;
        cout << it.first; //输出名字
        printf(" %02d\n", temp[0].month);//输出月份
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);//一次通话的费用
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute,
                   temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}
