#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n + 2);
        map<ll, int> mp;
        ll sm = 0;
        set<int> st;
        for (int i = 0; i < n + 2; i++) {
            cin >> b[i];
            mp[b[i]]++;
            st.insert(b[i]);
            sm += b[i];
        }
        bool ok = false;
        for (int i = 0; i < n + 2; i++) {
            ll rm_sum = sm - b[i];
            if(rm_sum % 2 == 0) {
                mp[b[i]]--;
                rm_sum /= 2;
                if(mp[rm_sum] > 0) {
                    ok = true;
                    mp[rm_sum]--;
                    break;
                }
                mp[b[i]]++;
            }
        }
        if (ok) {
            for (auto x : mp) {
                for (int j = 0; j < x.second; j++) {
                    cout << x.first << " ";
                }
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
