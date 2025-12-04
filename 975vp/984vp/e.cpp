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
    int n, k, q;
    cin >> n >> k >> q;
    vvi a(n, vi(k));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < k; j++) {
    		cin >> a[i][j];
    	}
    }
    vvi pref(n+1, vi(k+1));
    for (int j = 0; j < k; j++) {
    	for (int i = 0; i < n; i++) {
    		pref[i+1][j] = pref[i][j] | a[i][j];
    	}
    }
    while (q--) {
    	int m;
    	cin >> m;
    	int l = 0;
    	int r = n-1;
    	int done = 0;
    	for (int i = 0; i < m; i++) {
    		int j, v;
    		string c;
    		cin >> j >> c >> v;
    		j--;
    		int ll = l;
    		int rr = r;
    		if (c == ">" && pref[rr+1][j] <= v) {
    			done = 1;
    			continue;
    		}

    		if (c == "<" && pref[ll+1][j] >= v) {
    			done = 1;
    			continue;
    		}
    		if (c == ">" && pref[ll+1][j] > v) {
    			continue;
    		}
    		if (c == "<" && pref[rr+1][j] < v) {
    			continue;
    		}
    		while (ll < rr) {
    			if (c == "<") {
    				int mm = (ll + rr + 1)  / 2;
    				if (pref[mm+1][j] < v) {
    					ll = mm;
    				} else {
    					rr = mm - 1;
    				}
    			} else {
    				int mm = (ll + rr)  / 2;
    				if (pref[mm+1][j] > v) {
    					rr = mm;
    				} else {
    					ll = mm + 1;
    				}
    			}
    		}
    		if (c == "<") r = ll;
    		else l = ll;
    	}
    	if (!done) cout << l + 1 << endl;
        else cout << -1 << endl;
    }
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
