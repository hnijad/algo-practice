// Problem Link: https://codeforces.com/contest/1613/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll getDamage(const vector<int> &a, ll h) {
    ll damage = h;
    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] + h - 1 < a[i + 1]) {
            damage += h;
        } else {
            damage += a[i + 1] - a[i];
        }
    }
    return damage;
}

void solve() {
    int n; cin >> n;
    ll h; cin >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll low = 1, high = h;
    ll ans = h;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll damage = getDamage(a, mid);
        if (damage >= h) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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