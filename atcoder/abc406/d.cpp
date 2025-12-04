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
    int h, w, n;
    cin >> h >> w >> n;
    vector<pii> a(n);
    vector<vector<pii>> r(h+1);
    vector<vector<pii>> c(w+1);
    vi rr(h+1);
    vi cc(w+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    	r[a[i].first].push_back({a[i].second, i});
    	c[a[i].second].push_back({a[i].first, i});
    }
    int q;
    cin >> q;
    vi mark(n);
    while (q--) {
    	int x, d;
    	cin >> x >> d;
    	int tot = 0;
    	if (x == 1) {
    		if (rr[d]) {
    			cout << 0 << endl;
    			continue;
    		}
    		for (int i = 0; i < r[d].size(); i++) {
    			auto [z, y] = r[d][i];
    			if (!mark[y]) {
    				tot++;
    				mark[y] = 1;
    			}
    		}
    		cout << tot << endl;
    		rr[d] = 1;
    	} else {
			if (cc[d]) {
    			cout << 0 << endl;
    			continue;
    		}
    		for (int i = 0; i < c[d].size(); i++) {
    			auto [z, y] = c[d][i];
    			if (!mark[y]) {
    				tot++;
    				mark[y] = 1;
    			}
    		}
    		cout << tot << endl;
    		cc[d] = 1;
    	}
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
