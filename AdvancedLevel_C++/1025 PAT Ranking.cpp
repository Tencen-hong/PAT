
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct student {
    long long int id;
    int score, location, localrank, finalrank;
};

bool cmp1(student a, student b) {
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
    int n, m;
    scanf("%d", &n);
    vector<student> v;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        vector<student> temp(m);
        for (int j = 0; j < m; ++j) {
            scanf("%lld %d", &temp[j].id, &temp[j].score);
            temp[j].location = i;
        }
        sort(temp.begin(), temp.end(), cmp1);
        temp[0].localrank = 1;
        v.push_back(temp[0]);
        for (int j = 1; j < m; ++j) {
            temp[j].localrank = (temp[j].score == temp[j - 1].score) ? (temp[j - 1].localrank) : (j + 1);
            v.push_back(temp[j]);
        }//本地排名
    }
    sort(v.begin(), v.end(), cmp1);
    v[0].finalrank = 1;
    for (int i = 1; i < v.size(); ++i) {
        v[i].finalrank = (v[i - 1].score == v[i].score) ? (v[i - 1].finalrank) : (i + 1);
    }
    printf("%d\n", v.size());
    for (int j = 0; j < v.size(); ++j) {
        printf("%013lld %d %d %d\n", v[j].id, v[j].finalrank, v[j].location, v[j].localrank);
    }

    return 0;
}
