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
    vector<vector<mi>> p(n, vector<mi>(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		int x;
    		cin >> x;
    		p[i][j] = x;
    	}
    }
    vector<vector<mi>> q(n, vector<mi>(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		int x;
    		cin >> x;
    		q[i][j] = x;
    	}
    }
    vector<vector<mi>> pref2(n + 1, vector<mi>(m + 1));
    vector<vector<mi>> pref(n + 1, vector<mi>(m + 1));
    for (int j = 0; j < m; j++) {	
    	for (int i = 0; i < n; i++) {
    		pref2[i+1][j] = pref2[i][j] + q[i][j];
    	}
    }
    for (int j = 0; j < m; j++) {	
    	for (int i = 0; i < n; i++) {
    		pref[i][j+1] = pref[i][j] + p[i][j];
    	}
    }
    mi ans = 2;
    for (int i = 1; i < n; i++ ) {
    	for (int j = 1; j < m; j++) {
    		ans += pref[i-1][j-1] * pref2[i-1][j-1] * (1 - pref[i][j-1]) * (1 - pref2[i-1][j]);
    	}
    }
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
