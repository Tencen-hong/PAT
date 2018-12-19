#include <iostream>
#include <vector>
#include <search.h>

using namespace std;
vector<int> pre, in, post;
bool flag = false;

void postOrder(int L1, int R1, int L2, int R2) {
    if (L2 > R2 || L1 > R1 || flag)
        return;
    int root = L2;
    while (pre[L1] != in[root])
        root++;
    postOrder(L1 + 1, root - L2 + L1, L2, root - 1);
    postOrder(root - L2 + L1 + 1, R1, root + 1, R2);

    // post.push_back(in[root]);
    if (!flag) {
        cout << in[root];
        flag = true;
    }

}

int main() {

    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    postOrder(0, n - 1, 0, n - 1);

    //  cout << post[0] << endl;

    return 0;
}
