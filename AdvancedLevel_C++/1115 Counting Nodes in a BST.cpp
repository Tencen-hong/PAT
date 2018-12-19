#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    struct node *left, *right;
};

node *build(node *root, int val) {
    if (root == NULL) {
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    } else if (val <= root->val) {
        root->left = build(root->left, val);
    } else {
        root->right = build(root->right, val);
    }
    return root;
}

vector<int> num(1000);
int maxdepth = -1;

void dfs(node *root, int depth) {
    if (root == NULL) {
        maxdepth = max(maxdepth, depth);
        return;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

int main() {
    int n, t;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        root = build(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d", num[maxdepth - 1], num[maxdepth - 2], num[maxdepth - 1] + num[maxdepth - 2]);
    return 0;
}
