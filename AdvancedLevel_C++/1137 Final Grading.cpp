#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    string id;
    int opa = -1, gm = -1, gf = -1, g = 0;
};

bool cmp1(node a, node b) {
    if (a.g != b.g)
        return a.g > b.g;
    else
        return a.id < b.id;
}

int main() {
    //vector<node> stu;
    map<string, node> stu;
    int p, m, n;
    cin >> p >> m >> n;
    node temp;
    for (int i = 0; i < p; ++i) {
        cin >> temp.id >> temp.opa;
        if (temp.opa >= 200)
            stu[temp.id] = temp;
    }
    for (int i = 0; i < m; ++i) {
        cin >> temp.id >> temp.gm;
        if (stu.find(temp.id) != stu.end()) {
            stu[temp.id].gm = temp.gm;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp.id >> temp.gf;
        if (stu.find(temp.id) != stu.end()) {
            stu[temp.id].gf = temp.gf;
        }
    }

    vector<node> res;
    for (auto it:stu) {
        if (it.second.gm > it.second.gf)
            it.second.g = (it.second.gm * 0.4 + it.second.gf * 0.6 + 0.5);//+0.5四舍五入
        else
            it.second.g = it.second.gf;
        if (it.second.g >= 60)
            res.push_back(it.second);
    }
    sort(res.begin(), res.end(), cmp1);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].id << " " << res[i].opa << " ";
        cout << res[i].gm << " " << res[i].gf << " ";
        cout << res[i].g << endl;
    }
    return 0;
}
