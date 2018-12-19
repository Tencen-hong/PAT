#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> post, in, level(100000, -1);

void pre(int root, int start, int end, int index) {
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != post[root])
        i++;
    level[index] = post[root];
    pre(root - (end - i + 1), start, i - 1, 2 * index);//处理左子树
    pre(root - 1, i + 1, end, 2 * index + 1);//处理右子树
}

int main() {

    int n, cnt = 0;
    cin >> n;
    post.resize(n);
    in.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }

    pre(n - 1, 0, n - 1, 1);

    for (int i = 0; i < level.size(); ++i) {
        if (level[i] != -1) {
            if (cnt != 0)
                printf(" ");
            printf("%d", level[i]);
            cnt++;
        }
        if (cnt == n)break;
    }

    return 0;
}
