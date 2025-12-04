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
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    if (n == 0) {
    	cout << 0 << endl;
    	return;
    }
    if (m == 1) {
    	cout << n % MOD << endl;
    } else if (m == 2) {
    	vi v;
    	ll x = n;
    	while (x) {
    		v.push_back(x % 2);
    		x /= 2;
    	}
    	int sz = v.size();
    	vector<pair<mi, mi>> dp(sz + 1);
    	vector<pair<mi, mi>> split(sz + 1);
    	dp[0] = {1, v[0]};
    	for (int i = 1; i < sz; i++) {
    		if (v[i-1] == 0) {
    			auto [t0, u0] = split[i - 1];
    			auto [tt, uu] = dp[i - 1];
    			u0 += t0 * (1ll << (i - 1));
    			split[i] = {t0 + tt, u0 + uu};
    		} else {
    			split[i] = split[i - 1];
    		}

    		if (v[i] == 0) {
    			dp[i] = dp[i-1];
    		} else {
    			auto [a, b] = dp[i-1];
    			auto [c, d] = split[i];
    			dp[i] = {a + c, b + d + a * (1ll << i)};
    		}
    	}
    	cout << (int) dp[sz-1].second << endl;
    } else if (n % 2 == 0) {
    	mi A = 2 + n;
    	mi B = n / 2;
    	cout << (int) ((A * B) * inv(2)) << endl;
    } else {
    	mi A = 1 + n;
    	mi B = n / 2 + 1;
    	cout << (int) ((A * B) * inv(2)) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
