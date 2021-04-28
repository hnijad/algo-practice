#include <bits/stdc++.h>

using namespace std;

const int MAX = 200001;

int main() {
    int a,b;
    cin >> a >> b;
    int res = -1;
    for(int g = MAX - 1; g >= 0; g--) {
        int cnt = 0;
        for(int j = g; j < MAX; j+= g) {
            if(j >= a && j <= b){
                ++cnt;
            }
        }
        if(cnt > 1) {
            cout << g << "\n";
            return 0;
        }
    }
    return 0;
}