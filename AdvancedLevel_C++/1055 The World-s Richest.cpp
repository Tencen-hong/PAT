#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


struct node {
    char name[10];
    int age;
    int worth;

};

bool cmp1(node a, node b) {
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return (strcmp(a.name, b.name) < 0);
}

int main() {
    int n, k, m, Amin, Amax;
    int book[205];
    fill(book, book + 205, 0);
    node tmp;

    scanf("%d %d", &n, &k);
    vector<node> vec, v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", tmp.name, &tmp.age, &tmp.worth);
        v[i] = tmp;
    }

    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < v.size(); ++i) {
        if (book[v[i].age] < 100) {
            vec.push_back(v[i]);
            book[v[i].age]++;
        }
    }//每个年龄最多存储100个人信息

    for (int i = 1; i <= k; ++i) {
        scanf("%d %d %d", &m, &Amin, &Amax);

        printf("Case #%d:\n", i);
        int cnt = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].age >= Amin && vec[i].age <= Amax) {
                printf("%s %d %d\n", vec[i].name, vec[i].age, vec[i].worth);
                cnt++;
                if (cnt == m)
                    break;
            }
        }
        if (cnt == 0)
            printf("None\n");

    }

    return 0;
}
