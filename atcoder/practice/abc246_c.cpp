#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = a[i] / x;
        int mn = min(cnt, k);
        a[i] -= mn * x;
        k -= mn;
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        if (i < k) a[i] = max(0, a[i] - x);
        ans += a[i];
    }
    cout << ans << "\n";
    return 0;
}