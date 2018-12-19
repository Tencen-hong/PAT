#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int n;
    cin >> n;
    int maxn = sqrt(n);
    int len = 0, first = 0;
    for (int i = 2; i <= maxn; ++i) {
        int j, temp = 1;
        for (j = i; j <= maxn; ++j) {
            temp = temp * j;
            if (n % temp != 0) {
                break;
            }
        }
        if (len < j - i) {
            len = j - i;
            first = i;
        }
    }

    if (first == 0) cout << 1 << endl << n;
    else {
        cout << len << endl;
        for (int i = 0; i < len; ++i) {
            if (i != 0)
                cout << "*";
            cout << first + i;
        }
    }


    return 0;
}
