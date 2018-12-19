#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        m[t]++;
    }
    int num = 0;
    while (++num) {
        if (m[num] == 0)
            break;
    }
    cout << num;
    return 0;
}
