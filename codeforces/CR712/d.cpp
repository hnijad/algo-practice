#include <bits/stdc++.h>

using namespace std;

int ask() {
    int color;
    cin >> color;
    return color;
}

void tell(int b, int i, int j) {
    cout << b << " " << i << " " << j << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a, b;
    int A = -1;
    int B = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) & 1) {
                b.push_back({i + 1, j + 1});
            } else {
                a.push_back({i + 1, j + 1});
            }
        }
    }
    int turn = 0;
    while (true) {
        ++turn;
        int res = ask();
        set<int> choices = {1, 2, 3};
        choices.erase(res);
        if (A == -1 && turn == 1) {
            A = *choices.begin();
        }
        if (B == -1 && turn == 2) {
            if (*choices.begin() == A) {
                B = *choices.rbegin();
            } else {
                B = *choices.begin();
            }
        }
        if (A != res) {
            tell(A, a.back().first, a.back().second);
            a.pop_back();
        } else {
            tell(B, b.back().first, b.back().second);
            b.pop_back();
        }
        if (a.empty() || b.empty()) break;
    }
    if (a.empty()) {
        while (!b.empty()) {
            int res = ask();
            set<int> choices = {1, 2, 3};
            choices.erase(res);
            choices.erase(A);
            tell(*choices.begin(), b.back().first, b.back().second);
            b.pop_back();
        }
    } else {
        while (!a.empty()) {
            int res = ask();
            set<int> choices = {1, 2, 3};
            choices.erase(res);
            choices.erase(B);
            tell(*choices.begin(), a.back().first, a.back().second);
            a.pop_back();
        }
    }
    return 0;
}