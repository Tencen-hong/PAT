#include <iostream>
#include <vector>

using namespace std;
vector<int> pre, post, in;
bool unique = true;

void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if (preLeft == preRight) {//该树只有一个节点
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight - 1]) i++;//i指向下一个右根节点
        if (i - preLeft > 1)
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);//递归处理左子树
        else
            unique = false;//子树中只有一个节点，无法判定时左孩子还是右孩子
        in.push_back(post[postRight]);//当前右根节点
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);//递归处理右子树
    }
}

int main() {
    int n;
    cin >> n;
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    getIn(0, n - 1, 0, n - 1);
    printf("%s\n%d", unique ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); ++i) {
        printf(" %d", in[i]);
    }
    printf("\n");
    return 0;
}
