#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sm = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        sm += a[i];
        if (sm == x) {
            if (i == n - 1) {
                cout << "NO\n";
                return;
            } else {
                swap(a[n - 1], a[i]);
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
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