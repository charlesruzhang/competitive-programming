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
int maxM = 1e4+5;
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
void comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
}
void solve() {
    
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    ll n;
    int k;
    cin >> n >> k;
    function <int(ll)> bit = [&](ll n) {
    	if (n == 0) {
    		return 0;
    	}
    	return 64 - __builtin_clzll(n);
    };
    map<pair<ll, int>, mi> dp;
    function <mi(ll, int)> g = [&] (ll n, int k) {
    	//cout << n << " , " << k << endl;
    	if (k == 0) return mi(1);
    	int x = bit(n);
    	if (!x) return mi(0);
    	if (dp.find({n, k}) != dp.end()) {
    		return dp[{n, k}];
    	}
    	mi ans = 0;
    	ans += g(n - (1ll << (x - 1)), k - 1);
    	ans += g((1ll << (x - 1)) - 1, k);
    	return dp[{n, k}] = ans;
    };
    function <mi(ll, int)> f = [&] (ll n, int k) {
    	//cout << n << " " << k << endl;
    	if (k == 0) return mi(0);
    	int x = bit(n);
    	if (!x) return mi(0);
    	mi tot = 0;
    	tot += mi((1ll << (x - 1)) - 1) * ncr(x - 2, k - 1);
    	tot += f(n - (1ll << (x - 1)), k - 1);
    	tot += mi(1ll << (x - 1)) * g(n - (1ll << (x - 1)), k - 1);
    	return tot; 
    };
    cout << (int) f(n, k) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
