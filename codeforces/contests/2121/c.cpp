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
    vvi a(n, vi(m));
    int maxx =0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m ;j ++) {
    		cin >> a[i][j];
    		maxx = max(maxx, a[i][j]);
    	}
    }
    vi r(n), c(m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m ; j++) {
    		if (a[i][j] == maxx) {
    			r[i]++;
    			c[j]++;
    			cnt++;
    		}
    	}
    }
    int f = -1;
    int g = -1;
    for (int i = 0; i < n; i++) {
    	if (r[i] >= 2) {
    		if (f != -1) { 
    			cout << maxx << endl;
    			return;
    		}
    		f = i;
    	}
    }
    for (int i = 0; i < m; i++) {
    	if (c[i] >= 2) {
    		if (g != -1) { 
    			cout << maxx << endl;
    			return;
    		}
    		g = i;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m ; j++) {
    		if (a[i][j] == maxx && i != f && j != g) {
    			if (f == -1) {
    				f = i;
    				continue;
    			}
    			if (g == -1) {
    				g = j;
    				continue;
    			}
    			cout << maxx << endl;
    			return;
    		}
    	}
    }
    cout << maxx - 1 << endl;
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
