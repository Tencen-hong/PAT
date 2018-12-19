#include <iostream>
#include <vector>

using namespace std;

int n, m, a[100010], sum[100010];

int getdis(int left, int right) {
    if (left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }//始终保持left<right
    int dis1 = 0, dis2 = 0;

    dis1 += sum[right - 1] - sum[left - 1];//从left->right的距离


    dis2 += sum[n] - sum[right - 1];//从right->n->left的距离

    dis2 += sum[left - 1] - sum[0];

    return (dis1 < dis2) ? dis1 : dis2;
}


int main() {
    fill(a, a + 100010, -1);
    fill(sum, sum + 100010, 0);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int left, right;
        scanf("%d %d", &left, &right);
        int dis = getdis(left, right);
        printf("%d\n", dis);
    }
    return 0;
}
