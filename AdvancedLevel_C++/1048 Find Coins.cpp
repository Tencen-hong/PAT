#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    int n, m;
    int value[100010];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value[i]);
    }
    sort(value, value + n);
    int mid, left = 0, right = n - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (value[mid] == m)
            break;
        else if (value[mid] < m)
            left = mid + 1;
        else if (value[mid] > m)
            right = mid - 1;
    }//二分法找到<=m的位置，在下标0到这个位置的范围内寻找结果
    int high = right;
    int i, j;
    for (i = 0, j = high; i < j;) {
        if (value[i] + value[j] == m) {
            printf("%d %d", value[i], value[j]);
            return 0;
        } else if (value[i] + value[j] > m)
            j--;
        else if (value[i] + value[j] < m)
            i++;
    }
    printf("No Solution");

    return 0;
}
