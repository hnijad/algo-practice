// Problem Link: https://codeforces.com/contest/1581/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    bool isYes = false;
    ll sm = 1ll * (n - 1) * n / 2;
    if (sm < m || m < n - 1) {
        isYes = false;
    } else if (n == 1) {
        if (k > 1) isYes = true;
    } else if ( 1ll * m < sm) {
        if (k > 3) isYes = true;
    } else if (k > 2) {
        isYes = true;
    }

    cout << (isYes ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}