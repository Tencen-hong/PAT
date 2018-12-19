#include <iostream>
#include <vector>

using namespace std;

//每次用0交换
int main() {

    int n, num, cnt = 0, ans = 0, index = 1;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        v[num] = i;//数字num在i位置
        if (num != i && num != 0) cnt++;//除0外不在其位置的数量
    }
    while (cnt > 0) {
        if (v[0] == 0) {//当0在0位时，交换0位和第一个不在其所在位置的数字
            while (index < n) {//设置index避免每次都从头开始遍历
                if (v[index] != index) {
                    swap(v[index], v[0]);
                    ans++;
                    break;
                }
                index++;
            }
        }
        while (v[0] != 0) {//v[0]表示数字0所在的位置,当0在j位，j在m位时，j位本该是j,交换使得j在j位，0在m位
            swap(v[v[0]], v[0]);
            ans++;
            cnt--;
        }
    }
    printf("%d", ans);
    return 0;
}
