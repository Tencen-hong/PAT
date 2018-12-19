#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


struct node {
    int weight, rank, index;
};

int main() {
    int n, g;
    scanf("%d %d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i].weight);
        w[i].index = i;//保存原来的顺序
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    queue<node> q;//按游戏顺序压入队列
    for (int i = 0; i < n; ++i) {
        q.push(w[v[i]]);
    }
    while (!q.empty()) {
        int size = q.size();
        if (size == 1) {
            node tmp = q.front();
            w[tmp.index].rank = 1;
            break;
        }

        int group = size / g;
        if (size % g != 0)
            group += 1;  //正好整除为group组，有剩余则多余的再成一组

        node maxnode;
        int maxn = -1, cnt = 0;
        for (int i = 0; i < size; ++i) {
            node tmp = q.front();
            w[tmp.index].rank = group + 1;//没有晋级的即为group+1名,晋级的rank会在下一轮被覆盖
            q.pop();
            cnt++;
            if (tmp.weight > maxn) {//每组找一个weight最大的晋级
                maxn = tmp.weight;
                maxnode = tmp;
            }
            if (cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }

    }

    for (int i = 0; i < n; ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", w[i].rank);
    }


    return 0;
}
