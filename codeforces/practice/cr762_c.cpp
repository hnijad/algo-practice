// Problem Link: https://codeforces.com/contest/1619/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll toLong(string s) {
    ll ans = 0LL;
    ll base = 1;
    for (int i = 0; i < s.size(); i++) {
        ans = ans + 1ll * (s[i] - '0') *  base;
        base *= 10;
    }
    return ans;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    if (b < a) {
        cout << -1 << "\n";
        return;
    }
    string ans = "";
    while (a > 0 && b > 0) {
        if ( (b % 10) >= (a % 10) ) {
            ans += (b % 10) - (a % 10) + '0';
            b /= 10;
            a /= 10;
        } else {
            ll modA = a % 10;
            ll modB = b % 100;
            ll dif = modB - modA;
            if (dif >= 0 && dif <= 9) {
                ans += dif + '0';
                a /= 10;
                b /= 100;
            } else {
                cout << -1 << "\n";
                return;
            }
        }
    }
    if (a > 0) {
        cout << -1 << "\n";
        return;
    }

    while (b > 0) {
        ans += b % 10 + '0';
        b /= 10;
    }
    //reverse(ans.begin(), ans.end());
    cout << toLong(ans) << "\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}