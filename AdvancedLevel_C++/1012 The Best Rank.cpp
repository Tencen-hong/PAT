#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int id, best;
    int score[4], rank[4];
} stu[2005];
int flag, exist[1000000];

bool cmp1(node a, node b) {
    return a.score[flag] > b.score[flag];
}

int main() {
    int n, m, id;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
    }//输入数据
    for (flag = 0; flag <= 3; ++flag) {
        sort(stu, stu + n, cmp1);
        stu[0].rank[flag] = 1;
        for (int i = 1; i < n; ++i) {
            stu[i].rank[flag] = i + 1;
            if (stu[i].score[flag] == stu[i - 1].score[flag])
                stu[i].rank[flag] = stu[i - 1].rank[flag];
        }
    }给每个stu的每个科目作排名
    for (int i = 0; i < n; ++i) {
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        for (int j = 1; j <= 3; ++j) {
            if (stu[i].rank[j] < minn) {
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }//每个stu的最高排名下标
    char c[5] = {"ACME"};
    for (int k = 0; k < m; ++k) {
        cin >> id;
        int tmp = exist[id];
        if (tmp) {
            int best = stu[tmp - 1].best;
            printf("%d %c\n", stu[tmp - 1].rank[best], c[best]);
        } else
            printf("N/A\n");
    }

    return 0;
}
