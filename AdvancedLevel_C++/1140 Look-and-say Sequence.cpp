#include <iostream>

using namespace std;

int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; ++cnt) {
        string t;
        for (int i = 0; i < s.size(); i = j) {
            for (j = i; j < s.size() && s[i] == s[j]; ++j)
                ;
            t += to_string((s[i] - '0') * 10 + j - i);
        }
        s = t;
    }
    cout << s << endl;
    return 0;
}
