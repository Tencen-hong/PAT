
#include <iostream>
#include <algorithm>


using namespace std;

string s;

void add(string t) {
    int len = s.size(), carry = 0;
    for (int i = len - 1; i >= 0; --i) {
        s[i] = (s[i] - '0') + (t[i] - '0') + carry + '0';
        carry = 0;
        if (s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if (carry == 1)
        s = '1' + s;
}

int main() {
    int cnt, i;
    cin >> s >> cnt;
    for (i = 0; i <= cnt; ++i) {
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s || i == cnt) break;
        add(t);
    }

    cout << s << endl << i;
    return 0;
}
