
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    long int n, cnt = 0, num;
    vector<long int> res, prime(500000, 1);
    map<long int, long int> m;

    for (int i = 2; i * i < 500000; i++)
        for (int j = 2; j * i < 500000; j++)
            prime[j * i] = 0;//建立质数表


    scanf("%ld", &n);
    num = n;
    while (n > 0) {
        long int i;
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0 && prime[i] == 1) {
                res.push_back(i);//得到质数因子
                n = n / i;
                break;
            }
        }
        if (i > n / 2) {
            res.push_back(n);//最后一个质数
            break;
        }
    }

    for (long int i = 0; i < res.size(); ++i) {
        m[res[i]]++;//统计各因子数量
    }

    printf("%ld=", num);
    for (auto item:m) {
        if (cnt > 0)
            printf("*");
        if (item.second >= 2) {
            printf("%ld^%ld", item.first, item.second);
            cnt++;
        } else {
            printf("%ld", item.first);
            cnt++;
        }

    }


    return 0;
}
