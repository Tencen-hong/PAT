#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int val, level;
    struct node *left, *right;
};
vector<int> in, post;
int n;

void CreateBtree(node *&tree, int L1, int R1, int L2, int R2) {
    if (L1 > R1)
        return;
    if (tree == NULL) {
        tree = new node();
        tree->val = post[R2];
    }
    int index = 0;
    for (index = L1; index <= R1; ++index) {
        if (in[index] == post[R2])
            break;
    }
    CreateBtree(tree->left, L1, index - 1, L2, L2 + (index - L1 - 1));//递归建立左子树
    CreateBtree(tree->right, index + 1, R1, L2 + (index - L1 - 1) + 1, R2 - 1);//递归建立右子树
}

void levelOrder(node *tree) {
    queue<node *> que;
    tree->level = 1;
    que.push(tree);
    vector<node *> v;
    while (!que.empty()) {
        node *temp = que.front();
        que.pop();
        if (!v.empty() && v[0]->level != temp->level) {
            if (v[0]->level == 1)
                printf("%d", v[0]->val);//根节点单独打印
            else {
                if (v[0]->level % 2 == 0) {//分从左至右 和从右至左 打印每一层
                    for (int i = 0; i < v.size(); ++i) {
                        printf(" %d", v[i]->val);
                    }
                } else {
                    for (int i = v.size() - 1; i >= 0; --i) {
                        printf(" %d", v[i]->val);
                    }
                }
            }
            v.clear();
        }
        v.push_back(temp);

        if (temp->left != NULL) {
            temp->left->level = temp->level + 1;
            que.push(temp->left);
        }
        if (temp->right != NULL) {
            temp->right->level = temp->level + 1;
            que.push(temp->right);
        }
    }
    //处理最后一层
    if (v[0]->level == 1)
        printf("%d", v[0]->val);
    else {
        if (v[0]->level % 2 == 0) {
            for (int i = 0; i < v.size(); ++i) {
                printf(" %d", v[i]->val);
            }
        } else {
            for (int i = v.size() - 1; i >= 0; --i) {
                printf(" %d", v[i]->val);
            }
        }
    }
}

int main() {
    cin >> n;
    in.resize(n), post.resize(n);
    node *tree = NULL;

    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    CreateBtree(tree, 0, n - 1, 0, n - 1);//由中序和后序 建立二叉树
    levelOrder(tree);//层次遍历

    return 0;
}
