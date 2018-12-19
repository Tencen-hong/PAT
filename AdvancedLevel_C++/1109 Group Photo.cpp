#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    string name;
    int height;
};

bool cmp(node a, node b) {
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name < b.name;
}


int main() {

    int n, k, m, i, j;
    cin >> n >> k;
    node tmp;
    vector<node> stu(n);
    for (i = 0; i < n; ++i) {
        cin >> stu[i].name >> stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);

    int t = 0, row = k;
    while (row) {
        if (row == k)
            m = n % k + n / k;
        else
            m = n / k;
        vector<string> stemp(m);
        stemp[m / 2] = stu[t].name;
        //central左边
        j = m / 2 - 1;
        for (i = t + 1; i < t + m; i = i + 2) {
            stemp[j--] = stu[i].name;
        }
        //central右边
        j = m / 2 + 1;
        for (i = t + 2; i < t + m; i = i + 2) {
            stemp[j++] = stu[i].name;
        }
        //输出当前组
        cout << stemp[0];
        for (i = 1; i < m; ++i) {
            cout << " " << stemp[i];
        }
        cout << endl;
        t = t + m;
        row--;
    }


    return 0;
}
