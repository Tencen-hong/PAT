#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};

queue<node *> q;
int n;
int k = 0;
vector<pair<int, int>> data;
vector<int> nums;
bool first_print = true;

void CreateTree(node *&p, int index) {
    if (data[index].first == -1 && data[index].second == -1)
        return;
    if (data[index].first != -1) {
        node *tmp = (node *) malloc(sizeof(node));
        tmp->val = data[index].first;
        tmp->left = NULL;
        tmp->right = NULL;
        p->left = tmp;
        CreateTree(p->left, data[index].first);//递归构造左子树
    }
    if (data[index].second != -1) {
        node *tmp = (node *) malloc(sizeof(node));
        tmp->val = data[index].second;
        tmp->left = NULL;
        tmp->right = NULL;
        p->right = tmp;
        CreateTree(p->right, data[index].second);
    }

}

void inorder(node *p) {
    if (p != NULL) {
        inorder(p->left);
        p->val = nums[k++];//用实际值替换序号
        inorder(p->right);
    }
}

void levelOrder(node *p) {
    if (p != NULL)
        q.push(p);
    while (!q.empty()) {
        node *tmp = q.front();
        q.pop();
        if (first_print) {
            cout << tmp->val;
            first_print = false;
        } else
            cout << " " << tmp->val;
        if (tmp->left != NULL)
            q.push(tmp->left);
        if (tmp->right != NULL)
            q.push(tmp->right);
    }

}


int main() {
    node *root;
    root = (node *) malloc(sizeof(node));
    root->val = 0;
    root->left = NULL;
    root->right = NULL;

    cin >> n;
    int a, b;
    data.resize(n);
    nums.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        data[i].first = a;
        data[i].second = b;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }//#

    CreateTree(root, 0);//按所给结构,以序号构造BST

    sort(nums.begin(), nums.end());//所给数据从小到大排序后 即为二叉树的中序遍历

    inorder(root);

    levelOrder(root);//层次遍历


    return 0;
}
