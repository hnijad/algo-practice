#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)(1e9) + 7;

char getPrev(char ch) {
    switch (ch) {
        case 'h':
            return 'c';
        case 'o':
            return 'h';
        case 'k':
            return 'o';
        case 'u':
            return 'k';
        case 'd':
            return 'u';
        case 'a':
            return 'd';
        case 'i':
            return 'a';
    }
    return 'z';
}

int main() {
    string s;
    cin >> s;

    vector<int> dp(27);
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'c') {
            dp[s[i] - 'a']++;
            continue;
        }
        char ch = getPrev(s[i]);
        dp[s[i] - 'a'] += dp[ch - 'a'];

        if (dp[s[i] - 'a'] >= MOD) {
            dp[s[i] - 'a'] -= MOD;
        }
    }
    cout << dp['i' - 'a'] << "\n";

    return 0;
}