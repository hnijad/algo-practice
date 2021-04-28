#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
vector<vector<int>> graph(MAX);
vector<bool> used(MAX);

void build(int n, int len) {
    if (n == len) return;
    int h = n / 2;
    for (int i = 1; i <= h; i++) {
        graph[i].push_back(n - i + 1);
    }
    build(h, len);
}

void dfs(int u, vector<int>& gr) {
    gr.push_back(u);
    used[u] = true;
    for (int v : graph[u]) {
        dfs(v, gr);
    }
}

int main() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    int cnt = 0;
    int len = 0;
    while (n) {
        if (cnt == k) {
            len = n;
        }
        n /= 2;
        ++cnt;
    }
    if (cnt < k || len == 1) {
        cout << "impossible" << endl;
        return 0;
    }

    build(s.size(), len);
    vector<vector<pair<int, int>>> vc(len);

    int ans = 0;
    bool isPalindrome = true;
    for (int i = len; i >= 1; i--) {
        vector<int> gr;
        dfs(i, gr);
        vector<pair<int, int>> freq(26);
        for (int j = 0; j < 26; j++) {
            freq[j].second = j;
        }
        for (int pos : gr) {
            ++freq[s[pos - 1] - 'a'].first;
        }
        sort(freq.begin(), freq.end());  // partial_sort
        ans += gr.size() - freq[25].first;
        vc[i - 1].push_back(freq[25]);
        vc[i - 1].push_back(freq[24]);
        if (i <= len / 2) {
            int tmp = len - i + 1;
            if (freq[25].second != vc[tmp - 1][0].second) {
                isPalindrome = false;
            }
        }
    }
    int res = ans;
    if (isPalindrome) {
        if (len) res = 1e9;
        for (int i = 1; i <= len; i++) {
            if (len & 1 && i == (len + 1) / 2) continue;

            if (vc[i - 1].size() > 1) {
                res = min(res, ans + vc[i - 1][0].first - vc[i - 1][1].first);
            }
        }
    }
    for (int i = 1; i <= s.size(); i++) {
        if (!used[i]) {
            vector<int> gr;
            dfs(i, gr);
            vector<pair<int, int>> freq(26);
            for (int j = 0; j < 26; j++) {
                freq[j].second = j;
            }
            for (int pos : gr) {
                ++freq[s[pos - 1] - 'a'].first;
            }
            sort(freq.begin(), freq.end());  // partial_sort
            res += gr.size() - freq[25].first;
        }
    }
    cout << res << "\n";
    return 0;
}