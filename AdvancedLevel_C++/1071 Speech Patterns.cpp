#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    map<string, int> m;
    string word;
    for (int i = 0; i < str.size(); ++i) {
        str[i] = static_cast<char>(tolower(str[i]));//大小写不敏感，统一设置成小写
        if (str[i] >= 'a' && str[i] <= 'z' || isdigit(str[i])) {
            word += str[i];
        } else {
            if (word != "")
                m[word]++;//统计各单词出现次数
            word = "";
        }
    }
    if (word != "")//单独处理最后一个单词
        m[word]++;
    string res;
    int num = 0;

    for (auto it:m) {
        if (it.second > num) {
            num = it.second;
            res = it.first;
        }
    }

    cout << res << " " << num;


    return 0;
}
