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
    int n, h, m;
    cin >> n >> h >> m;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    }
    vi dp(m + 1, -1);
    dp[m] = h;
    for (int i = 0; i < n; i++) {
    	vi ndp(m + 1, -1);
    	for (int j = 0; j <= m; j++) {
    		if (dp[j] != -1) ndp[j] = dp[j] - a[i];
    		if (j + b[i] <= m && dp[j+b[i]] != -1) ndp[j] = max(ndp[j], dp[j + b[i]]); 
    	}
    	int flag = 0;
    	for (int j = 0; j <= m; j++) {
    		if (ndp[j] >= 0) {
    			flag = 1;
    			break;
    		}
    	}
    	if (!flag) {
    		cout << i << endl;
    		return;
    	}
    	swap(dp, ndp);
    }
    cout << n << endl;
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
