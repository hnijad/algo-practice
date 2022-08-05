// Problem Link: https://codeforces.com/contest/1582/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isPalindrome(const string & s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int getSum(const vector<vector<int>> &cnt, int ind, int l, int r) {
    if (l == 0) return cnt[ind][r];
    return cnt[ind][r] - cnt[ind][l - 1];
}

void solve() {
    int n;
    cin >> n;
    string s; 
    cin >> s;
    vector<vector<int>> cnt(26, vector<int> (n, 0));

    for (int i = 0; i < n; i++) cnt[s[i] - 'a'][i]++;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int j = 1; j < n; j++) {
            cnt[ch - 'a'][j] += cnt[ch - 'a'][j - 1];
        }
    }

    int ans = INT_MAX;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        vector<int> indecies;
        indecies.push_back(0);
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (s[j] != ch) {
                indecies.push_back(j);
                temp.push_back(s[j]);
            }
        }  
        indecies.push_back(n - 1);
        if (isPalindrome(temp) == false) continue;
        int indSize = indecies.size(), palSize = temp.size();
        
        for (int i = 0; i + 1 < indSize / 2 + indSize % 2; i++) {
            int left = getSum(cnt, ch - 'a', indecies[i], indecies[i + 1]);
            int right = getSum(cnt, ch - 'a',indecies[indSize - i - 2], indecies[indSize - i - 1]);
            palSize += min(left, right) * 2;
        }
        if (temp.size() % 2 == 0) {
            palSize += getSum(cnt, ch - 'a', indecies[indSize / 2 - 1], indecies[indSize / 2]);
        }
        ans = min(ans, n - palSize);
    }
    if (ans == INT_MAX) ans = - 1;
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}