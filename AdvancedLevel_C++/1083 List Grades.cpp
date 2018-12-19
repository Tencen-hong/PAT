#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
    string name;
    string id;
    int grade;
};

bool cmp1(node a, node b) {
    return a.grade > b.grade;
};

int main() {

    vector<node> stu, res;
    int n;
    cin >> n;
    stu.resize(n);

    for (int i = 0; i < n; ++i) {
        node tmp;
        cin >> tmp.name >> tmp.id >> tmp.grade;
        stu[i] = tmp;
    }

    int grade1, grade2;
    scanf("%d %d", &grade1, &grade2);

    for (int i = 0; i < stu.size(); ++i) {
        if (stu[i].grade >= grade1 && stu[i].grade <= grade2)
            res.push_back(stu[i]);
    }

    if (res.empty()) {
        cout << "NONE";
        return 0;
    }

    sort(res.begin(), res.end(), cmp1);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].name << " " << res[i].id << endl;
    }

    return 0;
}
