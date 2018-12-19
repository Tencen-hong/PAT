#include <iostream>

using namespace std;
const int maxn = 10010;
int fa[maxn] = {0};
bool exist[maxn] = {false};
int n, m, k;

int findFather(int x) {
    int a = x;
    while (x != fa[x])
        x = fa[x];
    while (a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) fa[faA] = faB;
}

int main() {

    int cnt[maxn] = {0};
    cin >> n;
    for (int i = 0; i < maxn; ++i) {
        fa[i] = i;
    }
    int id, temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &k, &id);
        exist[id] = true;
        for (int j = 0; j < k - 1; ++j) {
            scanf("%d", &temp);
            Union(id, temp);
            exist[temp] = true;
        }
    }

    for (int i = 0; i < maxn; ++i) {
        if (exist[i]) {
            int root = findFather(i);
            cnt[root]++;
        }
    }

    int Tree_number = 0, Bird_number = 0;
    for (int i = 0; i < maxn; ++i) {
        if (exist[i] && cnt[i] > 0) {
            Tree_number++;
            Bird_number += cnt[i];
        }
    }
    printf("%d %d\n", Tree_number, Bird_number);

    cin >> m;
    int ida, idb;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &ida, &idb);
        printf("%s\n", (findFather(ida) == findFather(idb)) ? "Yes" : "No");
    }


    return 0;
}
