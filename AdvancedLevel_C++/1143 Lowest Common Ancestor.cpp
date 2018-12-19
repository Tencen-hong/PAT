#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    map<int, bool> mp;
    vector<int> pre(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        for (int j = 0; j < n; ++j) {
            a = pre[j];
            if ((a > u && a < v) || (a > v && a < u) || a == u || a == v)break;
        }
        if (!mp[u] && !mp[v])
            printf("ERROR: %d and %d are not found.", u, v);
        else if (!mp[u] || !mp[v])
            printf("ERROR: %d is not found.", !mp[u] ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.", u, v, a);
        printf("\n");
    }
    return 0;
}
