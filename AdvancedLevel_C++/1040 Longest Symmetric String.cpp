#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    string s, str, tmp;
    getline(cin, s);
    int len = s.size();
    int maxlen = 1;

    for (int L = 2; L <= len; L++) {
        for (int i = 0; i + L <= len; ++i) {
            str = s.substr(i, L);
            tmp = str;
            reverse(tmp.begin(), tmp.end());
            if (tmp == str)
                maxlen = L;
        }
    }


    cout << maxlen;

    return 0;
}






