// Problem Link: https://codeforces.com/contest/1657/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0, r = n;
    int curLen = 0;
    bool type2 = false;
    for (int i = 0; i < n; i++) {
        if (type2) {
            if (s[i] == ')') {
                c += 1;
                r -= (curLen + 1);
                type2 = false;
            } else {
                curLen += 1;
            }
        } else {
            if (i + 1 < n) {
                if (s[i] == ')' && s[i + 1] == '(') {
                    type2 = true;
                    curLen = 2;
                } else {
                    c += 1;
                    r -= 2;
                }
                i++;
            }
        }
    }
    cout << c << " " << r << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}