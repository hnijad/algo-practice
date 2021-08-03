#include <bits/stdc++.h>

using namespace std;

void solve() {
    double a,b;
    cin >> a >> b;
    cout<< fixed << setprecision(12) << (a - b) / 3 + b;
}

int main() {
    int t = 1; 
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}