#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    int a, b;
};

bool cmp1(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<int> v[10000];//同性朋友
    map<int, bool> arr;//异性朋友
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {
            v[abs(stoi(b))].push_back(abs(stoi(a)));
            v[abs(stoi(a))].push_back(abs(stoi(b)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); ++j) {
            for (int k = 0; k < v[abs(d)].size(); ++k) {
                if (v[abs(c)][j] == abs(d) || v[abs(d)][k] == abs(c))//去掉c和d互为朋友
                    continue;
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]])//c的同性朋友和d的同行朋友 互为异性朋友
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp1);
        printf("%d\n", ans.size());
        for (int j = 0; j < ans.size(); ++j) {
            printf("%04d %04d\n", ans[j].a, ans[j].b);
        }
    }


    return 0;
}
