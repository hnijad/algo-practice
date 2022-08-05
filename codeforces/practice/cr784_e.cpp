// Problem Link: https://codeforces.com/contest/1669/problem/E

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int diff(string a, string b) {
    return (int)(a[0] != b[0]) + (int)(a[1] != b[1]);
}

void solve() {
    int n;
    cin >> n;
    map<string, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s].push_back(i);
    }
    ll ans = 0;
    for (auto e1 : mp) {
        for (auto e2: mp) {
            if (diff(e1.first, e2.first) == 1) {
                ans += 1ll * e1.second.size() * e2.second.size();
            }
        }
    }
    cout << ans / 2 << "\n";    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}