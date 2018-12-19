#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
char name[40010][5];

bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k, c;
    cin >> n >> k;
    vector<vector<int>> course(n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", name[i], &c);
        int id;
        for (int j = 0; j < c; ++j) {
            scanf("%d", &id);
            course[id].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for (int j = 0; j < course[i].size(); ++j) {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}
