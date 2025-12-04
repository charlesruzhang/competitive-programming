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
    int n;
    cin >> n;
    if (n == 1) {
    	cout << 1 << endl;
    	return;
    }
    if (n == 2) {
    	cout << 2 << endl;
    	return;
    }
    if (n == 3) {
    	cout << 6 << endl;
    	return;
    }
    // if (n == 4) {
    // 	cout << 16 << endl;
    // 	return;
    // }
    // vvi facts(n+1);
    // for (int i = n; i >= 3; i--) {
    // 	for (int j = i; j <= n; j+=i) {
    // 		facts[j].push_back(i);
    // 	}
    // }
    mi ans = 2 * n;
    vector<mi> dp(n+1, 1);
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 3; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            dp[j] += dp[i];
            dp[j + 1] += dp[i];
            dp[j - 1] += dp[i];
        }
        if (i != 3)
        dp[i + 1] += dp[i];
    	// for (int v: facts[i+1]) {
    	// 	if (v != i + 1) dp[i] += dp[v];
    	// }
    	// for (int v: facts[i]) {
    	// 	if (v != i) dp[i] += dp[v];
    	// }
    	// for (int v: facts[i-1]) {
    	// 	dp[i] += dp[v];
    	// }
    	//if (i <= 100) cout << i << " " << (int) dp[i] << endl; 
        // printf("%d %d\n",i,  dp[i].v);
    }
    mi summ = 1;
    for (int i = 3; i < n; i++) {
    	summ += dp[i];
    }
    cout << (int) (2 * n * summ) << endl;
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
