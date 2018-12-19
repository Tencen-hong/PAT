#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    string name;
    vector<string> list(m + 1);
    map<string, bool> winner;

    for (int i = 1; i <= m; ++i) {
        cin >> name;
        list[i] = name;
    }


    int cnt = n - 1;
    for (int i = s; i <= m; ++i) {
        if (winner.find(list[i]) != winner.end()) {
            continue;
        } else {
            cnt++;
            if (cnt == n) {
                cout << list[i] << endl;
                winner[list[i]] = true;
                cnt = 0;
            }
        }
    }

    if (winner.empty())
        cout << "Keep going...";

    return 0;
}
