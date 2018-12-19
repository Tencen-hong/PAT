#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n + 1);
    data[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());

    vector<int> prefixSum(n + 1);
    int tempSum = 0;
    for (int i = 0; i <= n; ++i) {
        tempSum += data[i];
        prefixSum[i] = tempSum;
    }

    //分成n1,n2两部分,且|n1-n2|最小=>在中点左右
    int pivot = n / 2;
    if (n % 2 == 0) {
        int right = prefixSum[n] - prefixSum[pivot];
        int left = prefixSum[pivot];
        int S = right - left;
        printf("%d %d", 0, S);
    } else {
        int right1 = prefixSum[n] - prefixSum[pivot];
        int left1 = prefixSum[pivot];
        int s1 = right1 - left1;
        pivot++;
        int right2 = prefixSum[n] - prefixSum[pivot];
        int left2 = prefixSum[pivot];
        int s2 = right2 - left2;
        printf("%d %d", 1, max(s1, s2));
    }

    return 0;
}
