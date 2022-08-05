// Problem Link: https://codeforces.com/contest/1679/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> a(n);
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = 0;
        sm += a[i].first;
    }

    pair<int, int> lst = {-1, -1};

    for (int j = 1; j <= q; j++) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; --i;
            sm -= ((a[i].second > lst.second) ? a[i].first : lst.first);
            sm += x;
            a[i].first = x;
            a[i].second = j;

        } else {
            int x; cin >> x;
            lst.second = j;
            lst.first = x;
            sm = 1ll * n * x;
        }
        cout << sm << "\n";
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}