#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    string ans;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        int len = s.length();
        reverse(s.begin(), s.end());
        if (i == 0) {
            ans = s;
            continue;
        } else {
            int len_ans = ans.length();
            int minlen = min(len, len_ans);
            for (int j = 0; j < minlen; ++j) {
                if (ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0)ans = "nai";
    cout << ans;

    return 0;
}
