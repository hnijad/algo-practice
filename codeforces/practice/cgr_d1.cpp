// Problem Link: https://codeforces.com/contest/1326/problem/D1

#include <bits/stdc++.h>

using namespace std;

bool isPal(string& s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}

int p(string &s, int l, int r, bool isSuffix = false) {
    int mx = 0;
    for (int i = l; i <= r; i++) {
        int st = l;
        int len = i - l + 1;
        if (isSuffix) {
            st = i;
            len = r - i + 1;
        }
        string str = s.substr(st, len);
        if (isPal(str)) {
            mx = max(mx, len);
        }
    }
    return mx;
}

void solve() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s << "\n";
        return;
    }
    int l = 0;
    int r = (int)s.size() - 1;
    while (s[l] == s[r] && l <= r) {
        l++, r--;
    }
    if (l > r) {
        cout << s << "\n";
        return;
    }

    int prefix_len = p(s, l, r);
    int suffix_len = p(s, l, r, true);
    if (prefix_len >= suffix_len) {
        l += prefix_len;
    } else {
        r -= suffix_len;
    }
    for (int i = 0; i < l; i++) cout << s[i];
    for (int i = r + 1; i < (int)s.size(); i++) cout << s[i];
    cout << "\n";
}


int main() {
   int t;
   cin >> t;
   while (t--) {
       solve();
   }
}