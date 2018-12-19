#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define inf 99999

int main() {
    int N, M;
    cin >> N >> M;
    int e[N + 1][N + 1];
    fill(e[0], e[0] + (N + 1) * (N + 1), inf);
    int a, b, dist;
    for (int i = 1; i <= M; ++i) {
        cin >> a >> b >> dist;
        e[a][b] = e[b][a] = dist;
    }//end  input
    int K;
    cin >> K;
    vector<int> total_dist(K, 0);//总距离
    int min_index = 0, min_dist = inf;//最小距离
    for (int i = 0; i < K; ++i) {
        int n;
        cin >> n;
        vector<int> list(n);
        for (int j = 0; j < n; ++j) {
            cin >> list[j];
        }//
        bool visit[N + 1];
        fill(visit, visit + N + 1, false);
        visit[list[0]] = true;
        bool NA = false;
        for (int j = 0; j < n - 1; ++j) {
            //若相邻2个城市之间有路，则累加距离并标记已访问，若无路则标记不可达NA
            if (e[list[j]][list[j + 1]] < inf) {
                total_dist[i] += e[list[j]][list[j + 1]];
                visit[list[j + 1]] = true;
            } else {
                NA = true;
                break;
            }
        }

        bool flag = true;
        //是否访问了所有的城市
        for (int k = 1; k <= N; ++k) {
            if (visit[k] == false)
                flag = false;
        }
        if (flag) {
            //访问的城市数量为N+1，且回到起点 ，则是简单环
            if (N + 1 == n && list[0] == list[n - 1]) {
                printf("Path %d: %d (TS simple cycle)\n", i + 1, total_dist[i]);
                if (total_dist[i] < min_dist) {
                    min_dist = total_dist[i];
                    min_index = i + 1;
                }
            } else if (list[0] == list[n - 1]) {//访问城市数量过多，普通环
                printf("Path %d: %d (TS cycle)\n", i + 1, total_dist[i]);
                if (total_dist[i] < min_dist) {
                    min_dist = total_dist[i];
                    min_index = i + 1;
                }
            } else {//没有回到起点，非环
                printf("Path %d: %d (Not a TS cycle)\n", i + 1, total_dist[i]);
            }
            continue;
        }
        if (NA)//不可达的环
            printf("Path %d: NA (Not a TS cycle)\n", i + 1);
        else//没有访问所有的城市也不是环
            printf("Path %d: %d (Not a TS cycle)\n", i + 1, total_dist[i]);
    }
    sort(total_dist.begin(), total_dist.end());
    printf("Shortest Dist(%d) = %d", min_index, min_dist);

    return 0;
}
