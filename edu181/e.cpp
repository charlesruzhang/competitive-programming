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
void solve() {
    int n, x;
    cin >> n >> x;
    if (n == 1) {
    	cout << x << endl;
    	return;
    }
    if (1ll * (n - 1) * (n - 2) / 2 > (x + 2 - 2 * n)) {
    	cout << 0 << endl;
    	return;
    }
    vector<vector<mi>> dp(n, vector<mi>(x + 1)); // max = i;
    dp[0][0] = 1;
    for (int i = 1; i <= n - 1; i++) {
    	for (int j = i; j <= x; j++) {
    		dp[i][j] = dp[i][j - i] + dp[i-1][j - i];
    	}
    }
    int maxx = x - 2 * n + 2;
    mi ans = 0;
    for (int i = 0; i <= maxx; i++) {
    	mi tot = 0;
    	for (int j = n - 2; j <= n - 1; j++) {
    		tot += dp[j][i];
    	}
    	ans += (maxx - i + 1) * tot;
    }
    cout << (int) ans << endl;
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
