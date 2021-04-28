#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(MAX);
    for (int i = 0; i < n + m; i++) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for (int i = 0; i < MAX; i++) {
        if (cnt[i] == 1) {
            cout << i << " ";
        }
    }
    return 0;
}