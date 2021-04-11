#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int A, B, n;
        string s;
        cin >> B >> A;
        cin >> s;
        n = A + B;
        int b = 0;
        int e = n - 1;
        bool ok = true;

        while (b < e) {
            //cout << b << " " << e << "\n";
            if (s[b] == '?' && s[e] == '?') {
                b++;
                e--;
                continue;
            }
            if ((s[b] == '1' && s[e] == '0') || (s[b] == '0' && s[e] == '1')) {
                ok = false;
                break;
            }
            if (s[b] == '1' || s[e] == '1') {
                A -= 2;
                s[b] = '1';
                s[e] = '1';
            }
            if (s[b] == '0' || s[e] == '0') {
                B -= 2;
                s[b] = '0';
                s[e] = '0';
            }

            b++;
            e--;
        }
       // cout << s << "\n";
       // cout << A << " " << B << "\n";
        b = 0;
        e = n - 1;
        while (b <= e) {
            if (b == e) {
                if (s[b] == '?') {
                    if (A > 0) {
                        s[b] = '1';
                        --A;
                    } else if (B > 0) {
                        s[b] = '0';
                        --B;
                    } else {
                        ok = false;
                    }
                }else {
                    if(s[b] == '1'){
                        A--;
                    }else {
                        B--;
                    }
                }
            } else {
                if (s[b] == '?') {
                    if (A >= 2) {
                        s[b] = '1';
                        s[e] = '1';
                        A -= 2;
                    } else if (B >= 2) {
                        s[b] = '0';
                        s[e] = '0';
                        B -= 2;
                    } else {
                        ok = false;
                    }
                }
            }
            b++;
            e--;
        }
        if (ok && A == 0 && B == 0) {
            cout << s << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
