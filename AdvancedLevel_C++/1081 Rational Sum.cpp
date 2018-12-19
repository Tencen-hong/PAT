#include <iostream>
#include <stdlib.h>
using namespace std;

//最大公约数
long long int gcd(long long int a, long long int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    long long int a, b, gcdvalue, suma = 0, sumb = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;//约分
        suma = suma * b + a * sumb;//   suma/sumb = suma/sumb + a/b  分数相加
        sumb = sumb * b;
        gcdvalue = gcd(suma, sumb);
        suma = suma / gcdvalue;
        sumb = sumb / gcdvalue;
    }

    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if (integer != 0) {
        printf("%lld", integer);
        if (suma != 0)
            printf(" ");
    }
    if (suma != 0)
        printf("%lld/%lld", suma, sumb);
    if (integer == 0 & suma == 0)
        printf("0");
    return 0;
}
