#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {

    int k;
    scanf("%d\n", &k);
    string str;
    cin >> str;
    str = str + '#';//便于计算

    set<char> res;
    bool m2[200];
    fill(m2, m2 + 200, true);
    map<char, bool> m1;
    int cnt = 0;
    char key = str[0];
    for (int i = 0; i < str.size(); ++i) {
        if (key == str[i]) {
            cnt++;
        } else {
            if (cnt % k != 0)
                m2[key] = false;//记录未连续达到k次的字符
            key = str[i];
            cnt = 1;
        }
        if (cnt % k == 0) {
            m1[key] = true;//记录连续达到k次的字符
        }
    }

    for (int i = 0; i < str.size() - 1; ++i) {
        if (!m2[str[i]])
            m1[str[i]] = false;//在连续达到k次的字符中，去掉不符合要求的(该字符有一段未达到k次)
    }

    bool printed[200] = {false};
    for (int i = 0; i < str.size() - 1; ++i) {
        if (m1[str[i]] && !printed[str[i]]) {
            cout << str[i];
            printed[str[i]] = true;//每个符合要求的字符 只打印一次
        }
    }
    cout << endl;
    for (int i = 0; i < str.size() - 1; ++i) {
        cout << str[i];
        if (m1[str[i]])
            i = i + k - 1;
    }


    return 0;
}
