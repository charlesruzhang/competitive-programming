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
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl dp(n+1);
    vl dp2(n+1);
    int flag = 1;
    for (int i = n - 1; i >= 0; i --) {
    	if (i != n - 1) {
    		dp[i] = min(dp2[i+1] + a[i] - 1, dp[i + 2] + a[i] + max(a[i+1] - i - 1, 0));
    		dp[i] = min(dp[i], max(0ll, dp2[i+2] - 1) + a[i] + max(a[i+1] - i - 1, 0));
    		dp[i] = min(dp[i], dp[i+1] + a[i]);
    		dp2[i] = min(dp[i+1] + a[i], a[i] + dp2[i+1] - 1);
    	} else {
    		dp[i] = a[i];
    		dp2[i] = a[i];
    	}
    	//cout << i << " " << dp[i] << endl;
    }
    cout << dp[0] << endl;
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
