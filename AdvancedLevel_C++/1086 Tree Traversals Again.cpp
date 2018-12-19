#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;
vector<int> value, pre, in, post;

void postorder(int root, int start, int end) {
    if (start > end)return;
    int i = start;
    while (i < end && pre[root] != in[i])i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}

int main() {
    int n;
    char str[5];
    stack<int> s;
    int key = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; ++i) {
        scanf("%s", str);
        if (strlen(str) == 4) {
            int num;
            scanf("%d", &num);
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", value[post[i]]);
    }


    return 0;
}
