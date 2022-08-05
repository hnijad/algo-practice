// Problem Link: https://codeforces.com/contest/1583/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> isBetween(n, false);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        isBetween[b - 1] = true;
    }
    int node = -1;
    for (int i = 0; i < n; i++) {
        if (isBetween[i] == false) {
            node = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (node + 1 == i) continue;
        cout << node + 1 << " " << i << "\n";
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}