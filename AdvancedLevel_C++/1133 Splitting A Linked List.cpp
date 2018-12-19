#include <iostream>
#include <vector>

using namespace std;

struct node {
    int address, next, data;
};

/*
 * 00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
 */
int main() {
    int st, n, k;
    cin >> st >> n >> k;
    vector<node> v(100010), res;
    node tmp;
    vector<node> negative, before_k, after_f;
    for (int i = 0; i < n; ++i) {
        cin >> tmp.address >> tmp.data >> tmp.next;
        v[tmp.address] = tmp;
    }

    while (st != -1) {
        if (v[st].data < 0)
            negative.push_back(v[st]);
        else if (v[st].data <= k)
            before_k.push_back(v[st]);
        else
            after_f.push_back(v[st]);
        st = v[st].next;
    }
    int i = 0;
    while (i < negative.size()) {
        res.push_back(negative[i]);
        i++;
    }
    i = 0;
    while (i < before_k.size()) {
        res.push_back(before_k[i]);
        i++;
    }
    i = 0;
    while (i < after_f.size()) {
        res.push_back(after_f[i]);
        i++;
    }

    for (i = 0; i < res.size() - 1; ++i) {
        printf("%05d %d %05d\n", res[i].address, res[i].data, res[i + 1].address);
    }
    printf("%05d %d %d\n", res[i].address, res[i].data, -1);
    return 0;
}
