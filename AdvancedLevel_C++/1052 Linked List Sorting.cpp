#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int address;
    int key;
    int next;
    bool flag = false;
};

bool cmp1(node a, node b) {
    return (a.flag && b.flag) ? a.key < b.key : a.flag > b.flag;
}

int main() {
    int n, s, cnt = 0;
    vector<node> list(100000);
    scanf("%d %05d", &n, &s);
    for (int i = 0; i < n; ++i) {
        node tmp;
        scanf("%05d %d %05d", &tmp.address, &tmp.key, &tmp.next);
        list[tmp.address] = tmp;
    }

    for (int i = s; i != -1; i = list[i].next) {
        list[i].flag = true;
        cnt++;
    }

    if (cnt == 0)
        printf("0 -1");
    else {
        sort(list.begin(), list.end(), cmp1);
        printf("%d %05d\n", cnt, list[0].address);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", list[i].address, list[i].key);
            if (i != cnt - 1)
                printf("%05d\n", list[i + 1].address);
            else
                printf("-1\n");
        }
    }
    return 0;
}
