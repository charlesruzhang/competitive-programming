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
    int n;
    cin >> n;
    vector<vector<pii>> e(n);
    for (int i = 0; i < n; i++) {
    	int s;
    	cin >> s;
    	for (int j = 0; j < s; j++) {
    		int v, w;
    		cin >> v >> w;
    		v--;
    		e[i].push_back({v, w});
    	}
    }
    vi visited(n);
    vector<mi> dp(n);
    vector<mi> ones(n);
    vector<mi> zeros(n);
    function <void(int)> dfs = [&] (int u) {
    	visited[u] = 1;
    	for (auto [v, w] : e[u]) {
    		if (w) {
    			ones[u] += 1;
    		} else {
    			zeros[u] += 1;
    			dp[u] += ones[u];
    		}
    		if (!visited[v]) {
    			dfs(v);
    		}
			dp[u] += dp[v];
			dp[u] += ones[u] * zeros[v];
			ones[u] += ones[v];
			zeros[u] += zeros[v];
    	}
    };
    dfs(0);
    cout << (int) dp[0] << endl;
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
