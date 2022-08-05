// Problem Link: https://codeforces.com/contest/1278/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX =  1000000;

ll sum(int n) {
    return 1ll * n * (1ll * n + 1) / 2;
}

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);

    int d = a - b;
    int p = (a + b) % 2;

    for (int i = 0; i <= MAX; i++) {
        ll res = sum(i);
        if (res < d) continue;
        if ((p + res) % 2 == 0) {
            cout << i << "\n";
            return ;
        }
    }
    cout << -1 << "\n";
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
}