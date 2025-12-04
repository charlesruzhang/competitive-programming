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
    vvi dp(6, vi(6));
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[0][1] = 2;
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 6; j++) {
    		if (i + j <= 1) continue;
    		for (int k = 0; k <= i; k++) {
    			for (int l = 0; l <= j; l++) {
    				if (k != i || l != j) dp[i][j] += dp[k][l]; 
    			}
    		}
    		cout << i << " " << j << " " << dp[i][j] << endl;
    	}
    }

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
