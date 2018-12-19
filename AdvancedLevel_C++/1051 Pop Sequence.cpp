#include <iostream>
#include <stack>
#include <vector>

using namespace std;
/***************************
先把输入的序列接收进数组v。
 然后按顺序1~n把数字进栈，每进入一个数字，判断有没有超过最大范围，超过了就break。
 如果没超过，设current = 1，从数组的第一个数字开始，看看是否与栈顶元素相等，while相等就一直弹出栈，不相等就继续按顺序把数字压入栈~~~
 最后根据变量flag的bool值输出yes或者no~~~
******************/
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; ++i) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &v[j]);
        }

        int current = 1;
        for (int j = 1; j <= n; ++j) {
            s.push(j);
            if (s.size() > m)break;
            while (!s.empty() && s.top() == v[current]) {
                s.pop();
                current++;
            }
        }

        if (current == n + 1) flag = true;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
