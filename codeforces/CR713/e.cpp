#include <bits/stdc++.h>

using namespace std;

int sum(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}

vector<int> construct(int s, int n, int cnt) {
    vector<int> p;
    int sm = 0;
    for (int i = 1; i <= cnt; i++) {
        p.push_back(i);
        sm += i;
    }
    for (int i = cnt - 1; i >= 0; i--) {
        int mx_inc = (n - p[i]);
        int demand = s - sm;
        if (demand == 0) break;
        int inc = min(mx_inc, demand);
        p[i] += inc;
        sm += inc;
        n--;
    }
    return p;
}

void print(vector<int> a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int cnt = r - l + 1;
        int mn = sum(1, cnt);
        int mx = sum(n - cnt + 1, n);
        if (s < mn || s > mx) {
            cout << -1 << "\n";
        } else {
            set<int> st;
            for (int i = 1; i <= n; i++) {
                st.insert(i);
            }
            vector<int> part = construct(s, n, cnt);
            for (int i = 0; i < part.size(); i++) {
                st.erase(part[i]);
            }
            vector<int> ans;
            for (int i = 1; i < l; i++) {
                ans.push_back(*st.begin());
                st.erase(st.begin());
            }
            for (int i = 0; i < part.size(); i++) {
                ans.push_back(part[i]);
            }
            for (int i = r + 1; i <= n; i++) {
                ans.push_back(*st.begin());
                st.erase(st.begin());
            }
            print(ans);
        }
    }
    return 0;
}
