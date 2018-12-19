#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> initial, partially;

void DownAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && partially[j] < partially[j + 1])
            j = j + 1;
        if (partially[i] < partially[j]) {
            swap(partially[i], partially[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    initial.resize(n + 1);
    partially.resize(n + 1);

    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &initial[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &partially[i]);
    }

    int p = 2;
    while (p <= n && partially[p - 1] <= partially[p]) {
        p++;
    }
    int index = p;
    while (p <= n && partially[p] == initial[p])
        p++;

    if (p != n + 1)
        flag = false;

    if (flag) {
        printf("Insertion Sort\n");
        sort(partially.begin() + 1, partially.begin() + index + 1);
        printf("%d", partially[1]);
        for (int j = 2; j <= n; ++j) {
            printf(" %d", partially[j]);
        }
    } else {
        printf("Heap Sort\n");
        p = n;
        while (p >= 2 && partially[p] >= partially[p - 1])
            p--;
        swap(partially[1], partially[p]);
        DownAdjust(1, p - 1);
        printf("%d", partially[1]);
        for (int j = 2; j <= n; ++j) {
            printf(" %d", partially[j]);
        }
    }


    return 0;
}
