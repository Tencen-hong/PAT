#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    int addr, key, next;
};


int main() {
    int begin_addr, n;
    scanf("%05d %d\n", &begin_addr, &n);

    vector<node> list(100010), removed, res;
    bool visit[100010] = {false};

    for (int i = 0; i < n; ++i) {
        node temp;
        cin >> temp.addr >> temp.key >> temp.next;
        list[temp.addr] = temp;
        visit[abs(temp.key)] = false;
    }

    while (begin_addr != -1) {
        if (!visit[abs(list[begin_addr].key)]) {
            visit[abs(list[begin_addr].key)] = true;
            res.push_back(list[begin_addr]);
        } else {
            removed.push_back(list[begin_addr]);
        }
        begin_addr = list[begin_addr].next;
    }

    int i = 0;
    for (i = 0; i < res.size(); ++i) {
        res[i].next = res[i + 1].addr;
        if (i != res.size() - 1)
            printf("%05d %d %05d\n", res[i].addr, res[i].key, res[i].next);
        else
            printf("%05d %d -1\n", res[i].addr, res[i].key);
    }

    for (i = 0; i < removed.size(); ++i) {
        removed[i].next = removed[i + 1].addr;
        if (i != removed.size() - 1)
            printf("%05d %d %05d\n", removed[i].addr, removed[i].key, removed[i].next);
        else
            printf("%05d %d -1\n", removed[i].addr, removed[i].key);
    }


    return 0;
}
