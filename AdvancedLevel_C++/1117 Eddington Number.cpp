#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp1(int a, int b) {
    return a > b;
}

int main() {

    int n;
    cin >> n;
    int cnt = 0;
    int a[100000];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, cmp1);
    for (int i = 0; i < n; ++i) {
        if (a[i] > i + 1)
            cnt++;
    }
    cout << cnt;

    return 0;
}
