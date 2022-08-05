// Problem Link: https://codeforces.com/contest/1547/problem/E

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k), t(k), tab(n, MAX);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) {
        cin >> t[i];
        tab[a[i] - 1] = t[i];
    }
    vector<int> L(n, MAX), R(n, MAX);
    L[0] = min(L[0], tab[0]);
    for (int i = 1; i < n; i++) {
        L[i] = min(L[i - 1] + 1,  tab[i]);
    }
    R[n - 1] = min(R[n - 1], tab[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        R[i]  = min(R[i + 1] + 1, tab[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << min(L[i], R[i]) << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
}