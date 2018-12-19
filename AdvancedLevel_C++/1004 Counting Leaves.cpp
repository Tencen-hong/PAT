

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int res[100];
vector<int> v[100];
int maxdepth;
void dfs(int id,int depth)
{
    if(v[id].size() == 0)
    {
        res[depth]++;
        maxdepth = max(maxdepth,depth);
    }else{
        for (int i = 0; i < v[id].size(); ++i) {
            dfs(v[id][i],depth+1);
        }
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);//n:总节点，m:非叶节点
    for(int i=0;i<m;i++)
    {
        int id,k;
        scanf("%d %d",&id,&k);  //按 id，孩子节点数量，孩子节点id 初始化存储
        for(int j=0;j<k;j++)
        {
            int c ;
            scanf("%d",&c);
            v[id].push_back(c);
        }
    }
    //
    dfs(1,0);

    printf("%d",res[0]);
    for (int l = 1; l <= maxdepth; ++l) {
        printf(" %d",res[l]);
    }

    return 0;
}

