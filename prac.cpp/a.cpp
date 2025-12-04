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
    vvi c = a;
    vvi d = b;
    auto print1 = [&](int z) {
    	if (z) {
    		cout << "Possible" << endl;
    	} else {
    		cout << "Impossible" << endl;
    	}
    };
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		c[i][j] = min(a[i][j], b[i][j]);
    		if (i && c[i][j] <= c[i-1][j]) {
    			print1(0);
    			return;
    		}
    		if (j && c[i][j] <= c[i][j-1]) {
    			print1(0);
    			return;
    		}
    		d[i][j] = max(a[i][j], b[i][j]);
    		if (i && d[i][j] <= d[i-1][j]) {
    			print1(0);
    			return;
    		}
    		if (j && d[i][j] <= d[i][j-1]) {
    			print1(0);
    			return;
    		}
    	}
    }
    print1(1);
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
