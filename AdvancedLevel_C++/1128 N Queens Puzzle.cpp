#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        vector<int> v(n);
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
            for (int t = 0; t < j; ++t) {
                if (v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t)) {//是否在同一行或在同一对角线
                    flag = false;
                    break;
                }

            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}
