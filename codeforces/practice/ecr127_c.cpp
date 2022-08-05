// Problem Link: https://codeforces.com/contest/1671/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    ll sm = 0, ans = 0;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (ll i = 1; i <= n; i++) {
        ll y = a[i - 1];
        sm += y;
  
        ll tmp = (x - sm) / i ;

        if (sm <= x) ++tmp;

        ans += max(tmp, 0ll);
        
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}