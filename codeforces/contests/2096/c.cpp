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
void solve() {
    int n;
    cin >> n;
    vvi h(n, vi(n));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> h[i][j];
    	}
    }
    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> y[i];
    }
    vvl dp(n, vl(2, MAXX));
    dp[0][0] = 0;
    dp[0][1] = y[0];
    ll ans = 0;
    for (int j = 1; j < n; j++) {
    	vector<int> xx(3);
    	for (int i = 0; i < n; i++) {
    		if (abs(h[i][j] - h[i][j-1]) <= 1) {
    			xx[h[i][j] - h[i][j-1] + 1]++;
    		}
    	}
    	if (!xx[1]) {
    		dp[j][0] = min(dp[j][0], dp[j-1][0]);
    		if (min(dp[j][1], dp[j-1][1]) != MAXX) dp[j][1] = min(dp[j][1], dp[j-1][1] + y[j]) ;
    	}
    	if (!xx[2]) {
    		dp[j][0] = min(dp[j][0], dp[j-1][1]);
    	}
    	if (!xx[0]) {
    		if (min(dp[j][1], dp[j-1][0]) != MAXX) dp[j][1] = min(dp[j][1], dp[j-1][0] + y[j]) ;
    	}
    }
    ans = min(dp[n-1][0], dp[n-1][1]);
    if (ans == MAXX) {
    	cout << -1 << endl;
    	return;
    }
    vvl dp2(n, vl(2, MAXX));

    dp2[0][0] = 0;
    dp2[0][1] = x[0];
    for (int j = 1; j < n; j++) {
    	vector<int> xx(3);
    	for (int i = 0; i < n; i++) {
    		if (abs(h[j][i] - h[j-1][i]) <= 1) {
    			xx[h[j][i] - h[j-1][i] + 1]++;
    		}
    	}
    	//cout << xx[0] << " " << xx[1] << " " << xx[2] << " " << j << endl;
    	if (!xx[1]) {
    		dp2[j][0] = min(dp2[j][0], dp2[j-1][0]);
    		if (min(dp2[j][1], dp2[j-1][1]) != MAXX) dp2[j][1] = min(dp2[j][1], dp2[j-1][1]  + x[j]);
    	}
    	if (!xx[2]) {
    		dp2[j][0] = min(dp2[j][0], dp2[j-1][1]);
    	}
    	if (!xx[0]) {
    		if (min(dp2[j][1], dp2[j-1][0]) != MAXX) dp2[j][1] = min(dp2[j][1], dp2[j-1][0]  + x[j]);
    	}
    }

    ans += min(dp2[n-1][0], dp2[n-1][1]);
    if (min(dp2[n-1][0], dp2[n-1][1]) == MAXX) {
    	cout << -1 << endl;
    	return;
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
