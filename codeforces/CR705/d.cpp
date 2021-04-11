#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX = 2 * 100001;
const int MOD = 1000000007;

vector<int> primes;

void generatePrimes() {
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < MAX; j += i) {
            isPrime[j] = false;
        }
        primes.push_back(i);
    }
}

int power(int a, int n) {
    if (n == 0) return 1;
    int q = power(a, n >> 1);
    q = 1ll * q * q % MOD;
    if (n & 1) q = 1ll * q * a % MOD;
    return q;
}

//map<int, int> mp[MAX];  // compare it with vector
//multiset<int> ms[MAX];

vector<map<int,int>> mp(MAX);
vector<multiset<int>> ms(MAX);

ll ans = 1;
int n;

void addPrime(int pos, int prime, int cnt) {
    if (cnt == 0) return;
    int cur = mp[pos][prime];
    mp[pos][prime] += cnt;

    int mn = 0;
    if (ms[prime].size() == n) mn = *ms[prime].begin();

    if (cur != 0) ms[prime].erase(ms[prime].find(cur));

    ms[prime].insert(cur + cnt);

    if (ms[prime].size() == n) ans = 1ll * ans * power(prime, *ms[prime].begin() - mn) % MOD;
}

void add(int pos, int x) {
    while (x != 1) {
        for (int prime : primes) {
            if (prime * prime > x) break;
            int cnt = 0;
            while ((x % prime) == 0) {
                x /= prime;
                ++cnt;
            }
            addPrime(pos, prime, cnt);
        }
        if (x != 1) {
            addPrime(pos, x, 1);
            x = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    generatePrimes();
    int t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(i, x);
    }
    while (t--) {
        int pos, x;
        cin >> pos >> x;
        --pos;
        add(pos, x);
        cout << ans << "\n";
    }
    return 0;
}