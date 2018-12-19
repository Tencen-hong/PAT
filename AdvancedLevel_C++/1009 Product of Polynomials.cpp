#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int main() {
    int n1, n2, a, count = 0;
    scanf("%d", &n1);
    double b, arr[1001] = {0.0}, res[2001] = {0.0};
    for (int i = 0; i < n1; i++) {
        scanf("%d %lf", &a, &b);
        arr[a] = b;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d %lf", &a, &b);
        for (int j = 0; j < 1001; j++)
            res[j + a] += arr[j] * b;
    }
    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0.0) count++;
    printf("%d", count);
    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0.0)
            printf(" %d %.1f", i, res[i]);


    return 0;
}

