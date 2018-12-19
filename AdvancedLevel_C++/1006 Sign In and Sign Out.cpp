#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int main() {
    int M;
    string unlocked, locked;
    int minn = INT_MAX, maxn = INT_MIN;

    cin >> M;
    for (int i = 0; i < M; ++i) {
        string id;
        cin >> id;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int tmp1 = h1 * 3600 + m1 * 60 + s1;
        int tmp2 = h2 * 3600 + m2 * 60 + s2;
        if (minn > tmp1) {
            minn = tmp1;
            unlocked = id;
        }
        if (maxn < tmp2) {
            maxn = tmp2;
            locked = id;
        }
    }

    cout << unlocked << ' ' << locked;

    return 0;
}

//输入时间转化为总秒数；
