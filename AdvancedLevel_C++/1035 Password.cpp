#include <iostream>
#include <vector>

using namespace std;

bool flag[1010] = {false};

string modified(string password, int index) {
    for (int i = 0; i < password.size(); ++i) {
        if (password[i] == '1') {
            password[i] = '@';
            flag[index] = true;
        } else if (password[i] == '0') {
            password[i] = '%';
            flag[index] = true;
        } else if (password[i] == 'l') {
            password[i] = 'L';
            flag[index] = true;
        } else if (password[i] == 'O') {
            password[i] = 'o';
            flag[index] = true;
        }
    }
    return password;
}


int main() {
    int n;
    vector<pair<string, string>> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string tempaccount, temppassword;
        cin >> tempaccount >> temppassword;
        temppassword = modified(temppassword, i);
        v.emplace_back(tempaccount, temppassword);
    }
    int count = 0;
    for (int j = 0; j < 1010; ++j) {
        if (flag[j])
            count++;
    }
    if (count == 0) {
        if (n == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", n);
        return 0;
    } else {
        cout << count << endl;
        for (int i = 0; i < 1010; ++i) {
            if (flag[i]) {
                cout << v[i].first << " " << v[i].second << endl;
            }
        }
    }

    return 0;
}
