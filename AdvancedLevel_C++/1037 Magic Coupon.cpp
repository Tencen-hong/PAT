#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int nc, np, sum = 0;
    cin >> nc;
    vector<int> cou(nc);
    for (int i = 0; i < nc; ++i) {
        scanf("%d", &cou[i]);
    }
    cin >> np;
    vector<int> pro(np);
    for (int i = 0; i < np; ++i) {
        scanf("%d", &pro[i]);
    }
    sort(cou.begin(), cou.end());
    sort(pro.begin(), pro.end());

    int i = 0, j = 0;
    while ((i < nc) && (j < np) && cou[i] < 0 && pro[j] < 0) {
        sum += cou[i] * pro[j];
        i++;
        j++;
    }
    i = nc - 1;
    j = np - 1;
    while (i >= 0 & j >= 0 && cou[i] > 0 && pro[j] > 0) {
        sum += cou[i] * pro[j];
        i--;
        j--;
    }
    printf("%d", sum);


    return 0;
}
