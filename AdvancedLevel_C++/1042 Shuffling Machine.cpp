#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, order[55] = {-1}, index = 1;
    vector<string> v(55);
    char c[6] = "SHCDJ";
    for (int i = 0; i < 4; ++i) {
        string str = "";
        for (int j = 1; j <= 13; ++j) {
            str = c[i] + to_string(j);
            v[index++] = str;
        }
    }
    v[index++] = "J1";
    v[index++] = "J2";//构造原始扑克牌

    cin >> k;
    for (int i = 1; i <= 54; ++i) {
        scanf("%d", &order[i]);
    }
    for (int i = 0; i < k; ++i) {
        string tmp;
        vector<string> cop = v;
        for (int j = 1; j <= 54; ++j) {
            tmp = cop[j];
            v[order[j]] = tmp;
        }
    }
    for (int i = 1; i <= 54; ++i) {
        cout << v[i];
        if (i != 54)
            cout << " ";
    }


    return 0;
}
