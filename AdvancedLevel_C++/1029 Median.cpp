#include <iostream>
#include <vector>

using namespace std;

int main() {

    int m, n, p = 0, temp;
    scanf("%d", &m);
    vector<int> v1(m);

    for (int i = 0; i < m; i++)
        scanf("%d", &v1[i]);

    scanf("%d", &n);

    int mid = (m + n - 1) / 2;
    int count = 0;
    int ans = v1[0];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);

        if (count > mid)
            continue;

        while (p < m) {
            if (count > mid)
                break;
            if (v1[p] < temp) {
                ans = v1[p];
                p++;
                count++;
            } else if (temp < v1[p]) {
                ans = temp;
                count++;
                break;
            } else if (v1[p] == temp) {
                ans = v1[p];
                p++;
                count++;
            }
        }
        if (p >= m) {
            if (count > mid)
                continue;
            ans = temp;

            count++;
        }
    }

    while (p < m) {
        if (count > mid)
            break;
        ans = v1[p];
        p++;
        count++;
    }

    printf("%d", ans);

    return 0;
}
