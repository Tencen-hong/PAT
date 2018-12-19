#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
vector<int> temp;
set<int> s;
bool visit[10010] = {false};

void dfs(int node, int height) {
    if (height > maxheight) {
        maxheight = height;
        temp.clear();
        temp.push_back(node);
    } else if (height == maxheight) {
        temp.push_back(node);
    }
    visit[node] = true;
    for (int i = 0; i < v[node].size(); ++i) {
        if (visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}

int main() {
    cin >> n;
    v.resize(n + 1);
    int a, b, s1 = 0, cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }//#
    for (int i = 1; i <= n; ++i) {
        if (visit[i] == false) {
            dfs(i, 1);
            if (i == 1) {
                if (temp.size() != 0)
                    s1 = temp[0];
                for (int j = 0; j < temp.size(); ++j) {
                    s.insert(temp[j]);
                }//temp中存放距离当前节点最远的节点
            }
            cnt++; //统计连通分量数量
        }
    }
    if (cnt >= 2) {//不知一个连通分量说明不是连通图，输出连通分量
        printf("Error: %d components", cnt);
    } else {//说明是连通图，那么从图中任意节点出发，距离最远的点即是最长路径的一端
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);//从这一端出发，找寻另一端
        for (int i = 0; i < temp.size(); ++i) {
            s.insert(temp[i]);
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            printf("%d\n", *it);
        }
    }
    
    return 0;
}
