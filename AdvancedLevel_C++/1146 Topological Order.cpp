#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool first_print = true;

int main() {
    int n, m, k, a, b;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    vector<int> indegree(1010, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        indegree[b]++;//入度++
        e[a].push_back(b);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> u(n);
        vector<int> indegree_fb = indegree;
        for (int j = 0; j < n; ++j) {
            cin >> u[j];
        }
        for (int j = 0; j < n; ++j) {
            if (indegree_fb[u[j]] != 0) {
                if (first_print) {
                    cout << i;
                    first_print = false;
                } else {
                    cout << " " << i;
                }

                break;
            }
            for (int l = 0; l < e[u[j]].size(); ++l) {
                indegree_fb[e[u[j]][l]]--;//入度--
            }
        }
    }

    return 0;
}
