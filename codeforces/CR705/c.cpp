#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 26;

int getNeed(int n, int k) {
    int mult = (n + k - 1) / k;
    return mult * k - n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(ALPHA);
        for (int i = 0; i < n; i++) {
            ++cnt[s[i] - 'a'];
        }
        if ((n % k) != 0) {
            cout << -1 << "\n";
        } else {
            bool ok = true;
            for (int i = 0; i < ALPHA; i++) {
                if ((cnt[i] % k) != 0) {
                    ok = false;
                }
            }

            auto calculateForAlpa = [&](int alpha, int pos) -> bool {
                //cout << alpha << " " << pos << endl;
                ++cnt[alpha];
                int needs = 0;
                int sum = 0;
                for (int j = 0; j < ALPHA; j++) {
                    needs += getNeed(cnt[j], k);
                }
                //cout << i << " " << req << " " << req + i << "\n";
                if (needs < n - pos) {
                    for (int j = ALPHA - 1; j >= 0; j--) {
                        int need = getNeed(cnt[j], k);
                        cnt[j] += need;
                        sum += cnt[j];
                    }

                    cnt[0] += (n - pos - 1) - needs;
                    return true;
                }
                --cnt[alpha];
                return false;
            };

            if (ok) {
                cout << s << "\n";
            } else {
                int pos = -1;
                int alp = -1;
                for (int i = n - 1; i >= 0; i--) {
                    --cnt[s[i] - 'a'];
                    for (int alpha = s[i] - 'a' + 1; alpha < ALPHA; alpha++) {
                        if (calculateForAlpa(alpha, i)) {
                            alp = alpha;
                            pos = i;
                            break;
                        }
                    }
                    if (pos != -1) break;
                }
                string ans = "";
                for (int i = 0; i < pos; i++) {
                    ans.push_back(s[i]);
                    --cnt[s[i] - 'a'];
                }
                ans.push_back('a' + alp);
                --cnt[alp];
                for (int i = 0; i < ALPHA; i++) {
                    for (int j = 0; j < cnt[i]; j++) {
                        ans.push_back(i + 'a');
                    }
                }
                //assert(ans.size() <= n);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}