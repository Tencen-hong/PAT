#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string lower[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                      "jly", "aug", "sep", "oct", "nov", "dec"};
    string higher[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                       "hei", "elo", "syy", "lok", "mer", "jou"};
    map<string, int> mlow, mhigh;
    for (int i = 1; i <= 12; ++i) {
        mlow[lower[i]] = i;
        mhigh[higher[i]] = i;
    }

    int n;
    scanf("%d", &n);
    getchar();
    for (int k = 0; k < n; ++k) {
        string ch;
        getline(cin, ch);
        if (isdigit(ch[0])) {
            int temp = stoi(ch);
            if (temp >= 13) {
                int a = temp / 13;
                int b = temp % 13;
                cout << higher[a];
                if (b != 0)
                    cout << " " << lower[b];
                cout << endl;
            } else {
                cout << lower[temp] << endl;
            }
        } else {
            int res;
            string temp;
            if (ch.size() <= 3) {
                temp = ch;
                if (mhigh.find(temp) != mhigh.end()) {
                    res = 13 * mhigh[temp];
                } else if (mlow.find(temp) != mlow.end()) {
                    res = mlow[temp];
                }
            } else {
                temp = ch.substr(0, 3);
                res = 13 * mhigh[temp];
                temp = ch.substr(4, 3);
                res += mlow[temp];
            }
            cout << res << endl;
        }

    }


    return 0;
}
