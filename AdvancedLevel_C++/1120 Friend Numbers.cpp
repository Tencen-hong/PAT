#include <iostream>
#include <map>

using namespace std;

map<int, bool> m;

void f(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    if (m.find(sum) == m.end())
        m[sum] = true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        f(tmp);
    }
    cout << m.size() << endl;
    bool first_p = true;
    for (auto it:m) {
        if (!first_p)
            printf(" %d", it.first);
        else {
            printf("%d", it.first);
            first_p = false;
        }
    }
    return 0;
}
