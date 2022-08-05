// Problem Link: https://codeforces.com/contest/1594/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (s[i] != c);
    }

    if (cnt == 0) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = i; j <= n; j+=i) {
            tmp +=(s[j - 1] != c);
        }
        if (tmp == 0) {
            cout << 1 << "\n";
            cout << i << "\n";
            return;
        }
    }

    cout << 2 << "\n";
    cout << 2 << " " << ((n&1) ? n : n - 1) << "\n";
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}