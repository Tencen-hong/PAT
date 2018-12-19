#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {

    string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string c[6] = {"Ge", "Shi", "Bai", "Qian", "Yi", "Wan"};
    int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    vector<string> res;

    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu ";
        n = -n;
    }

    int part[3];
    part[0] = n / J[8];
    part[1] = (n % J[8]) / J[4];
    part[2] = n % J[4];

    bool zero = false;//是否在非零数字前输出合适的ling
    int printCnt = 0;//用于维护单词前没有空格，之后输入的单词都在前面加一个空格。
    for (int i = 0; i < 3; ++i) {
        int temp = part[i];//三个部分，每部分内部的命名规则都一样，都是X千X百X十X
        for (int j = 3; j >= 0; --j) {
            int curPos = 8 - i * 4 + j;//当前数字的位置
            if (curPos >= 9) continue;//最多九位数
            int cur = (temp / J[j]) % 10;//取出当前数字
            if (cur != 0) {
                if (zero) {
                    cout << " ling";
                    zero = false;//只有在当前数不为0时，才决定打印之前的0
                }
                if (j == 0) {
                    if (printCnt++ != 0) cout << ' ';
                    cout << num[cur];
                } else {
                    if (printCnt++ != 0) cout << ' ';
                    cout << num[cur] << ' ' << c[j];
                }
            } else {
                if (!zero && j != 0 && n / J[curPos] >= 10) zero = true;//注意100020这样的情况
            }
        }
        if (i != 2 && part[i] > 0) cout << ' ' << c[i + 4];//处理完每部分之后，最后输出单位，Yi/Wan
    }

    return 0;
}
