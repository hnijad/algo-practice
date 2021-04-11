#include <bits/stdc++.h>

using namespace std;

int getReverse(int a){
    if(a == 0) return 0;
    if(a == 1) return 1;
    if(a == 2) return 5;
    if(a == 5) return 2;
    if(a == 8) return 8;
    return -1;
}

bool isValid(int n, int x) {
    int a = n % 10;
    int b = n / 10;
    if ((a == 0 || a == 1 || a == 2 || a == 5 || a == 8) &&
        (b == 0 || b == 1 || b == 2 || b == 5 || b == 8) ) {
         if((10 * getReverse(a) + getReverse(b)) < x) return true;
    }
    return false;
}

void printTime(int hh, int mm) {
    string tm = "";
    tm.push_back(hh / 10 + '0');
    tm.push_back(hh % 10 + '0');
    tm.push_back(':');
    tm.push_back(mm / 10 + '0');
    tm.push_back(mm % 10 + '0');
    cout << tm << "\n";
}

void solve() {
    int h, m;
    cin >> h >> m;
    int hh, mm;
    char ch;
    cin >> hh >> ch >> mm;

    while (true) {
        if (isValid(hh, m) && isValid(mm, h)) {
            printTime(hh, mm);
            return;
        }
        mm = (mm + 1) % m;
        hh = (hh + (mm == 0)) % h;
    }
    cout << (1 / 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}