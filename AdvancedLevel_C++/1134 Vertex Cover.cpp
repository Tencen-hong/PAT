#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int size, cnt = 0, temp;
        cin >> size;
        map<int, int> mmap;
        for (int j = 0; j < size; ++j) {
            cin >> temp;
            for (int l = 0; l < v[temp].size(); ++l) {
                if (mmap.find(v[temp][l]) != mmap.end())
                    continue;
                cnt++;
            }
            mmap[temp]++;
        }
        if (cnt == m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
