#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m, i, j, minsum = 99999999;
    vector<pair<int, int>> res;
    vector<int> sum;
    bool issol = false;
    cin >> n >> m;
    sum.resize(n + 1);
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        sum[i] = sum[i - 1] + tmp;//从1th到ith的和
    }
    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (sum[mid] < m)
            left = mid + 1;
        else if (sum[mid] == m) {
            left = mid;
            break;
        } else if (sum[mid] > m)
            right = mid - 1;
    }//二分查找 找到第一个大于m的下标作为起点

    for (j = left; j <= n; ++j) {
        int tmpsum = 99999999;
        for (i = j; i >= 1; --i) {//从后往前遍历
            if (sum[j] - sum[i - 1] < m)
                continue;
            if (sum[j] - sum[i - 1] == m) {
                issol = true;
                res.emplace_back(i, j);
                break;
            } else if (sum[j] - sum[i - 1] > m && !issol) {
                tmpsum = sum[j] - sum[i - 1];
                break;
            }
        }
        if (minsum > tmpsum && !issol) {
            minsum = tmpsum;
            res.clear();
            res.emplace_back(i, j);
        } else if (minsum == tmpsum && !issol) {
            res.emplace_back(i, j);
        }
    }

    for (int k = 0; k < res.size(); ++k) {
        printf("%d-%d\n", res[k].first, res[k].second);
    }


    return 0;
}
