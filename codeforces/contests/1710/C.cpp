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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<mi>> dp(n+1, vector<mi>(64));
    for (int i = 0; i < 64; i+=8) {
    	dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < 8; j++) {
    		for (int k = 0; k < 8; k++) {
    			int flag = 1;
    			for (int t = 0; t < 3; t++) {
    				int x = ((j & (1 << t)) >= 1) ? 1 : 0;
    				int y = ((k & (1 << t)) >= 1) ? 1 : 0;
    				if (x && y && s[n - i] == '0') {
    					flag = 0;
    					break;
    				}
    			}
    			if (!flag) continue;
    			int one = -1, zero = -1;
    			int summ = 0;
    			int ss = j;
    			for (int t = 0; t < 3; t++) {
    				int y = ((k & (1 << t)) >= 1) ? 1 : 0;
    				if (y != s[n - i] - '0') {
    					ss &= 7 - (1 << t);
    				}
    				one = (y) ? t : one;
    				zero = (!y) ? t : zero;
    				summ += y;
    			}
    			if (summ == 3) {
    				for (int z = 0; z < 8; z++) {
    					dp[i][j * 8 + z] += dp[i-1][ss * 8 + z];
    				}
    			} else if (summ == 2) {
    				for (int z = 0; z < 8; z++) {
    					if (z & (1 << zero)) {
    						dp[i][j * 8 + z] += dp[i-1][ss * 8 + z];
    						dp[i][j * 8 + z] += dp[i-1][ss * 8 + (z ^ (1 << zero))];
    					}
    				}
    			} else if (summ == 1) {
    				for (int z = 0; z < 8; z++) {
    					if (z & (1 << one)) {
    						dp[i][j * 8 + z] += dp[i-1][ss * 8 + z];
    						dp[i][j * 8 + z] += dp[i-1][ss * 8 + (z ^ (1 << one))];
    					}
    				}
    			} else {
    				for (int z = 0; z < 8; z++) {
    					dp[i][j * 8 + z] += dp[i-1][ss * 8 + z];
    				}
    			}

    		}
    	}
    }
    cout << (int) dp[n][63] << endl;
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
