#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout <<  max(0, (y * z + x - 1) / x  - 1) << endl;
    return 0;
}