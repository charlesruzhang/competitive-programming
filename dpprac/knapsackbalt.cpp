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
    int n;
    vi m(3);
    cin >> n;
    for (int i = 0; i < 3; i++) {
    	cin >> m[i];
    }
    vvi dp(3, vi(n + 1));
    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < m[i]; j++) {
    		int cost, boost;
    		cin >> cost >> boost;
    		for (int k = n; k >= cost; k--) {
    			dp[i][k] = max(dp[i][k], dp[i][k - cost] + boost);
    		}
    	}
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; i + j <= n; j++) {
    		ans = max(ans, 1ll * dp[0][i] * dp[1][j] * dp[2][n - i - j]);
    	}
    }
    cout << ans << endl;
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
