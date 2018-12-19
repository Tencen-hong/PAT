#include <iostream>
#include <vector>

using namespace std;
int mSize, n, m;

bool isprime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> mSize >> n >> m;
    while (!isprime(mSize))
        mSize++;
    vector<int> v(mSize, 0);
    int key, pos;
    for (int i = 0; i < n; ++i) {
        cin >> key;
        bool flag = false;
        for (int j = 0; j < mSize; ++j) {
            pos = (key + j * j) % mSize;
            if (v[pos] == 0) {
                v[pos] = key;
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("%d cannot be inserted.\n", key);
    }

    int total_cnt = 0;
    for (int i = 0; i < m; ++i) {
        cin >> key;
        int cnt = 1;
        for (int j = 0; j < mSize; ++j) {
            pos = (key + j * j) % mSize;
            if (v[pos] == 0 || v[pos] == key)
                break;
            cnt++;
        }
        total_cnt += cnt;//总查找次数
    }
    printf("%.1lf", (double) total_cnt / m);

    return 0;
}
