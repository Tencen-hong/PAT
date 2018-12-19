
#include <iostream>
using namespace std;
int main() {
    float res[1001] ={0};
    int k,a,count=0;
    float b;
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %f",&a,&b);
        res[a] += b;
    }
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %f",&a,&b);
        res[a] += b;
    }
    for (int j = 0; j < 1001; ++j) {
        if(res[j] != 0)
            count++;
    }
    printf("%d",count);
    for (int j = 1000; j >= 0 ; --j) {
        if(res[j] != 0)
            printf(" %d %.1f",j,res[j]);
    }
    return 0;
}


//分析：设立res数组，长度为指数的最大值，res[i] = j表示指数i的系数为j，接收a和b输入的同时将对应指数的系数加入到res中，累计res中所有非零系数的个数，然后从后往前输出所有系数不为0的指数和系数
