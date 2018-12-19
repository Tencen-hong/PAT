#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int inf = 99999999;
int cmax, n, sp, m;//单个车站最大容量，车站数量，问题车站，路径数量
int e[510][510], dis[510], weight[510];
int minNeed = inf, minBack = inf;
bool visit[510] = {false};
vector<int> pre[510], path, temppath;

void dfs(int v) {
    temppath.push_back(v);
    if (v == 0) {
        int need = 0, back = 0;//缺少单车数量，多余单车数量
        for (int i = temppath.size() - 1; i >= 0; --i) {
            int id = temppath[i];
            if (weight[id] > 0) {
                back += weight[id];//多余车辆累加
            } else {
                if (back > (0 - weight[id])) {
                    back += weight[id];//多余车辆数>缺少车辆
                } else {
                    need += ((0 - weight[id]) - back);//多余车辆不够，累加缺少车辆
                    back = 0;
                }
            }
        }
        if (need < minNeed) {   //最短路径中 缺少单车数目最小的那条路径
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if (need == minNeed && back < minBack) { //如果还有多条路径， 找多余车辆最少的那条
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); ++i) {
        dfs(pre[v][i]);//从后往前深度遍历
    }
    temppath.pop_back();
}

int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
        weight[i] = weight[i] - cmax / 2;
    }//各个车站相比完美状态差多少
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }//输入路径和权重
    dis[0] = 0;//从0节点开始
    for (int i = 0; i <= n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j <= n; ++j) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }//找到距离刚归并节点最近的节点
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v <= n; ++v) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }//pre收录最短路径v节点的前驱节点u
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for (int i = path.size() - 2; i >= 0; i--) {//反向存储的路径，反向遍历
        printf("->%d", path[i]);
    }
    printf(" %d", minBack);

    return 0;
}
