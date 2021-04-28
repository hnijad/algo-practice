#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)(1e9) + 7;

int power(int a, int n) {
    if (n == 0) return 1;
    int q = power(a, n / 2);
    q = 1ll * q * q % MOD;
    if (n & 1) q = 1ll * q * a % MOD;
    return q;
}

int main() {
    int n, p;
    cin >> n >> p;
    int res = 1ll * (p - 1) * power(p - 2, n - 1) % MOD;
    cout << res << "\n";
    return 0;
}