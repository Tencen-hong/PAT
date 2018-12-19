#include <iostream>

using namespace std;

#include <vector>

#define SIZE 510
#define inf 999999999
int dis[SIZE], Time[SIZE], e[SIZE][SIZE], w[SIZE][SIZE];
int dispre[SIZE], weight[SIZE];
bool visit[SIZE];
int st, fin, minnode = inf;
vector<int> dispath, temppath, Timepath, Timepre[SIZE];

void dfsdispath(int v) {
    dispath.push_back(v);
    if (v == st) return;
    dfsdispath(dispre[v]);
}

void dfsTimepath(int v) {
    temppath.push_back(v);
    if (v == st) {
        if (temppath.size() < minnode) {
            minnode = temppath.size();
            Timepath = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < Timepre[v].size(); ++i) {
        dfsTimepath(Timepre[v][i]);
    }
    temppath.pop_back();
}

int main() {
    fill(dis, dis + SIZE, inf);
    fill(weight, weight + SIZE, inf);
    fill(Time, Time + SIZE, inf);
    fill(e[0], e[0] + SIZE * SIZE, inf);
    fill(w[0], w[0] + SIZE * SIZE, inf);

    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if (flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }

    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for (int i = 0; i < n; ++i) {
        dispre[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (visit[j] == false && minn > dis[j]) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)break;
        visit[u] = true;
        for (int v = 0; v < n; ++v) {
            if (visit[v] == false && e[u][v] != inf) {
                if (e[u][v] + dis[u] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if (e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }

    dfsdispath(fin);

    Time[st] = 0;
    fill(visit, visit + SIZE, false);
    for (int i = 0; i < n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if (u == -1)break;
        visit[u] = true;
        for (int v = 0; v < n; ++v) {
            if (visit[v] == false && w[u][v] != inf) {
                if (w[u][v] + Time[u] < Time[v]) {
                    Time[v] = Time[u] + w[u][v];
                    Timepre[v].clear();
                    Timepre[v].push_back(u);
                } else if (w[u][v] + Time[u] == Time[v]) {
                    Timepre[v].push_back(u);
                }
            }
        }
    }

    dfsTimepath(fin);

    printf("Distance = %d", dis[fin]);
    if (dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for (int i = dispath.size() - 1; i >= 0; --i) {
            printf("%d", dispath[i]);
            if (i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for (int i = Timepath.size() - 1; i >= 0; --i) {
        printf("%d", Timepath[i]);
        if (i != 0) printf(" -> ");
    }


    return 0;
}
