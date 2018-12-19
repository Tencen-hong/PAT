#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<double> arr;
    cin >> n;
    arr.resize(n + 1);
    double res = 0.0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        res = res + arr[i] * i * (n - i + 1);
    }

    printf("%.2f", res);

    return 0;
}
