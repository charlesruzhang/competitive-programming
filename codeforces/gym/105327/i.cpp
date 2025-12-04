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
const ll MOD = 1e9+7;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
vi primes;
vi pvec;
vi lp;
vi mu;
const int maxN = 1e6+1;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    lp.assign(maxN, 1e6+1);
    lp[1] = 0;
    primes[0] = primes[1] = 0;
    mu[1] = 1;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                lp[j] = min(lp[j], i);
                if ((j / i) % i == 0) {
                    mu[j] = 0;
                }
                mu[j] *= -1;
            }
            lp[i] = i;
            mu[i] = -1;
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<mi> p2(n+1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
    	p2[i] = 2 * p2[i-1];
    }
    vi cnt(1e6 + 1);
    for (int i = 0; i < n; i++) {
    	int cur = a[i];
    	vi v;
    	while (cur > 1) {
    		int z = lp[cur];
    		while (cur % z == 0) {
    			cur /= z;
    		}
    		v.push_back(z);
    	}
    	for (int j = 0; j < (1 << v.size()); j++) {
    		int x = 1;
    		for (int k = 0; k < v.size(); k++) {
    			if ((1 << k) & j) {
    				x *= v[k];
    			}
    		}
    		cnt[x]++;
    	}
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int y;
    	cin >> y;
    	int cur = y;
    	vi v;
    	while (cur > 1) {
    		int z = lp[cur];
    		while (cur % z == 0) {
    			cur /= z;
    		}
    		v.push_back(z);
    	}
    	int ans = 0;
    	for (int j = 0; j < (1 << v.size()); j++) {
    		int x = 1;
    		for (int k = 0; k < v.size(); k++) {
    			if ((1 << k) & j) {
    				x *= v[k];
    			}
    		}
    		ans += mu[x] * cnt[x];
    	}
    	cout << (int) p2[ans] << endl;
    }
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
