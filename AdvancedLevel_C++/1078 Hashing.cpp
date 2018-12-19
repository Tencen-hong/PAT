#include <iostream>

using namespace std;

bool isprime(int a) {
    if (a == 1)return false;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int func(int a) {
    while (!isprime(a))a++;
    return a;
}

bool hashTable[10010];

int main() {
    int Msize, n, key;
    scanf("%d %d", &Msize, &n);
    int size = func(Msize);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        int index = key % size;
        if (!hashTable[index]) {
            hashTable[index] = true;
            if (i != 0) printf(" ");
            printf("%d", index);
        } else {
            int flag = 0;
            for (int step = 1; step < size; ++step) {//二次方探查法解决冲突,index = (key + step * step) % size
                index = (key + step * step) % size;
                if (!hashTable[index]) {
                    hashTable[index] = true;
                    flag = 1;
                    if (i != 0) printf(" ");
                    printf("%d", index);
                    break;
                }
            }
            if (flag == 0) {
                if (i != 0) printf(" ");
                printf("-");
            }
        }
    }

    return 0;
}
