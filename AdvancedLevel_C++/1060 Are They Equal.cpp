#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d %s %s", &n, a, b);

    int cnta = strlen(a), cntb = strlen(b);
    for (int i = 0; i < strlen(a); ++i) {
        if (a[i] == '.') {
            cnta = i;
            break;
        }
    }
    for (int i = 0; i < strlen(b); ++i) {
        if (b[i] == '.') {
            cntb = i;
            break;
        }
    }//cnta,cntb分别得到小数点的下标

    int indexa = 0, indexb = 0;
    while (a[p] == '0' || a[p] == '.')p++;
    while (b[q] == '0' || b[q] == '.')q++;//p,q分别指向第一个非0数字

    if (cnta >= p)
        cnta = cnta - p;
    else
        cnta = cnta - p + 1;
    if (cntb >= q)
        cntb = cntb - q;//小数点在第一个非0数字的右边，指数=cnta-p
    else
        cntb = cntb - q + 1;//左边，指数=xnta-p+1

    if (p == strlen(a))
        cnta = 0;
    if (q == strlen(b))
        cntb = 0;//都是0

    while (indexa < n) {
        if (a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if (p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }
    while (indexb < n) {
        if (b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if (q >= strlen(b))
            B[indexb++] = '0';
        q++;
    }//copy底数,不够精度的位置补0

    if (strcmp(A, B) == 0 && cnta == cntb)//底数和指数都相等，a,b才相等
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d", A, cnta, B, cntb);

    return 0;
}
