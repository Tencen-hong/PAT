

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int hh, mm, ss, p_time, w_time = 0, a_time;
};

bool cmp1(node a, node b) {
    return a.a_time < b.a_time;
}

//时间全部转化为秒
int main() {
    vector<node> cus;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        node tmp;
        scanf("%d:%d:%d %d", &tmp.hh, &tmp.mm, &tmp.ss, &tmp.p_time);
        tmp.a_time = tmp.hh * 3600 + tmp.mm * 60 + tmp.ss;
        if (tmp.a_time > 17 * 60 * 60)//超过17点
            continue;
        if (tmp.p_time > 60)//处理时间超过60分钟
            tmp.p_time = 60;
        tmp.p_time = tmp.p_time * 60;
        cus.push_back(tmp);
    }

    sort(cus.begin(), cus.end(), cmp1);

    vector<int> windows(k, 8 * 60 * 60);
    double sum = 0.0;
    for (int i = 0; i < cus.size(); ++i) {
        int minn = windows[0], minj = 0;
        for (int j = 1; j < k; ++j) {
            if (windows[j] < minn) {
                minn = windows[j];
                minj = j;
            }
        }//选出最先结束的窗口
        if (cus[i].a_time < windows[minj]) { //来早了
            cus[i].w_time = windows[minj] - cus[i].a_time;
            windows[minj] += cus[i].p_time;
        } else {//来迟了
            windows[minj] = cus[i].a_time + cus[i].p_time;
        }
        sum += cus[i].w_time;
    }

    if (cus.size() == 0)
        printf("0.0");
    else
        printf("%.1f", sum / 60.0 / cus.size());
    return 0;
}
