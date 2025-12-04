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
    int m, s, t;
    cin >> m >> s >> t;
    int cur = 0;
    ll tot = 0;
    while (cur < t && m >= 10) {
    	m -= 10;
    	tot += 60;
    	cur++;
    	if (tot >= s) {
    		cout << "Yes" << endl;
    		cout << cur << endl;
    		return;
    	}
    }
    if (cur >= t && tot < s) {
    	cout << "No" << endl;
    	cout << tot << endl;
    	return;
    }
    t -= cur;
    m /= 2;
    vvi dp(t + 1, vi(10, -INF));
    dp[0][m] = tot;
    for (int i = 1; i <= t; i++) {
    	for (int j = 0; j < 10; j++) {
    		if (j >= 2) dp[i][j] = max(dp[i - 1][j - 2], dp[i][j]);
    		if (j < 5) dp[i][j] = max(dp[i - 1][j + 5] + 60, dp[i][j]);
    		dp[i][j] = max(dp[i][j], dp[i - 1][j] + 17);
    		if (dp[i][j] >= s) {
    			cout << "Yes" << endl;
    			cout << i + cur << endl;
    			return;
    		}
    	}
    }
    cout << "No" << endl;
    int maxx = 0;
    for (int i = 0; i < 10; i++) {
    	maxx = max(maxx, dp[t][i]);
    }
    cout << maxx << endl;
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
