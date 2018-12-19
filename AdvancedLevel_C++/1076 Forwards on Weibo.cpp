#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int id, layer;
};

int N, L, M, K;
vector<vector<int>> v;

int bfs(node tnode) {
    bool inq[1010] = {false};
    queue<node> q;
    q.push(tnode);
    inq[tnode.id] = true;
    int cnt = 0;
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        int topid = top.id;
        for (int i = 0; i < v[topid].size(); ++i) {
            int nextid = v[topid][i];
            if (!inq[nextid] && top.layer < L) {
                node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &N, &L);
    v.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &M);
        for (int j = 0; j < M; ++j) {
            int temp;
            scanf("%d", &temp);
            v[temp].push_back(i);
        }
    }
    scanf("%d", &K);
    int tid;
    for (int i = 0; i < K; ++i) {
        scanf("%d", &tid);
        node tnode = {tid, 0};
        printf("%d\n", bfs(tnode));
    }

    return 0;
}
