// Problem Link: https://codeforces.com/contest/1213/problem/D1

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int f(int a, int b) {
    int k = 0;
    while (true) {
        if (a == b) return k;
        if (a < b) return -1;
        a /= 2;
        k++;
    }
    return k;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;

    for (int i = 0; i < MAX; i++) {
        int temp = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int res = f(a[j], i);
            if (res != -1) {
                temp += res;
                ++cnt;
            }
            if (cnt == k) {
                ans = min(ans, temp);
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}