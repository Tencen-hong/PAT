#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {

    long long int a, b, c;
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: ", i);
        long long int sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {
            printf("true\n", i);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("false\n", i);
        } else if (sum > c) {
            printf("true\n", i);
        } else {
            printf("false\n", i);
        }
    }


    return 0;
}
