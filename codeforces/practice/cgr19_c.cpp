// Problem Link: https://codeforces.com/contest/1637/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    priority_queue <int> pq;
    ll seed = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (i > 0 && i < n - 1) {
            if (num & 1) pq.push(num);
            else seed += (num / 2);
        }
    }
    ll ans = 0L;
    if (seed == 0) {
        if (pq.size() < 2) {
            cout << -1 << "\n";
            return;
        }

        ll mx1 = pq.top();
        pq.pop();
        ll mx2 = pq.top();
        pq.pop();
        if (mx1 < 2) {
            cout << -1 << "\n";
            return;
        }
        ans++;
        mx1 -= 2;
        seed = (mx2 + 1 ) / 2;
        pq.push(mx1);
    }

    while (!pq.empty()) {
        ll mx = pq.top();
        pq.pop();
        seed += (mx + 1) / 2;
        seed -= 1;
        ans++;
    }
    cout << ans + seed << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}