#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)(1e9) + 7;

vector<vector<int>> g;
vector<long long> dp;
vector<int> level;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    level[start] = 0;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : g[parent]) {
            if (level[child] == 0) {
                level[child] = level[parent] + 1;

                dp[child] += dp[parent];
                if (dp[child] >= MOD) dp[child] -= MOD;

                q.push(child);

            } else if (level[child] == level[parent] + 1) {
                dp[child] += dp[parent];

                if (dp[child] >= MOD) dp[child] -= MOD;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dp.resize(n, 0);
    level.resize(n, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(0);
    cout << dp[n - 1] << "\n";

    return 0;
}