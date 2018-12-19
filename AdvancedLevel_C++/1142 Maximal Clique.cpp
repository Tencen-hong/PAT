#include <iostream>
#include <vector>

using namespace std;

int e[210][210];

int main() {
    int nv, ne, a, b;
    cin >> nv >> ne;
    for (int i = 0; i < ne; ++i) {
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    int m, k;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        vector<int> v(k);
        int book[210] = {0}, isclique = 1, ismaximal = 1;
        for (int j = 0; j < k; ++j) {
            cin >> v[j];
            book[v[j]] = 1;
        }
        for (int j = 0; j < k; ++j) {
            if (isclique == 0)
                break;
            for (int l = j + 1; l < k; ++l) {
                if (e[v[j]][v[l]] == 0) {//Clique要求所有节点两两相连
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0)
            continue;
        for (int j = 1; j <= nv; ++j) {
            if (book[j] == 0) {
                for (int l = 0; l < k; ++l) {
                    if (e[v[l]][j] == 0)break;//是否能增加一个节点使得和之前所有节点都相通
                    if (l == k - 1)
                        ismaximal = 0;
                }
            }
            if (ismaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (ismaximal == 1)
            printf("Yes\n");
    }

    return 0;
}
