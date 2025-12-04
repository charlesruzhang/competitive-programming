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
void solve() {
	int maxM = 1e6+5;
    vector<mi> fact(maxM);
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    vector<mi> ifact(maxM);
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n;
    cin >> n;
    int cnt = 31 - __builtin_clz(n);
    mi T = 0;
    if ((1 << (cnt - 1)) * 3 <= n) {
    	for (int i = 0; i < cnt; i++) {
    		// The ith division is 3.
    		mi res = 1;
    		int tot = n - 1;
    		int prev = (1 << (cnt - 1)) * 3;
    		for (int j = cnt - 1; j >= 0; j--) {
    			int now = (j + i == cnt - 1) ? (prev / 3) : (prev / 2);
				int y = n / now - n / prev;
				res *= ncr(tot - 1, y - 1) * fact[y - 1] * y;
				tot -= y;
				prev = now;
    		}
    		T += res;
    	}
    } 
	mi ans = 1;
	int tot = n - 1;
	for (int i = cnt - 1; i >= 0; i--) {
		int now = 1 << i;
		int prev = 1 << (i + 1);
		int y = n / now - n / prev;
		ans *= ncr(tot - 1, y - 1) * fact[y - 1] * y;
		tot -= y;
	}
	T += ans;
	cout << (int) T << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
