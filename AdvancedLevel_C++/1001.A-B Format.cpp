#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    string res = to_string(a+b);
    for(int i=res.size()-1-2; i>0;)
    {
        if(res[i-1] != '-')
            res.insert(i,",");
        i-=3;
    }
    cout << res;
  return 0;
}

//分析：把a+b的和转为字符串s。从后往前每隔3位数字插入一个","。(前面有"-"则跳过)
