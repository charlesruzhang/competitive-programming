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
    vi a(n);
    vi v(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	v[a[i]] = i+1;
    }
    vvl dp(n+2, vl(n / 2 + 1));
    for (int i = n; i >= 1; i--) {
    	for (int j = 0; j <= min(n / 2, n - i); j++) {
    		int k = n - i - j;
    		if (!v[i] || v[i] % 2 == 1) {
    			dp[i][j] = max(dp[i][j], dp[i+1][j] + i * (j + (n + 1) / 2 - k));
    		}
    		if ((j+1 <= n / 2) && (!v[i] || v[i] % 2 == 0)) {
    			dp[i][j+1] = max(dp[i][j+1], dp[i+1][j] + i * (k + n / 2 - j));
    		}
    	}
    }
    cout << dp[1][n/2] << endl;
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
