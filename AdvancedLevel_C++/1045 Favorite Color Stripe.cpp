
#include <iostream>
#include <vector>

using namespace std;
int book[201], a[10001], dp[10001];

//book[i]=j表示颜色i的下标为j，   a为剔除不喜欢的颜色后的颜色下标数组,  dp[i]为i位置之前的按序的颜色长度
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &x);
        if (book[x] >= 1)
            a[num++] = book[x];
    }
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] >= a[j])//当全部用颜色下标表示时，所求即是输入颜色下标的最大非连续递增长度
                dp[i] = dp[j] + 1;//以i位置结尾的最大非连续递增序列长度
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
