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
void solve(int t) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    mi ans = 0;
    int sq = floor(sqrt(100000));
    vector<mi> dp(sq); // cnt = i;
    vector<mi> dp2(sq); // val = i;
    for (int i = 0; i < n; i++) {
    	vector<mi> ndp(sq);
    	for (int j = 0; j < sq; j++) {
    		int nmaxx = a[i] / (j + 1);
    		if (!nmaxx) continue;
    		int cnt = (i == 0) ? 0 : ((a[i - 1] - 1) / nmaxx);
    		if (cnt >= sq) {
    			ndp[j] = dp2[nmaxx-1] + mi(i+1) * j;
    		} else {
    			ndp[j] = dp[cnt] + mi(i + 1) * j;
    		}
    	}
    	swap(dp, ndp);
    	vector<mi> ndp2(sq);
    	for (int j = 0; j < sq; j++) {
    		if (a[i] % (j + 1) == 0) ndp2[j] = dp2[j] + mi(i + 1) * (a[i] / (j+1) - 1);
    		else {
    			assert (j != 0);
    			int cnt = (a[i] - 1) / (j+1) + 1;
    			ndp2[j] = dp2[a[i] / cnt - 1] + mi(i + 1) * (cnt - 1);
    		}
    	}
    	swap(dp2, ndp2);
    	ans += dp[0];
    }
    cout << (int) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}
