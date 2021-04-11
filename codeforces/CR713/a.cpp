#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(101);
        vector<int> ind(101);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            ind[x] = i + 1;
        }
        for (int i = 0; i < 101; i++) {
            if (cnt[i] == 1) {
                cout << ind[i] << "\n";
            }
        }
    }
    return 0;
}
