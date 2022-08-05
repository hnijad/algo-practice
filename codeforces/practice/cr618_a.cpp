// Problem Link: https://codeforces.com/contest/1299/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int BIT_SIZE = 32;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(BIT_SIZE);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < BIT_SIZE; j++) {
            if (a[i] & (1 << j)) {
                cnt[j].push_back(i);
            }
        }
    }

    int index = 0;

    for (int i = BIT_SIZE - 1; i >= 0; i--) {
        if (cnt[i].size() == 1) {
            index = cnt[i][0];
            break;        
        }
    }

    swap(a[0], a[index]);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}