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
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vi mark(n);
    for (int i = 0; i < k ;i++) {
    	int x;
    	cin >> x;
    	x--;
    	mark[x] = 1;
    }
    if (m == 1) {
    	cout << 1 << endl;
    	return;
    }
    if (n == 1) {
    	cout << (1ll * m * (m + 1) / 2) % MOD << endl;
    	return;
    }
    vector<mi> dp2(n+1);
    for (int i = 2; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp2[j] += powMod(m - i + 1, j) * powMod(i - 1, n - j);
        }
    }
    mi ans = powMod(m, n);
    vvi dp(n+1, vi(1 << n));
    dp[1][0] = 1;
    dp[1][1] = 2;
    int dir = (n % 2) ? 1 : 0;
    for (int i = 2; i <= n; i++) {
    	for (int j = 0; j < (1 << i); j++) {
            int x = __builtin_popcount(j);
    		if ((i + dir) % 2 == 1) {
    			dp[i][j] = 2;
    		} else {
    			dp[i][j] = 1;
    		}
    		int tot = 0;
    		for (int t = 0; t < i; t++) {
    			int ptot = tot;
    			if (j & (1 << t)) {
    				tot |= (1 << t);
    			}
    			if (mark[t]) {
    				int x = (((j - tot) >> 1) + ptot);
    				if ((i + dir) % 2 == 1) {
    					dp[i][j] = min(dp[i][j], dp[i-1][x]);
    				} else {
    					dp[i][j] = max(dp[i][j], dp[i-1][x]);
    				}
    			}
    		}
            if (i == n && dp[i][j] == 2) {
                ans += dp2[x];
            }
    	}
    }
    cout << (int)ans << endl;
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
