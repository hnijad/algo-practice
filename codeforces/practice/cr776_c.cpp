// Problem Link: https://codeforces.com/contest/1650/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int,int>>> vp(m);

    for (int i = 0; i < m; i++) {
        cin >> vp[i].second.first;
        cin >> vp[i].first;
        vp[i].second.second = i;
    }
    sort(vp.begin(), vp.end());
    vector<pair<int, int>> points, ans;
    int sm = 0;
    for (int i = 0; i < 2 * n; i++) {
        sm += vp[i].first;
        points.push_back({vp[i].second.first, vp[i].second.second});
    }
    sort(points.begin(), points.end());

    for (int i = 0; i < n; i++) {
        ans.push_back({points[i].second, points[2 * n - i - 1].second});
    }

    cout << sm << "\n";
    for (auto x : ans) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
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