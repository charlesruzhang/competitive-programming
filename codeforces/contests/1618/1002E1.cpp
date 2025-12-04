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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m)), b(n, vi(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> b[i][j];
    	}
    }
    int idx = 0;
    int tot = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int now = 0;
    	for (int j = 0; j < m; j++) {
    		if (b[i][j] != a[idx / m][idx % m]) {
    			if (j > tot) {
    				cout << ans + (n - i) * m << endl;
    				return;
    			}
    			tot++;
    		} else {
    			idx++;
    		}
    	}
    	ans += now;
    }
    cout << tot << endl;
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
