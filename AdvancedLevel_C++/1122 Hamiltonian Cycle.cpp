#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define N 210

bool e[N][N];
vector<int> querry;
int n, m;
int cnt[N];

bool is_cycle() {
    for (int i = 0; i < n; ++i) {
        cnt[querry[i]]++;
        if (cnt[querry[i]] >= 2) {
            return false;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!e[querry[i]][querry[i + 1]])
            return false;
    }
    return true;
}

int main() {
    fill(e[0], e[0] + N * N, false);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        e[a][b] = e[b][a] = true;
    }

    int k, tmp_size;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> tmp_size;
        querry.resize(tmp_size);
        fill(cnt, cnt + N, 0);
        for (int j = 0; j < tmp_size; ++j) {
            cin >> querry[j];
        }
        if (tmp_size != n + 1 || querry[0] != querry[n]) {
            cout << "NO" << endl;
            continue;
        } else {
            if (is_cycle())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
