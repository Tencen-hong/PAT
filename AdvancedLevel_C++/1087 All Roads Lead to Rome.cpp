#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
#define inf 999999999
#define SIZE 210
int n, k;
vector<int> weight, pre[SIZE], temppath, path;
map<string, int> city_2_id;
map<int, string> id_2_city;
int e[SIZE][SIZE], dist[SIZE];
int maxvalue, cntpath = 0;
double maxavg;

void dfs(int v) {
    temppath.push_back(v);
    if (v == 0) {
        int value = 0;
        for (int i = 0; i < temppath.size(); ++i) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if (value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if (value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for (int i = 0; i < pre[v].size(); ++i) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}


int main() {
    string temp;
    cin >> n >> k >> temp;
    city_2_id[temp] = 0;
    id_2_city[0] = temp;
    weight.resize(n);
    weight[0] = 0;

    fill(e[0], e[0] + SIZE * SIZE, inf);
    fill(dist, dist + SIZE, inf);

    int tmp_happy;
    for (int i = 1; i < n; ++i) {
        cin >> temp >> tmp_happy;
        id_2_city[i] = temp;
        city_2_id[temp] = i;
        weight[i] = tmp_happy;
    }

    string city1, city2;
    int cost;
    for (int i = 0; i < k; ++i) {
        cin >> city1 >> city2 >> cost;
        int a = city_2_id[city1];
        int b = city_2_id[city2];
        e[a][b] = e[b][a] = cost;
    }

    bool visit[SIZE] = {false};

    dist[0] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (!visit[j] && dist[j] < minn) {
                u = j;
                minn = dist[j];
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visit[v] && e[u][v] != inf) {
                if (dist[u] + e[u][v] < dist[v]) {
                    dist[v] = dist[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dist[v] == dist[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = city_2_id["ROM"];
    dfs(rom);

    printf("%d %d %d %d\n", cntpath, dist[rom], maxvalue, (int) maxavg);
    for (int i = path.size() - 1; i >= 1; --i) {
        cout << id_2_city[path[i]] << "->";
    }
    cout << "ROM";


    return 0;
}
