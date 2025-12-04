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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(4));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 4; j++) {
    		cin >> a[i][j];
    	}
    	a[i][0]--;
    	a[i][1]--;
    	swap(a[i][0], a[i][1]);
    }
    sort(a.begin(), a.end());
    mi ans = 1;
    for (int i = 0; i < n; i++) {
    	ans *= (1 - a[i][2] * inv(a[i][3]));
    }
    vector<mi> dp(m+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
    	int l = a[i][1];
    	int r = a[i][0];
    	int p = a[i][2];
    	int q = a[i][3];
    	dp[r + 1] += dp[l] * (p * inv(q - p));
    	//cout << r + 1 << " " << l << endl;
    }
    ans *= dp[m];
    cout << (int) ans << endl;
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
