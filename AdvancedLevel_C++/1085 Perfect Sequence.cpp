#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {

    int n;
    long long p;
    scanf("%d %lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = 0, temp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + res; j < n; ++j) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > res)
                    res = temp;
            } else
                break;
        }
    }
    cout << res;

    return 0;
}
