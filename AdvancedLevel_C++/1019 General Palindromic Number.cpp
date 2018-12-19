#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<long long> convert(long long n, long long b) {
    vector<long long> num;
    while (n > 0) {
        num.push_back((n % b));
        n = n / b;
    }
    reverse(num.begin(), num.end());
    return num;
}

int main() {
    long long n, b;
    cin >> n >> b;
    vector<long long> res;
    res = convert(n, b);
    string flag = "Yes";
    int i, j;
    for (i = 0, j = res.size() - 1; i < j;) {
        if (res[i] == res[j]) {
            i++;
            j--;
        } else {
            flag = "No";
            break;
        }
    }

    cout << flag << endl;
    if (res.size() > 0)
        printf("%d", res[0]);
    else
        printf("0");
    for (int i = 1; i < res.size(); ++i) {
        printf(" %d", res[i]);
    }

    return 0;
}
