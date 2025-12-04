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
    	cout << 3 << endl;
    	return;
    }

    ll ans = 0;
    vvi dp(n+1, vi(1 << n));
    dp[1][0] = 1;
    dp[1][1] = 2;
    int dir = (n % 2) ? 1 : 0;
    for (int i = 2; i <= n; i++) {
    	for (int j = 0; j < (1 << i); j++) {
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
    		if (i == n) {
    			ans += dp[i][j];
    		}
    	}

    }
    cout << ans << endl;
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
