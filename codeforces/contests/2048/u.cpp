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
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    }
    vvl dp(n, vl(3, 1e18));
    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = 2 * b[0];
    for (int i = 1; i < n; i++) {
    	for (int j = 0; j < 3; j++) {
    		for (int k = 0; k < 3; k++) {
    			if (a[i-1] + j != a[i] + k) {
    				dp[i][k] = min(dp[i][k], dp[i-1][j] + 1ll * k * b[i]);
    			}
    		}
    	}
    }
    cout << min(min(dp[n-1][1], dp[n-1][0]), dp[n-1][2]) << "\n";
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
