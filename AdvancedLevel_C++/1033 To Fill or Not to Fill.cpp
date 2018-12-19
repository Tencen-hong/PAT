#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

const int inf = 9999999;
struct station {
    double price, dis;
};

bool cmp1(station a, station b) {
    return a.dis < b.dis;
}

int main() {
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};//将终点加进去
    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &sta[i].price, &sta[i].dis);
    }//#
    sort(sta.begin(), sta.end(), cmp1);//排序后，sta[n]表示终点
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalprice = 0.0, leftdis = 0.0;
    if (sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while (nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for (int i = 1; i <= n && sta[i].dis <= maxdis; ++i) {//在满油箱所能达到的最远距离内考虑
            if (sta[i].dis <= nowdis) continue;//已经经过的站，忽略
            if (sta[i].price < nowprice) {//sta[n].dis=d,sta[n].price=0,所以终点一定会进来这里
                totalprice += (sta[i].dis - nowdis - leftdis) / davg * nowprice; //开到比当前价格低的加油站 所需要加的油*当前油价, ()一定为正，若为负则剩余的油能超过这个加油站，则应该在上一轮就被处理
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if (sta[i].price < minPrice)//当后面的油价都高于现在的油价，选取油价最低的那一个，
            {
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if (flag == 0 && minPrice != inf) {
            totalprice += nowprice * (cmax - leftdis / davg);//当前加油站，油箱加满
            leftdis = cmax * davg - (minPriceDis - nowdis);//多加的油所能开的路程
            nowprice = minPrice;
            nowdis = minPriceDis;
        }
        if (flag == 0 && minPrice == inf) {//只有当sta[i].dis > maxdis时，minPrice才不会被赋值，即超出油箱最大里程
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalprice);


    return 0;
}
