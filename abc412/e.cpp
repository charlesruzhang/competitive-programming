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
vi primes;
vi pvec;
const int maxN = 1e7;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
                primes[j] = 0;
            }
        }
    }
    pvec.clear();
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
}
void solve() {
    ll L, R;
    cin >> L >> R;
    vl v(R - L);
    vi cnt(R - L);
    for (ll i = L + 1; i <= R; i++) {
    	v[i - L - 1] = i;
    }
    for (int p : pvec) {
    	ll z = 1ll * (L / p + 1) * p;
    	for (ll i = z; i <= R; i += p) {
    		while (v[i - L - 1] % p == 0) {
    			v[i - L - 1] /= p;
    		}
    		cnt[i - L - 1]++;
    	}
    }
    int tot = R - L + 1;

    for (ll i = L + 1; i <= R; i++) {
    	if (cnt[i - L - 1] >= 2 || (cnt[i - L - 1] == 1 && v[i - L - 1] > 1)) {
    		tot--;
    	}
    }
    cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
