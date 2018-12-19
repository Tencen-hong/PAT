
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//判断输入是否为负数，判断n是否为素数，把n转换为d进制再反过来转换为10进制，判断是否为素数
bool isprime(int n) {
    if (n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {

    int n, d;
    while (scanf("%d", &n) != EOF) {
        if (n < 0) break;
        scanf("%d", &d);
        if (isprime(n) == false) {
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        do {
            arr[len++] = n % d;
            n = n / d;
        } while (n != 0);
        for (int i = 0; i < len; ++i) {
            n = n * d + arr[i];
        }
        printf("%s", isprime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}
