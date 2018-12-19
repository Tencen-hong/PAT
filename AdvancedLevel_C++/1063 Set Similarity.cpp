#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {

    int N, M, K;
    int temp, a, b;
    scanf("%d", &N);
    vector<set<int>> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &M);
        set<int> s;
        for (int j = 0; j < M; ++j) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }

    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b].size();
        for (auto item: v[a]) {
            if (v[b].find(item) == v[b].end()) {
                nt++;
            } else
                nc++;
        }
        double ans = (double) nc / nt * 100;
        printf("%.1f%%\n", ans);
    }


    return 0;
}
