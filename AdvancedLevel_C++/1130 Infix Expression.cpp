#include <iostream>
#include <vector>

using namespace std;

struct node {
    string val;
    int left, right;
};


int n, root = 1;
vector<node> v;

string dfs(int index) {
    if (index == -1)
        return "";
    if (v[index].right != -1) {
        v[index].val = dfs(v[index].left) + v[index].val + dfs(v[index].right);
        if (index != root)
            v[index].val = '(' + v[index].val + ')';
    }
    return v[index].val;
}

int main() {
    cin >> n;
    v.resize(n + 1);
    vector<bool> book(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].val >> v[i].left >> v[i].right;
        if (v[i].left != -1)
            book[v[i].left] = true;
        if (v[i].right != -1)
            book[v[i].right] = true;
    }
    while (book[root])
        root++;
    cout << dfs(root) << endl;
    return 0;
}
