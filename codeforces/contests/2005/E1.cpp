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
    int l, n, m;
    cin >> l >> n >> m;
    vi a(l);
    for (int i = 0; i < l; i++) {
    	cin >> a[i];
    }
    vvi b(n, vi(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> b[i][j];
    	}
    }
    vvi dp(n+1, vi(m+1));
    for (int i = l - 1; i >= 0; i--) {
    	vvi ndp(n+1, vi(m+1));
    	vvi nndp(n+1, vi(m+1));
    	for (int j = n - 1; j >= 0; j--) {
    		for (int k = m - 1; k >= 0; k--) {
    			ndp[j][k] = ndp[j+1][k] | ndp[j][k+1] | dp[j+1][k+1];
    			if (a[i] == b[j][k]) {
    				nndp[j][k] = ~ndp[j][k];
    			}
    		}
    	}
    	swap(dp, nndp);
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (dp[i][j]) {
    			cout << "T" << endl;
    			return;
    		}
    	}
    }
    cout << "N" << endl;
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
