#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char maxp(vector<double> v) {
    if (v[0] > v[1] && v[0] > v[2])
        return 'W';
    if (v[1] > v[0] && v[1] > v[2])
        return 'T';
    if (v[2] > v[0] && v[2] > v[1])
        return 'L';
}

int main() {

    vector<vector<double>> vec;
    char res[3];
    double profit = 1.0;
    for (int i = 0; i < 3; ++i) {
        vector<double> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        vec.push_back(tmp);
        res[i] = maxp(tmp);
    }

    for (int j = 0; j < 3; ++j) {
        if (res[j] == 'W')
            profit *= vec[j][0];
        if (res[j] == 'T')
            profit *= vec[j][1];
        if (res[j] == 'L')
            profit *= vec[j][2];
    }
    profit = (profit * 0.65 - 1) * 2;
    cout << res[0] << ' ' << res[1] << ' ' << res[2];
    printf(" %.2f", profit);

    return 0;
}
