#include <iostream>
#include <vector>

using namespace std;
vector<int> pre, arr, post;
struct node {
    int val;
    struct node *left, *right;
};

node *build(node *root, int x) {
    if (root == NULL) {
        root = new node();
        root->val = x;
    } else if (abs(x) <= abs(root->val)) {
        root->left = build(root->left, x);
    } else
        root->right = build(root->right, x);
    return root;
}

void getPost(int root, int end) {
    if (root > end)return;
    int i = root + 1, j = end;
    while (i <= end && pre[root] >= pre[i])i++;
    while (j >= root + 1 && pre[root] <= pre[j])j--;
    if (i != j + 1) return;//输入的是先根遍历，除了根之外的序列被分为两部分，一部是大于跟的右儿子，一部分是小于根的左儿子，并且两者分界线相邻 \
    根据输入给出的序列去 “构建” 一颗二叉搜索树，构建失败时，树的节点数一定小于n . 例:7 2 1 5 11 3 4 14 15
    getPost(root + 1, j);
    getPost(i, end);
    post.push_back(pre[root]);
}

bool judge1(node *root) {
    if (root == NULL)
        return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0)
            return false;
        if (root->right != NULL && root->right->val < 0)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}

int getNum(node *root) {
    if (root == NULL) return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(node *root) {
    if (root == NULL)
        return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if (l != r)
        return false;
    return judge2(root->left) && judge2(root->right);
}

int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n;
        node *root = NULL;
        pre.resize(n);
        arr.resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
            root = build(root, arr[j]);
            pre[j] = abs(arr[j]);
        }
        post.clear();
        getPost(0, n - 1);
        if (post.size() != n || arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
