#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    string name, id;
    int grade;
};

bool cmp1(node a, node b) {
    return a.grade > b.grade;
}

bool cmp2(node a, node b) {
    return a.grade < b.grade;
}

vector<node> m, f;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        node tmpstu;
        string gender;
        cin >> tmpstu.name >> gender >> tmpstu.id >> tmpstu.grade;
        if (gender == "M")
            m.push_back(tmpstu);
        if (gender == "F")
            f.push_back(tmpstu);
    }
    sort(f.begin(), f.end(), cmp1);
    sort(m.begin(), m.end(), cmp2);
    if (f.empty())
        printf("Absent\n");
    else
        cout << f[0].name << " " << f[0].id << endl;
    if (m.empty())
        printf("Absent\n");
    else
        cout << m[0].name << " " << m[0].id << endl;
    if (f.empty() || m.empty())
        printf("NA");
    else {
        int diff = abs(f[0].grade - m[0].grade);
        cout << diff;
    }

    return 0;
}
