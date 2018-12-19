#include <iostream>
#include <map>

using namespace std;

int main() {

    map<char, int> table, extra;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s2.size(); ++i) {
        table[s2[i]]++;
    }
    for (int i = 0; i < s1.size(); ++i) {
        if (table.find(s1[i]) != table.end() && table[s1[i]] > 0) {
            table[s1[i]]--;
        } else {
            extra[s1[i]]++;
        }
    }

    int cnt = 0, cnt2 = 0;
    for (auto it:table) {
        cnt += it.second;
    }

    if (cnt == 0) {
        for (auto it:extra) {
            cnt2 += it.second;
        }
        cnt += cnt2;
        printf("Yes %d", cnt);
    } else {
        printf("No %d", cnt);
    }


    return 0;
}
