#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M;
map<int, int> pos;
vector<int> in, pre;

void lca(int inL, int inR, int preRoot, int a, int b) {
    if (inL > inR)
        return;
    int inRoot = pos[pre[preRoot]], pos_a = pos[a], pos_b = pos[b];
    if (pos_a < inRoot && pos_b < inRoot)
        lca(inL, inRoot - 1, preRoot + 1, a, b);
    else if ((pos_a < inRoot && pos_b > inRoot) || (pos_a > inRoot && pos_b < inRoot))
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    else if (pos_a > inRoot && pos_b > inRoot)
        lca(inRoot + 1, inR, preRoot + 1 + (inRoot - inL), a, b);
    else if (inRoot == pos_a)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (inRoot == pos_b)
        printf("%d is an ancestor of %d.\n", b, a);
}

int main() {
    cin >> M >> N;
    in.resize(N + 1);
    pre.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    for (int i = 1; i <= N; ++i) {
        cin >> pre[i];
    }

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else
            lca(1, N, 1, a, b);
    }
    return 0;
}
