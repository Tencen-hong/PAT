
/***
穷举，假设i,j为狼人，其余为好人， //a数组，-1表示狼人，1表示好人  
设这种情况为最终结果，k从头开始遍历，看每个人的说法与结果是否有出入，不同则认为此人说谎，加入liar,  //v[k]*a[abs(v[k])]是否<0
1.判定liar的数量是否为2，
2.判定liar是否刚好为一个狼人+一个好人
***/

#include<iostream>
#include<vector>

using namespace std;
int main() {
    int N;
    cin >> N;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            vector<int> a(N + 1, 1), liar;
            a[i] = a[j] = -1;
            for (int k = 1; k <= N; k++) {
                if (v[k] * a[abs(v[k])] < 0)
                    liar.push_back(k);
            }
            if (liar.size() == 2 && a[liar[0]] + a[liar[1]] == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";

    return 0;
}
