#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double p,r;
int n,max_height,cnt=0;
vector<vector<int>> chain;

void dfs(int root,int level){
    if(max_height<level){
        max_height=level;
        cnt=1;
    }else if(max_height==level){
        cnt++;
    }
    for (int i = 0; i < chain[root].size(); ++i) {
        dfs(chain[root][i],level+1);
    }
}

int main() {

    int tmp,root;

    scanf("%d %lf %lf",&n,&p,&r);
    chain.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        if(tmp==-1)
        {
            root=i;
            continue;
        }
        chain[tmp].push_back(i);
    }

    dfs(root,0);

    double price = pow(1+(double)r/100,max_height)*p;
    printf("%.2lf %d",price,cnt);


    return 0;
}
