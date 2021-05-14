#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), res(n, -1);
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++) {
        s.insert({0, i+1});
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        auto b = s.begin();
        s.erase(b);
        s.insert({ (*b).first + x , (*b).second});
        cout << (*b).second << " ";
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