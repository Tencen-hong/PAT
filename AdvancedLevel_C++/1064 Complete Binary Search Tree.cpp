#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int> in, level;

void levelorder(int start, int end, int index) {
    if (start > end) return;
    int n = end - start + 1;
    int l = log2(n + 1);//除了最后一层的层数,若是满二叉树则最后一层算NULL
    int leave = n - (pow(2, l) - 1);//最后一层的叶子节点数
    int root = start + (pow(2, l - 1) - 1) + min((int) pow(2, l - 1), leave);
    //(pow(2,l-1)-1) 是除了root节点所在层和最后一层外，左子树节点的个数
    //pow(2, l - 1) 是l+1层最多拥有的属于根节点左子树的节点个数
    //min(pow(2, l - 1), leave) 是根节点左子树真正拥有的叶子节点数
    level[index] = in[root];
    levelorder(start, root - 1, 2 * index + 1);
    levelorder(root + 1, end, 2 * index + 2);
}

int main() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    sort(in.begin(), in.end());
    levelorder(0, n - 1, 0);
    printf("%d", level[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", level[i]);
    }


    return 0;
}
