#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = k - (k / 2 + (k % 2)) + (n - k);
    cout << cnt << "\n";
    for (int i = k / 2 + (k % 2); i < k; i++) {
        cout << i << " ";
    }
    for (int i = k + 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}