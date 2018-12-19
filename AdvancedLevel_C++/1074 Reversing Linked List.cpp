#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct node {
    int addr, data, next;
};


int main() {
    int start, n, k;
    node link[100010], temp;
    vector<node> res;

    scanf("%d %d %d", &start, &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &temp.addr, &temp.data, &temp.next);
        link[temp.addr] = temp;
    }

    int index = start;

    while (index != -1) {
        res.push_back(link[index]);
        index = link[index].next;
    }//从开始地址 copy整个链表

    int pos = 0;
    while (pos + k <= res.size()) {
        reverse(res.begin() + pos, res.begin() + pos + k);
        pos = pos + k;
    }//每k个元素 reverse一次

    for (int i = 0; i < res.size() - 1; ++i) {
        res[i].next = res[i + 1].addr;
    }//修改每个节点的next

    for (int i = 0; i < res.size() - 1; ++i) {
        printf("%05d %d %05d\n", res[i].addr, res[i].data, res[i].next);
    }

    int size = res.size();
    printf("%05d %d -1\n", res[size - 1].addr, res[size - 1].data);

    return 0;
}

