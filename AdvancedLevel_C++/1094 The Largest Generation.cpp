#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> vec;
vector<int> level;

void dfs(int p, int depth) {
    level[p] = depth;
    for (int i = 0; i < vec[p].size(); ++i) {
        dfs(vec[p][i], depth + 1);
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vec.resize(n + 1);
    level.resize(n + 1);
    int parent_id, k, child_id;
    for (int i = 0; i < m; ++i) {
        cin >> parent_id >> k;
        for (int j = 0; j < k; ++j) {
            cin >> child_id;
            vec[parent_id].push_back(child_id);
        }
    }

    dfs(1, 1);//记录各id的level

    int res_number = 0, res_level = 0;
    vector<int> count(n + 1);
    for (int i = 1; i <= n; ++i) {
        count[level[i]]++;//记录各level人数
    }
    for (int i = 1; i <= n; ++i) {
        if (count[i] > res_number) {
            res_number = count[i];
            res_level = i;
        }
    }
    printf("%d %d", res_number, res_level);

    return 0;
}
