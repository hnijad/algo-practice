// Problem Link: https://codeforces.com/contest/1635/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool isSorted = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            isSorted &= (a[i] >= a[i - 1]);
        }
    }
    if (isSorted) {
        cout << 0 << "\n";
        return;
    }    
    if (a[n - 1] >= a[n - 2] && a[n - 1] >= 0) {
        cout << n - 2 << "\n";
        for (int i = n - 3; i >= 0; i--) {
            cout << i + 1 << " " << i + 1 + 1 << " " << n - 1 + 1 << "\n";
        }
    } else {
        cout << - 1 << "\n";
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