#include <iostream>

using namespace std;

int main() {
    string table[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string str;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += (str[i] - '0');
    }
    string tmp = to_string(sum);
    string res = table[tmp[0] - '0'];
    for (int i = 1; i < tmp.size(); ++i) {
        res += ' ' + table[tmp[i] - '0'];
    }
    cout << res;

    return 0;
}

