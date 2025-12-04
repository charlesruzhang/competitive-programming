// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;
vi primes;
vi pvec;
vi lp;
const int maxN = 1e7+5;
void sieve() {
    primes.assign(maxN, 1);
    pvec.assign(maxN, 1);
    lp.assign(maxN, INF);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 1; i < maxN; i++) {
    	lp[i] = i;
    }
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
        		lp[j] = min(lp[j], i);
                primes[j] = 0;
            }
            lp[i] = i;
        }
    }
    pvec.clear();
    int timer = 1;
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec[i] = timer++;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 1) {
    		cur ^= 1;
            cout << 1 << endl;
    	} else {
    		int x = lp[a[i]];
    		if (x == 2) {
    			cout << 0 << endl;
    			continue;
    		}
    		cur ^= pvec[x];
            cout << pvec[x] << endl;
    	}
    }
    cout << (cur ? "Alice" : "Bob") << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
