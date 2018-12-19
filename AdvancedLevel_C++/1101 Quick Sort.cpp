#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define N 100000

int main() {
    int a[N], b[N];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);
    int v[N], max = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i] && b[i] > max)
            v[cnt++] = b[i];
        if (b[i] > max)
            max = b[i];
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
