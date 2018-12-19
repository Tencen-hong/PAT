#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct node {
    double inventory;
    double prices;
    double unit;
};

bool cmp1(node a, node b) {
    return a.unit < b.unit;
}

int main() {

    double n, d, sum = 0;
    double ans = 0;

    scanf("%lf %lf", &n, &d);
    vector<node> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &v[i].inventory);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &v[i].prices);
        v[i].unit = v[i].inventory / v[i].prices;
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < v.size(); ++i) {
        if (sum + v[i].inventory <= d) {
            sum += v[i].inventory;
            ans += v[i].prices;
        } else {
            ans += v[i].prices * ((d - sum) / v[i].inventory);
            break;
        }
    }
    printf("%.2lf", ans);

    return 0;
}
