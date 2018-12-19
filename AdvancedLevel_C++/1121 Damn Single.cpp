#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 100010


int main(){
    int  n,m;
    int m1[N],m2[N];
    bool attend[N];
    cin>>n;
    int ida,idb;
    fill(m1,m1+N,-1);
    fill(m2,m2+N,-1);
    for (int i = 0; i < n; ++i) {
        cin>>ida>>idb;
        m1[ida]=idb;
        m2[idb]=ida;
    }
    cin>>m;
    vector<int> guest(m);
    fill(attend,attend+N, false);

    for (int i = 0; i < m; ++i) {
        cin>>guest[i];
        attend[guest[i]]=true;
    }

    vector<int> res;
    for (int i = 0; i < m; ++i) {
        int other1=m1[guest[i]];
        int other2=m2[guest[i]];
        bool find_other=false;
        if(other1!=-1)
        {
            if(attend[other1]){
                find_other=true;
                continue;
            }
        }
        if(other2!=-1)
        {
            if(attend[other2])
            {
                find_other=true;
                continue;
            }
        }
        if(!find_other)
            res.push_back(guest[i]);
    }

    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for (int i = 0; i < res.size(); ++i) {
        if(i!=0)
            printf(" ");
        printf("%05d",res[i]);
    }

    return 0;
}
