#include <iostream>
#include <vector>

using namespace std;

bool isMirror;
vector<int> pre, post;

void getpost(int root, int tail) {
    if (root > tail) return;
    int i = root + 1, j = tail;
    if (!isMirror) {
        while (i <= tail && pre[root] > pre[i])i++;
        while (j > root && pre[root] <= pre[j])j--;
    } else {
        while (i <= tail && pre[root] <= pre[i])i++;
        while (j > root && pre[root] > pre[j])j--;
    }
    if (i - j != 1)return;//当子树是bst时，i-j正好=1,当子树不是bst时，post就缺少push_back
    getpost(root + 1, j);//左
    getpost(i, tail);//右
    post.push_back(pre[root]);//根
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    getpost(0, n - 1);
    if (post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n) {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; ++i) {
            printf(" %d", post[i]);
        }
    } else {
        printf("NO");
    }

    return 0;
}
