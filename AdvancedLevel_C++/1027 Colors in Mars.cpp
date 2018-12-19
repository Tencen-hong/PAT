#include <iostream>

using namespace std;

string convert(int num, int radix) {
    string res = "00";
    for (int i = 1; i >= 0; --i) {
        int tmp = num % radix;
        res[i] = tmp < 10 ? tmp + '0' : tmp - 10 + 'A';
        num = num / radix;
    }
    return res;
}

int main() {
    int a1, a2, a3, radix = 13;
    cin >> a1 >> a2 >> a3;
    string r = convert(a1, radix);
    string g = convert(a2, radix);
    string b = convert(a3, radix);
    cout << '#' << r << g << b << endl;

    return 0;
}
