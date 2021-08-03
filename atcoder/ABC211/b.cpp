#include <bits/stdc++.h>

using namespace std;

void solve() {
}

int main() {
    vector<string> s(4);
    vector<string> search = {"H", "2B", "3B", "HR"};

    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < 4; i++) {
        
        bool ok = false;

        for (int j = 0; j < 4; j++) {
            if (s[j] == search[i]) {
                ok = true;
            }
        }    
        if(!ok) {
            cout << "No";
            return 0;
        }

    }
    
    cout << "Yes\n";
    return 0;
}