#include <iostream>
#include <map>

using namespace std;

int main() {

    string s;
    cin >> s;
    int count_t = 0, count_p = 0, result = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'T')
            count_t++;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P')
            count_p++;
        if (s[i] == 'T')
            count_t--;//记录A后面的T的个数
        if (s[i] == 'A')
            result = (result + count_p * count_t) % 1000000007;
    }
    cout << result;
    return 0;
}
