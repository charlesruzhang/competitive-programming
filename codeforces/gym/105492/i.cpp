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
    int n, k;
    cin >> n >> k;
    vi t(n), f(n);
    vector<int> v(1e6+1, n-1);
    for (int i = 0; i < n; i++) {
    	cin >> t[i] >> f[i];
    }
    int idx = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
    	while (idx <= 1e6 && idx < t[i]) {
    		idx++;
    		v[idx] = i - 1;
    	}
    }
    vi p(k), d(k), c(k);
	for (int i = 0; i < k; i ++) {
		cin >> p[i] >> d[i] >> c[i];
	}   
	vl dp(n+1);
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dp[i+1] + f[i];
		for (int j = 0; j < k; j++) {
			int newt = t[i] + p[j];
			int x = (newt <= 1e6) ? v[newt] : n-1;
			int y = min(i + d[j], x+1);
			//cout << y << " " << x <<" " << i + d[j] << endl;
			dp[i] = min(dp[y] + c[j], dp[i]);
		}
	}
	cout << dp[0] << endl;
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
