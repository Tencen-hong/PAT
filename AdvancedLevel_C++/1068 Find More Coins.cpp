#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M; //n_coins; money_to_pay
bool choice[10010][110]; //形成值j的时候，是否要用硬币i
int dp[110]; //前面硬币所能构成的不大于i的最大值
int w[10010]; //硬币面值,0-N

bool cmp1(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &w[i]);
    }

    sort(w + 1, w + N + 1, cmp1); //硬币倒序

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= w[i]; j--) {
            if (dp[j - w[i]] + w[i] >= dp[j]) { // 如果前面的情况下，加入硬币w[i]后满足条件，有相等的情况也覆盖
                dp[j] = dp[j - w[i]] + w[i];
                choice[i][j] = true;
            }
        }
    }

    if (dp[M] != M) {
        printf("No Solution");
    } else {
        vector<int> arr;
        int index = N, v = M;
        while (v > 0) {
            if (choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", arr[i]);
        }

    }

    return 0;
}
