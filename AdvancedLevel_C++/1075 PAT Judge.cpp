#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct node {
    int user_id, score[6] = {-2, -2, -2, -2, -2, -2};
    int total = 0;
    bool flag = false;
    int perfect = 0;
    int rank;
};

bool cmp1(node a, node b) {
    if (a.total != b.total)
        return a.total > b.total;
    else {
        if (a.perfect != b.perfect)
            return a.perfect > b.perfect;
        else {
            return a.user_id < b.user_id;
        }
    }
}

int main() {

    int N, K, M;//users,problems,submittions
    int P[6];//full mark
    int user_id, problem_id, score;
    map<int, node> stu;
    vector<node> res;

    scanf("%d %d %d", &N, &K, &M);
    for (int i = 1; i <= K; ++i) {
        scanf("%d", &P[i]);
    }

    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &user_id, &problem_id, &score);
        if (stu.find(user_id) == stu.end()) {//新插入数据
            stu[user_id].user_id = user_id;
            stu[user_id].score[problem_id] = score;
        } else {
            if (score > stu[user_id].score[problem_id]) {
                stu[user_id].score[problem_id] = score;//更新最高分
            }
        }
        if (score >= 0)
            stu[user_id].flag = true;//如果有分数>=0，表示通过测试，是需要输出的,若果某人的所有分数都<0,那么不输出
    }

    for (auto it:stu) {
        if (!it.second.flag)
            continue;
        for (int i = 1; i <= K; ++i) {
            if (it.second.score[i] > 0)
                it.second.total += it.second.score[i];//统计总分
            if (it.second.score[i] == P[i])
                it.second.perfect++;//有一个小细节，就是他可能一个题会重复提交多次满分，所以在这里统计满分次数就不会重复
        }
        res.push_back(it.second);
    }

    sort(res.begin(), res.end(), cmp1);

    res[0].rank = 1;
    for (int i = 1; i < res.size(); ++i) {
        res[i].rank = i + 1;
        if (res[i - 1].total == res[i].total)
            res[i].rank = res[i - 1].rank;
    }//同分同排名

    for (int i = 0; i < res.size(); ++i) {
        printf("%d %05d %d", res[i].rank, res[i].user_id, res[i].total);
        for (int j = 1; j <= K; ++j) {
            if (res[i].score[j] == -2)
                printf(" -");//-2表示未提交
            else if (res[i].score[j] == -1)//-1表示已提交但是未通过
                printf(" 0");
            else
                printf(" %d", res[i].score[j]);
        }
        printf("\n");

    }


    return 0;
}

