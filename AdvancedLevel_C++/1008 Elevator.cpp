#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0] = 0;
    int time = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        int tmp = v[i] - v[i - 1];
        if (tmp > 0) {
            time += tmp * 6 + 5;  //up
        } else if (tmp < 0) {
            time += abs(tmp) * 4 + 5; //down
        } else if (tmp == 0) {  //stop
            time += 5;
        }
    }
    cout << time;

    return 0;
}

