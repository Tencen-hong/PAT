#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int p = 1, i, q = 1, exp = 0;
    string s;
    cin >> s;

    if (s[0] == '-')
        p = -1;//底数的正负

    string res = "";
    int n_pos;
    for (i = 1; i < s.size() && s[i] != 'E'; ++i) {
        if (s[i] == '.')
            continue;
        res = res + s[i];//copy底数

    }
    i++;
    if (s[i++] == '-') {
        q = -1;//指数的正负
    }
    for (; i < s.size(); ++i) {
        exp = exp * 10 + (s[i] - '0');//指数int
    }
    if (q == -1) {
        res.insert(res.begin(), exp, '0');//指数为负，前面补0
        res.insert(res.begin() + 1, 1, '.');//第二个位置补小数点
    } else {
        int need = exp - (res.size() - 1);//指数为正，需要补0的个数
        if (need > 0)
            res.insert(res.end(), need, '0');//超过关键字，后面补0
        else if (need < 0)//如果need==0，+1.02E+2的时候不要错误处理成102.了后面是不能带点的。
            res.insert(res.end() + need, 1, '.');//没超过关键字，相应位置加小数点
    }

    if (p == -1)
        res.insert(res.begin(), 1, '-');//负数加-号，正数不用
    cout << res << endl;


    return 0;
}
