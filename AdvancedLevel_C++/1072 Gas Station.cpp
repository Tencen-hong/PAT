#include <iostream>

#define inf 9999999
#define size 1020

using namespace std;

int main() {
    int N, M, K, DS;//houses;candidate locations;roads;maximum service range
    int e[size][size];
    bool visit[size];
    int dist[size];
    fill(e[0], e[0] + size * size, inf);

    scanf("%d %d %d %d", &N, &M, &K, &DS);
    for (int i = 0; i < K; ++i) {
        string s, t;
        int tmpdist;
        int a, b;
        cin >> s >> t >> tmpdist;
        if (s[0] == 'G') {
            s = s.substr(1);
            a = N + stoi(s);//gas staion 的id = gasid + N
        } else
            a = stoi(s);
        if (t[0] == 'G') {
            t = t.substr(1);
            b = N + stoi(t);
        } else
            b = stoi(t);
        e[a][b] = e[b][a] = tmpdist;
    }//#

    int ansid = -1;
    double ansaverage = inf, ansdist = -1;

    for (int index = N + 1; index <= N + M; ++index) {
        double mindist = inf;
        double average = 0.0;

        fill(visit, visit + size, false);
        fill(dist, dist + size, inf);

        dist[index] = 0;
        for (int i = 0; i < N + M; ++i) {

            int u = -1, minn = inf;
            for (int j = 1; j <= N + M; ++j) {
                if (!visit[j] && dist[j] < minn) {
                    u = j;
                    minn = dist[j];
                }
            }
            if (u == -1)break;
            visit[u] = true;
            for (int v = 1; v <= N + M; ++v) {
                if (!visit[v] && dist[u] + e[u][v] < dist[v]) {
                    dist[v] = dist[u] + e[u][v];
                }
            }

        }//求每个gas station 的最短路径dist[]

        for (int i = 1; i <= N; ++i) {
            if (dist[i] > DS) {
                mindist = -1;
                break;
            }//超过服务范围，放弃这个gas station
            if (dist[i] < mindist)
                mindist = dist[i];//找距离house 最短的路径
            average += 1.0 * dist[i];//距离总和
        }

        if (mindist == -1)
            continue;//超过服务范围，放弃这个gas station

        average = average / N;//距离平均值

        if (mindist > ansdist) {//记录 候选gas station 中最小距离 最大的那个gas station
            ansdist = mindist;
            ansid = index;
            ansaverage = average;
        } else if (mindist == ansdist && average < ansaverage) {//如果最小距离相等，记录平均值最小的那个
            ansid = index;
            ansaverage = average;
        }

    }


    if (ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - N, ansdist, ansaverage);//还原gas station id

    return 0;
}
