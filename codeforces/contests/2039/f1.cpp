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
int N = 1e5 + 1;
vvi facts(N + 1);
vi primes;
vi pvec;
vi mu, mu2;
const int maxN = 1e5+1;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    mu2.assign(maxN, 1);
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
void comp() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j+=i) {
			facts[j].push_back(i);
		}
	}
}
void solve() {
    int n;
    cin >> n;
    vector<vector<mi>> pref(n + 1);
    vector<vector<mi>> P(n + 1);
    mi R = 1;
    pref[1].push_back(1);
    P[1].push_back(1);
    for (int i = 2; i <= n; i++) {
    	// ans[i] += ans[i - 1];
    	// for (int x: facts[i]) {
    	// 	if (x != i) ans[i] += 2 * ans[x];
    	// }
    	// ans[i]+=1;
    	// cout << "ans[" << i << "] = " << (int) ans[i] << endl; 
    	int sz = facts[i].size();
    	vector<mi> res(sz);
    	for (int j = 0; j < sz; j++) {
    		mi tot = 0;
    		mi off = 0;
    		int x = facts[i][j];
    		// compute F(i, facts[j]);
    		for (int k = 0; k <= j; k++) {
    			if (facts[i][j] % facts[i][k] == 0) {
    				int y = facts[i][k];
    				tot += (pref[y].size() ? pref[y].back() : 0);
    				if (k != j) off -= res[k];
    			}
    		}
    		//mi tmp = 2 * tot + 1;
    		tot -= P[x].size() ? P[x].back() : 0;
    		P[x].push_back({(P[x].size() ? P[x].back() : 0) + 2 * tot + 1});
    		res[j] = 2 * tot + 1 + off;
    		//if (x == i) R += 2 * tot + 1;
    		// cout << "i = " << i << ", x = " << x << ", res = " << (int) res[j] << endl;
    		// cout << (int) tot << " " << (int) off << endl;
    		// cout << endl;
    	}
    	for (int j = 0; j < sz; j++) {
    		int x = facts[i][j];
    		pref[x].push_back((pref[x].size() ? pref[x].back() + res[j] : res[j]));
    		R += res[j];
    	}
    }
    cout << (int) R << endl;
} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
