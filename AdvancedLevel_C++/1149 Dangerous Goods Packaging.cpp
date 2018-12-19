#include<iostream>
#include<vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int N, M, K;
    vector<pair<int, int>> incompatible;

    cin >> N >> M;

    int a, b, temp;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        incompatible.push_back({a, b});
    }
    for (int i = 0; i < M; ++i) {
        cin >> K;
        set<int> sset;
        for (int j = 0; j < K; ++j) {
            cin >> temp;
            sset.insert(temp);
        }
        bool flag = true;
        for (int j = 0; j < incompatible.size(); ++j) {
            auto search1 = sset.find(incompatible[j].first);
            auto search2 = sset.find(incompatible[j].second);
            if (search1 != sset.end() && search2 != sset.end()) {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
    }
    return 0;
}
