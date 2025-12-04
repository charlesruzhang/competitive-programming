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
void solve() {
    int n, m;
    cin >> n >> m;
    vvi p(n, vi(n+1));
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	p[x][y] = 1;
    }
    vector<vector<mi>> dp(n+1, vector<mi>(n+1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
    	mi summ = 0;
    	for (int z = 0; z <= n; z++) {
    		summ += dp[i][z];
    	}
    	for (int j = 1; j <= n - i; j ++) {
    		if (p[i][j]) continue;
    		for (int k = j; k <= n - i; k++) {
    			int flag = 1;
    			for (int l = i; l < i + k; l++) {
    				int target = j + l - i;
    				if (target > k) target -= k;
    				if (p[l][target]) {
    					flag = 0;
    					break;
    				}
    			}
    			if (flag) {
    				int dest = j - 1;
    				if (dest == 0) dest += k;
    				if (j == 1) dp[i + k][dest] += summ;
    				else dp[i+k][0] += summ;
    				if (j > 1) dp[i+k][0] -= dp[i][j-1];
    				//cout << "??" << endl;
    			}
    		}
    	}
    }
    mi ans = 0;
    for (int i = 0; i <= n; i++) {
    	ans += dp[n][i];
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
