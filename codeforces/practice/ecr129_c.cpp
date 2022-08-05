// Problem Link: https://codeforces.com/contest/1681/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<pair<int,int>> swaps;
    for (int i = 0; i < n; i++) {
        int mn_a = *min_element(a.begin() + i, a.end());
        int mn_b = *min_element(b.begin() + i, b.end());

        int pos = -1;

        for (int j = i; j < n; j++) {
            if (a[j] == mn_a && b[j] == mn_b) {
                pos = j;
            }
        }

        if (pos != -1 && pos != i) {
            swaps.push_back({i, pos});
            swap(a[i], a[pos]);
            swap(b[i], b[pos]);
        } else if (pos == -1) {
            cout << -1 << "\n";
            return ;
        }
    }

    cout << swaps.size() << "\n";
    for (auto x : swaps) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
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