
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int N, M, C1, C2;
    int e[510][510] = {INT_MAX};
    int team[510], dist[510], num_path[510], num_team[510];
    bool visit[510];
    //输入数据初始化
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; i++) {
        cin >> team[i];
    }
    fill(e[0], e[0] + 510 * 510, INT_MAX);
    fill(dist, dist + 510, INT_MAX);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    //djs算法初始化
    dist[C1] = 0;
    num_path[C1] = 1;
    num_team[C1] = team[C1];
    //dsj算法
    int min, u;
    for (int i = 0; i < N; i++) {
        min = INT_MAX;
        u = -1;
        for (int j = 0; j < N; j++) {
            if (visit[j] == false && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        //
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v < N; ++v) {
            if (visit[v] == false && e[u][v] != INT_MAX) {
                if (dist[u] + e[u][v] < dist[v]) {  //到目标节点v的最短路径
                    dist[v] = dist[u] + e[u][v];
                    num_path[v] = num_path[u];  
                    num_team[v] = num_team[u] + team[v];
                } else if (dist[u] + e[u][v] == dist[v]) { // 到目标节点v的另一条最短路径
                    num_path[v] += num_path[u];
                    if (num_team[v] < num_team[u] + team[v])
                        num_team[v] = num_team[u] + team[v];
                }
            }
        }
    }
    //
    printf("%d %d", num_path[C2], num_team[C2]);

    return 0;
}
