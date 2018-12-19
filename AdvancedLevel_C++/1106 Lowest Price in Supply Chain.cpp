#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;
double p, r;
double res_p = 9999999;
int res_s = 0;
vector<vector<int>> arr;

void dfs(int root, int depth) {
    if (arr[root].empty()) {
        double temp_res = p * pow(1 + r / 100, depth);
        if (temp_res < res_p) {
            res_p = temp_res;
            res_s = 1;
        } else if (temp_res == res_p)
            res_s++;
    }

    for (int i : arr[root]) {
        dfs(i, depth + 1);
    }
}

int main() {
    cin >> n >> p >> r;
    arr.resize(n);
    int tmpsize;

    for (int i = 0; i < n; ++i) {
        cin >> tmpsize;
        if (tmpsize == 0)
            continue;
        arr[i].resize(tmpsize);
        for (int j = 0; j < tmpsize; ++j) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    printf("%.4f %d", res_p, res_s);

    return 0;
}
