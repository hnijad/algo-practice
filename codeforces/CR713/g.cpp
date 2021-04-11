#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX = (int)(1e7) + 1;
const int INF = (int)(1e9);

vector<ll> div_sum(MAX,1);
vector<int> ans(MAX, INF);


void init() {
    div_sum[0] = 0;
    for(int i = 2; i  < MAX; i++) {
        for(int j = i; j < MAX; j += i){
            div_sum[j] += i;
        }
    }
}



int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL), cout.tie(NULL);
    init();
    
    for(int i = MAX - 1; i >= 0; i--) {
        if(div_sum[i] < MAX ){
            ans[div_sum[i]] = i;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int c; scanf("%d", &c);
        int res = ans[c];
        if(res == INF) res = -1;
        printf("%d\n", res);
    }
}
