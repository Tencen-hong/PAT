#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    map<char, int> m2;
    bool visit[130] = {false};
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] >= 'a' && s2[i] <= 'z')
            s2[i] = s2[i] + 'A' - 'a';//改大写
        m2[s2[i]]++;
    }
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] >= 'a' && s1[i] <= 'z')
            s1[i] = s1[i] + 'A' - 'a';
        if (m2.find(s1[i]) == m2.end()) {//没找到即为res
            if (!visit[s1[i]]) {//每种res只打印一次
                cout << s1[i];
                visit[s1[i]] = true;
            }
        }
    }

    return 0;
}
