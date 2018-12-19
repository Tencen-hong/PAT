#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int ID_Number, Virtue_Grade, Talent_Grade;
    int total;
};

bool cmp1(node a, node b) {
    if (a.total != b.total)
        return a.total > b.total;
    else {
        if (a.Virtue_Grade != b.Virtue_Grade)
            return a.Virtue_Grade > b.Virtue_Grade;
        else {
            return a.ID_Number < b.ID_Number;
        }
    }
}


int main() {
    int N, L, H;
    int M = 0;
    vector<node> sage, nobleman, fool, small;
    scanf("%d %d %d", &N, &L, &H);
    for (int i = 0; i < N; ++i) {
        node tmp;
        scanf("%d %d %d", &tmp.ID_Number, &tmp.Virtue_Grade, &tmp.Talent_Grade);
        if (tmp.Talent_Grade < L || tmp.Virtue_Grade < L)
            continue;
        tmp.total = tmp.Virtue_Grade + tmp.Talent_Grade;
        M++;
        if (tmp.Virtue_Grade >= H && tmp.Talent_Grade >= H) {
            sage.push_back(tmp);
            continue;
        }
        if (tmp.Talent_Grade < H && tmp.Virtue_Grade >= H) {
            nobleman.push_back(tmp);
            continue;
        }
        if (tmp.Virtue_Grade >= tmp.Talent_Grade) {
            fool.push_back(tmp);
            continue;
        }
        small.push_back(tmp);
    }
    sort(sage.begin(), sage.end(), cmp1);
    sort(nobleman.begin(), nobleman.end(), cmp1);
    sort(fool.begin(), fool.end(), cmp1);
    sort(small.begin(), small.end(), cmp1);
    printf("%d\n", M);
    for (int i = 0; i < sage.size(); i++) {
        printf("%08d %d %d\n", sage[i].ID_Number, sage[i].Virtue_Grade, sage[i].Talent_Grade);
    }
    for (int i = 0; i < nobleman.size(); i++) {
        printf("%08d %d %d\n", nobleman[i].ID_Number, nobleman[i].Virtue_Grade, nobleman[i].Talent_Grade);
    }
    for (int i = 0; i < fool.size(); i++) {
        printf("%08d %d %d\n", fool[i].ID_Number, fool[i].Virtue_Grade, fool[i].Talent_Grade);
    }
    for (int i = 0; i < small.size(); i++) {
        printf("%08d %d %d\n", small[i].ID_Number, small[i].Virtue_Grade, small[i].Talent_Grade);
    }
    return 0;
}
