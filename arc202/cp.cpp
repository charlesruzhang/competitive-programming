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
vi mu;
const int maxN = 2e5+1;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    mu[1] = 1;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                if ((j / i) % i == 0) {
                    mu[j] = 0;
                }
                mu[j] *= -1;
            }
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
    vector<mi> p(2e5+1);
    p[0] = 0;
    for (int i = 1; i <= 2e5; i++) {
    	p[i] = p[i-1] * 10 + 1;
    }
    vector<mi> ip(2e5+1);
    for (int i = 1; i <= 2e5; i++) {
    	ip[i] = inv(p[i]);
    }
    vvi v(2e5 + 1);
    for (int i = 1; i <= 2e5; i++) {
    	for (int j = 1; j * j <= i; j++) {
    		if (i % j == 0) {
    			v[i].push_back(j);
    			if (j * j != i) v[i].push_back(i / j);
    		}
    	}
    	sort(v[i].begin(), v[i].end(), greater<>());
    }
    mi ans = 1;
    vector<int> mark(2e5 + 1);
    for (int i = 0; i < n; i++) {
    	//ans *= p[a[i]];
    	for (int j = 0; j < v[a[i]].size(); j++) {
    		int tar = v[a[i]][j];
    		if (!mark[tar]) {
    			for (int k = 0; k < v[tar].size(); k++) {
    				int x = v[tar][k];
    				if (mu[tar / x] == 1) {
    					ans *= p[x];
    				} else if (mu[tar / x] == -1) {
    					ans *= ip[x];
    				}
    			}
    		}
    		mark[tar] = 1;
    	}
    	cout << (int) ans << endl;
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
