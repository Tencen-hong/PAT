#include <iostream>
#include <algorithm>

using namespace std;

//radix 可以非常大

long long convert(string str, long long radix) {
    long long num = 0;
    for (char i : str) {
        long long tmp = i <= '9' ? i - '0' : i - 'a' + 10;
        num = num * radix + tmp;
    }
    return num;
}

long long find_radix(string str, long long num) {
    char it = *max_element(str.begin(), str.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long high = max(low, num);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(str, mid);
        if (t == num)
            return mid;
        else if (t < 0 || t > num)   //t<0,表示进制过大，转换出的10进制数溢出
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


int main() {
    string n1, n2;
    long long tag, radix, res;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 1)
        res = find_radix(n2, convert(n1, radix));
    else
        res = find_radix(n1, convert(n2, radix));
    if (res != -1)
        cout << res;
    else
        cout << "Impossible";

    return 0;
}
