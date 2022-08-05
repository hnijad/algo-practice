// Problem Link: https://codeforces.com/contest/1272/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    b[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            b[i] = b[i - 1] + 1;
        } else {
            b[i] = 1;
        }
        ans = max(ans, b[i]);
    }
    c[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            c[i] = c[i + 1];
        } else {
            c[i] = b[i];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i + 1] && a[i] > a[i - 1] ) continue; 
        if (a[i - 1] < a[i + 1]) {
            ans = max(ans, b[i - 1] + c[i + 1] -  (a[i] < a[i + 1]) );
        }       
    }
    cout << ans << "\n";
    return 0;
}