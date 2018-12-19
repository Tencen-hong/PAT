#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


struct node {
    int GE, GI, total;
    int id, rank;
    vector<int> prefer;//志愿
};

bool cmp1(node a, node b) {
    if (a.total != b.total)
        return a.total > b.total;
    else if (a.GE != b.GE)
        return a.GE > b.GE;
    return a.id < b.id;
}

int main() {
    int N, M, K;
    vector<vector<int>> admitted;//admitted[i][j]表示i学校录取的学生id
    vector<int> quota, last_rank;//学校配额，最后录取的学生的排名
    vector<node> stu;

    scanf("%d %d %d", &N, &M, &K);
    quota.resize(M);
    stu.resize(N);
    admitted.resize(M);
    last_rank.resize(M);

    for (int i = 0; i < M; ++i) {
        scanf("%d", &quota[i]);
    }

    for (int i = 0; i < N; ++i) {
        stu[i].id = i;
        stu[i].prefer.resize(K);
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        stu[i].total = (stu[i].GI + stu[i].GE);
        for (int j = 0; j < K; ++j) {
            scanf("%d", &stu[i].prefer[j]);
        }
    }

    sort(stu.begin(), stu.end(), cmp1);

    stu[0].rank = 1;
    for (int i = 1; i < stu.size(); ++i) {
        if (stu[i].total == stu[i - 1].total && stu[i].GE == stu[i - 1].GE)
            stu[i].rank = stu[i - 1].rank;
        else
            stu[i].rank = stu[i - 1].rank + 1;
    }

    for (int i = 0; i < stu.size(); ++i) {
        for (int j = 0; j < K; ++j) {
            int school_id = stu[i].prefer[j];
            if (quota[school_id] > 0 || last_rank[school_id] == stu[i].rank) {//配额有剩余 或  排名和最后一名录取的 相同，则统统录取
                quota[school_id]--;
                last_rank[school_id] = stu[i].rank;
                admitted[school_id].push_back(stu[i].id);
                break;
            }
        }
    }

    for (int i = 0; i < admitted.size(); ++i) {
        sort(admitted[i].begin(), admitted[i].end());
        for (int j = 0; j < admitted[i].size(); ++j) {
            if (j != 0) printf(" ");
            printf("%d", admitted[i][j]);
        }
        printf("\n");
    }

    return 0;
}
