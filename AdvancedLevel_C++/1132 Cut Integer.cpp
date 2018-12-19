#include <iostream>

using namespace std;

int main() {
    string z, str_a, str_b;
    int n;
    long long int int_a, int_b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> z;
        str_a = z.substr(0, z.size() / 2);
        str_b = z.substr(z.size() / 2, z.size() / 2);
        int_a = stoll(str_a);
        int_b = stoll(str_b);
        if (int_a * int_b == 0)
            cout << "No" << endl;
        else {
            if (stoll(z) % (int_a * int_b) == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
