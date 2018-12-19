#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp1(char a, char b) {
    return a > b;
}

int main() {
    string s;
    cin >> s;
    s.insert(0, 4 - s.size(), '0');//不足4位的时候补0
    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), cmp1);
        sort(b.begin(), b.end());
        int res = stoi(a) - stoi(b);
        s = to_string(res);
        s.insert(0, 4 - s.size(), '0');
        cout << a << " - " << b << " = " << s << endl;
    } while (s != "6174" && s != "0000");

    return 0;
}
