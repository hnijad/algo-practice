// Problem Link: https://codeforces.com/contest/1692/problem/E

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void print(vector<int> v) {
    for (int x: v) {
        cout << x << " ";
    }
    cout << "\n";
}

void solve() {
    int n, s, x;
    cin >> n >> s;
    vector<int> pref(n), mp(n + 1, 1e9);
    for (int i = 0; i < n; i++) {
        cin >> x;
        pref[i] = x + ((i == 0) ? 0 : pref[i - 1]);
        mp[pref[i]] = min(mp[pref[i]], i);
    }
    //print(pref);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (pref[i] < s) continue;
        int dif = pref[i] - s;
        if (dif == 0) ans = min(ans, n - i - 1);
        else ans = min(ans, mp[dif] + 1 + n - i - 1);
        //cout << dif << " " << ans << "\n";
    }

    if (ans == INT_MAX) ans = -1;
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