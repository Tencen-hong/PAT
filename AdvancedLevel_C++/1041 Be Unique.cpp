#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> v;
    int count[10010] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
        count[tmp]++;
    }
    string res = "None";
    for (int i = 0; i < n; ++i) {
        if (count[v[i]] == 1) {
            cout << v[i];
            return 0;
        }
    }
    cout << res;
    
    return 0;
}
