#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, s, weight[110], sum = 0;
vector<int> path, tree[110];
vector<vector<int>> res;
queue<int> q;

void dfs(int root) {
    sum += weight[root];//根节点到当前节点的权重
    path.push_back(root);
    if (tree[root].size() == 0)//叶节点
    {
        if (sum == s)
            res.push_back(path);//满足条件加入解集
    }
    for (int i = 0; i < tree[root].size(); ++i) {
        dfs(tree[root][i]);//dfs孩子节点
    }
    path.pop_back();
    sum -= weight[root];//删除当前节点信息，进入兄弟节点或父亲节点
}

bool cmp1(vector<int> a, vector<int> b) {
    return a > b;//按字典降序排列
}

int main() {
    fill(weight, weight + 110, -1);
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; ++i) {
        int id, num;
        scanf("%d %d", &id, &num);
        for (int j = 0; j < num; ++j) {
            int child_id;
            scanf("%d", &child_id);
            tree[id].push_back(child_id);//父亲节点存储孩子节点id
        }
    }//#

    dfs(0);//从根节点开始dfs

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            res[i][j] = weight[res[i][j]];//将节点id转化为接节点权重
        }
    }

    sort(res.begin(), res.end(), cmp1);

    for (int k = 0; k < res.size(); ++k) {
        printf("%d", res[k][0]);
        for (int i = 1; i < res[k].size(); ++i) {
            printf(" %d", res[k][i]);
        }
        printf("\n");
    }

    return 0;
}
