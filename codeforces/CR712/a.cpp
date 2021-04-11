#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        int b = i;
        int e = n - (i + 1);
        if (b > e) break;
        if (s[b] != s[e]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (!isPalindrome(s + 'a')) {
            cout << "YES\n";
            cout << s + 'a' << "\n";
        } else if (!isPalindrome('a' + s)) {
            cout << "YES\n";
            cout << 'a' + s << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}