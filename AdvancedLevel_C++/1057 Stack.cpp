#include <bits/stdc++.h>

using namespace std;
#define lowbit(x) ((x)&(-x))
stack<int> s;

const int maxn = 100010;
int c[maxn];//以树状数组统计前n项和

void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}


void PeekMedian() {//2分查找第i-th大的数
    int left = 1, right = maxn, mid, key;
    key = (s.size() % 2 == 0) ? s.size() / 2 : (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= key)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", right);

}


int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        if (str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if (str[1] == 'o') {
            if (!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }

        } else {
            if (!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }

    return 0;
}
