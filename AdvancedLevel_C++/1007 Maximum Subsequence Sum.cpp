#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int tmp = 0, tmpindex = 0, sum = -1, start = 0, end = n - 1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        tmp += v[i];
        if (tmp < 0) {
            tmp = 0;
            tmpindex = i + 1;
            continue;
        } else if (tmp > sum) {
            sum = tmp;
            start = tmpindex;
            end = i;
        }
    }
    if (sum < 0)
        sum = 0;
    printf("%d %d %d", sum, v[start], v[end]);

    return 0;
}

