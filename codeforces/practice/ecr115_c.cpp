// Problem Link: https://codeforces.com/contest/1598/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += 1ll * a[i] * 2;
    }
    if (sum % n  > 0) {
        cout << 0 << "\n";
        return;
    }
    ll y = sum / n;
    ll ans = 0;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x = y - a[i];
        ans += mp[x];
        mp[a[i]]++;
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