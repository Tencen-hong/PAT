#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<vector<int>> v(10000);
vector<int> path, temp_path;
map<int, int> line;
int visit[10000], Cnt, minCnt, minTransfer, start, end1;
int n, m, k;

int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); ++i) {
        if (line[a[i - 1] * 10000 + a[i]] != preLine) {
            cnt++;
            preLine = line[a[i - 1] * 10000 + a[i]];
        }
    }
    return cnt;//计算换乘的次数，第一列车不作数=>cnt=-1
}

void dfs(int node, int cnt) {
    if (node == end1 && (cnt < minCnt || minCnt == cnt && transferCnt(temp_path) < minTransfer)) {
        minCnt = cnt;
        minTransfer = transferCnt(temp_path);
        path = temp_path;
    }//距离最短=经过的站最少的||经过站相等时换乘次数最少的
    if (node == end1)
        return;
    for (int i = 0; i < v[node].size(); ++i) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            temp_path.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);//下一个站cnt+1
            visit[v[node][i]] = 0;
            temp_path.pop_back();
        }
    }
}

int main() {
    cin >> n;
    int pre, temp;
    for (int i = 0; i < n; ++i) {
        cin >> m >> pre;
        for (int j = 1; j < m; ++j) {
            cin >> temp;
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;//line存储相邻2个站之间的地铁车号
            pre = temp;
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> start >> end1;
        minCnt = 999999, minTransfer = 999999;
        temp_path.clear();
        temp_path.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;

        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); ++j) {
            if (line[path[j - 1] * 10000 + path[j]] != preLine) {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
                preLine = line[path[j - 1] * 10000 + path[j]];
                preTransfer = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}
