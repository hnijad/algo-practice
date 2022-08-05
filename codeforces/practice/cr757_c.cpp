// Problem Link: https://codeforces.com/contest/1614/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX = 2 * 100000;
const int MOD = 1000000007;

int main() {
    vector<int> powOfTwo(MAX);
    powOfTwo[0] = 1;
    
    for (int i = 1; i < MAX; i++) {
        powOfTwo[i] = powOfTwo[i-1] * 2 % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int totalOr = 0;
        for (int i = 0; i < m; i++) {
            int l, r, x; cin >> l >> r >> x;
            totalOr |= x;
        }
        int ans = 1ll * totalOr * powOfTwo[n - 1] % MOD;
        cout << ans << "\n";
    }
    return 0;
}