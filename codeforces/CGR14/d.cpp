#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left(n + 1), right(n + 1);
    int need = n / 2 - min(l, r);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i < l)
            ++left[x];
        else
            ++right[x];
    }
    int price = 0;
    if (l < r) {
        swap(l, r);
        swap(left, right);
    }

    for (int i = 1; i <= n; i++) {
        int mn = min(left[i], right[i]);
        left[i] -= mn;
        right[i] -= mn;
        int half = left[i] / 2;
        int take = min(half, need);
        need -= take;
        price += take;
        left[i] -= 2 * take;
    }
    if (need) {
        for (int i = 1; i <= n; i++) {
            if (need == 0) break;
            if (left[i]) {
                need--;
                right[i]++;
                left[i]--;
                price++;
            }
        }
    }

    //cout << "Need -> " << need << "\n";
    //cout << "Price -> " << price << "\n";
    assert(need == 0);
    for (int i = 1; i <= n; i++) {
        //cout << left[i] << " " << right[i] << "\n";
        int mn = min(left[i], right[i]);
        left[i] -= mn;
        right[i] -= mn;
        price += right[i];
    }
    cout << price << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}