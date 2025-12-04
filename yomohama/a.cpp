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
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
    	cin >> vs[i];
    }
    vvl dp(n, vl(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (vs[i][j] == 'Y') {
    			dp[i][j] = 1;
    		}
    	}
    }
    ll ans = 0;
    vector<char> vc = {'Y', 'O', 'K', 'O', 'H', 'A', 'M', 'A'};
    
    for (int k = 1; k < 8; k++) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
	    		if (vs[i][j] == vc[k]) {
	    			dp[i][j] = 0;
	    			if (i && vs[i-1][j] == vc[k-1]) {
	    				dp[i][j] += dp[i-1][j];
	    			}
	    			if (j && vs[i][j-1] == vc[k-1]) {
	    				dp[i][j] += dp[i][j-1];
	    			}
	    			if (i != n - 1 && vs[i+1][j] == vc[k-1]) {
	    				dp[i][j] += dp[i+1][j];
	    			}
	    			if (j != m - 1 && vs[i][j+1] == vc[k-1]) {
	    				dp[i][j] += dp[i][j+1];
	    			}
	    			if (k == 7) {
	    				ans += dp[i][j];
	    			}
	    			//cout << k << " " << dp[i][j] << endl;
	    		}
    		}
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
