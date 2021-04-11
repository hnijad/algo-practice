#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cntOne = 0;
        for (int i = 0; i < n; i++) {
            cntOne += (s[i] - '0');
        }
        if ((cntOne & 1) || s[0] == '0' || s[n - 1] == '0') {
            cout << "NO"
                 << "\n";
        } else {
            cout << "YES"
                 << "\n";
            string a = "(";
            string b = "(";
            int temp = 1;
            char lastZero = ')';
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '1') {
                    temp += 1;
                    if (temp <= cntOne / 2) {
                        a.push_back('(');
                        b.push_back('(');
                    } else {
                        a.push_back(')');
                        b.push_back(')');
                    }

                } else {
                    if (lastZero == ')') {
                        a.push_back('(');
                        b.push_back(')');
                        lastZero = '(';
                    } else {
                        a.push_back(')');
                        b.push_back('(');
                        lastZero = ')';
                    }
                }
            }
            a.push_back(')');
            b.push_back(')');    
            cout << a << "\n";
            cout << b << "\n";
        }
    }
    return 0;
}