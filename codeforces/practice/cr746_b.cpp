// Problem Link: https://codeforces.com/contest/1592/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for (int i = n - x; i < x; i++) {
        if (b[i] != a[i]) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}