#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    double TwS = 0.0;
    int Ns = 0, rank;
    string name;

};

bool cmp1(node a, node b) {
    if (a.TwS != b.TwS)
        return a.TwS > b.TwS;
    else if (a.Ns != b.Ns)
        return a.Ns < b.Ns;
    else
        return a.name < b.name;
}

int main() {
    int n;
    double score;
    string id, name;
    vector<node> sch;
    map<string, node> mmap;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> score >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        mmap[name].name = name;
        mmap[name].Ns++;
        if (id[0] == 'B') {
            score = score / 1.5;
        } else if (id[0] == 'T') {
            score = score * 1.5;
        }
        mmap[name].TwS += score;
    }

    for (auto it:mmap) {
        it.second.TwS = (int) it.second.TwS;//最后转为int
        sch.push_back(it.second);
    }
    sort(sch.begin(), sch.end(), cmp1);
    cout << sch.size() << endl;
    for (int i = 0; i < sch.size(); ++i) {
        sch[i].rank = i + 1;
        if (i != 0 && (int) sch[i].TwS == (int) sch[i - 1].TwS)
            sch[i].rank = sch[i - 1].rank;//修改rank
    }
    for (int i = 0; i < sch.size(); ++i) {
        cout << sch[i].rank;
        cout << " " << sch[i].name << " " << (int) sch[i].TwS << " " << sch[i].Ns << endl;
    }

    return 0;
}
