#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int cntOne = 0, cntZero = 0;
        for (int i = 0; i < n; i++) {
            cntOne += (a[i] == '1');
            cntZero += (a[i] == '0');
        }
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int bitA = (a[i] - '0' + carry) % 2;
            int bitB = b[i] - '0';
            if (bitA == bitB) {
                cntOne -= (bitA == 1);
                cntZero -= (bitA == 0);
            } else {
                if (cntZero == cntOne) {
                    ++carry;
                    cntOne -= (bitA == 0);
                    cntZero -= (bitA == 1);
                } else {
                    break;
                }
            }
        }
        if (cntOne == 0 && cntZero == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}