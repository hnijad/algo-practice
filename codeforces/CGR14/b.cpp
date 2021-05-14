#include <bits/stdc++.h>

using namespace std;

bool isSquare(int n) {
    int s = sqrt(n);
    return (s * s == n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n & 1) {
            cout << "NO\n";
        } else {
            bool ok = false;
            if (n % 2 == 0) {
                if (isSquare(n / 2)) {
                    ok = true;
                }
            }
            if (n % 4 == 0) {
                if (isSquare(n / 4)) {
                    ok = true;
                }
            }
            if (ok)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}