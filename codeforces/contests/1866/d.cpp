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
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(m, vi(n));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[j][i];
    	}
    }
    for (int i = 0; i < m; i++) {
    	sort(a[i].begin(), a[i].end(), greater<>());
    }
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		a[i][j] = ((j) ? a[i][j-1] : 0) + a[i][j];  
    	}
    }
    vvl dp(m+1, vl(k+1));
    for (int i = k - 1; i < m; i++) {
    	for (int j = min(i, k - 1); j >= 0; j--) {
    		dp[i+1][j] = dp[i+1][j+1];
    		for (int z = 1; z <= min(i - k + 2, min(j + 1, n)); z++) {
    			dp[i+1][j] = max(dp[i+1][j], dp[i+1-z][j + 1 - z] + a[i - j][z - 1]);
    		}
    		//if (i + 1 < k) dp[i+1][j] = 0;
    		//cout << i << " " << j << " " << dp[i+1][j] << endl;
    	}
    }
    cout << dp[m][0] << endl;
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
