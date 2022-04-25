#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX = 1000000;
 
ll n;

int findSmalestB(int a) {
    int lower = 0;
    int high = MAX;
    int res = MAX;

    while (lower <= high) {
        int mid = (lower + high) / 2;

        ll val = 1ll * (a + mid) * (1ll * a * a + 1ll * mid * mid);

        if (val >= n) {
            high = mid - 1;
            res = mid;
        } else {
            lower = mid + 1;
        }
    }
    return res;
}

int main() {
    cin >> n;
    ll ans = LLONG_MAX;

    for (int i = 0; i <= MAX; i++) {
        int a = i;
        int b = findSmalestB(i);
        ans = min(ans, 1ll * (a + b) * (1ll * a * a + 1ll * b * b));
    } 
    cout << ans << "\n";
    return 0;
}