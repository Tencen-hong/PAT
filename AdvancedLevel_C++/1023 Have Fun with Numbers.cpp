#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <map>

using namespace std;


int main() {

    string str;
    int arr[10]={0};
    vector<int> c;
    cin>>str;
    for (int i = 0; i < str.size(); ++i) {
        int tmp = str[i]-'0';
        c.push_back(tmp);
        arr[tmp]++;
    }
    int flag = 0;
    reverse(c.begin(),c.end());
    vector<int> b;
    for (int i = 0; i < c.size(); ++i) {
        int tmp = c[i]*2+flag;
        b.push_back(tmp%10);
        flag = tmp/10;
    }
    if(flag)
        b.push_back(flag);
    reverse(b.begin(),b.end());
    for (int i = 0; i < b.size(); ++i) {
        arr[b[i]]--;
    }
    bool f=true;
    for (int i = 0; i < 10; ++i) {
        if(arr[i]!=0)
            f=false;
            
    }
    if(f)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = 0; i < b.size(); ++i) {
        printf("%d",b[i]);
    }
 

    return 0;
}
