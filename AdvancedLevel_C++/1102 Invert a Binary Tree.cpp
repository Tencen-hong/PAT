#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};
vector<pair<int, int>> data;

bool first_print = true;

void CreateTree(node *&p, int key) {
    node *tmp = (node *) malloc(sizeof(node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->val = key;
    p = tmp;
    if (data[p->val].first != -1) {
        CreateTree(p->left, data[p->val].first);
    }
    if (data[p->val].second != -1) {
        CreateTree(p->right, data[p->val].second);
    }
}

void inorder(node *p) {
    if (p != NULL) {
        inorder(p->left);
        if (first_print) {
            printf("%d", p->val);
            first_print = false;
        } else
            printf(" %d", p->val);
        inorder(p->right);
    }
}

void invert(node *&p) {
    if (p != NULL) {
        invert(p->left);
        invert(p->right);
        swap(p->left, p->right);
    }
}

void levelorder(node *p) {
    queue<node *> q;
    q.push(p);
    while (!q.empty()) {
        node *top = q.front();
        q.pop();
        if (first_print) {
            printf("%d", top->val);
            first_print = false;
        } else {
            printf(" %d", top->val);
        }
        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
    }
}

int main() {
    node *root;
    root = (node *) malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;

    int n;
    cin >> n;
    data.resize(n);
    vector<int> count(n, 0);
    char a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        data[i].first = -1;
        if (isdigit(a))
            data[i].first = a - '0';
        data[i].second = -1;
        if (isdigit(b))
            data[i].second = b - '0';
        if (data[i].first != -1)
            count[data[i].first]++;
        if (data[i].second != -1)
            count[data[i].second]++;
    }//读入数据，统计每个孩子节点数字出现的次数

    for (int i = 0; i < n; ++i) {
        if (count[i] == 0) {
            root->val = i;
            break;
        }
    }//出现次数为0的数字即为根节点

    CreateTree(root, root->val);//根据data建立二叉树

    invert(root);//翻转二叉树

    levelorder(root);

    printf("\n");
    first_print = true;
    inorder(root);
    return 0;
}
