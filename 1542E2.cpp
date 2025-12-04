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
ll MOD = 998244353;
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
    int n, M;
    cin >> n >> M;
    MOD = M;
    vector<mi> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
    	fact[i] = fact[i-1] * (n - i + 1);
    }
    mi ans = 0;
    vector<mi> dp(n * n + 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
    	vector<mi> pref(n * n + 2);
    	for (int k = 0; k <= n * n; k++) {
    		pref[k + 1] = pref[k] + dp[k];
    	}
    	vector<mi> ndp(n * n + 1);
    	for (int k = 0; k <= i * (i - 1) / 2; k++) {
    		ndp[k] = pref[k + 1] - pref[max(k - i + 1, 0)];
    	}
    	swap(ndp, dp);
    	int I = i * (i - 1) / 2;
    	vector<mi> pref2(I + 2), pref3(I + 2);
	    for (int j = 0; j <= I; j++) {
	        pref[j + 1] = pref[j] + dp[j];
	        pref2[j + 1] = pref2[j] + pref[j + 1];
	        pref3[j + 1] = pref3[j] + j * pref[j + 1];
	    }

	    mi S = 0;
	    for (int j = 2; j <= I; j++) {
	        int L = max(0, j - i - 1);
	        int R = j - 2;
	        mi sumP = pref2[R + 1] - pref2[L];
	        mi sumtP = pref3[R + 1] - pref3[L];
	        S += dp[j] * ((i - j + 2) * sumP + sumtP);
	    }

	    ans += fact[n - i - 1] * S;
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
