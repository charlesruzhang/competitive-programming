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
    int n, m, q;
    cin >> n >> m >> q;
    vvi c(n), p(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	p[v].push_back(u);
    	c[u].push_back(v);
    }
    vi full(n);
    vi empty(n, 1);
    vi red(n);
    for (int i = 0; i < q; i++) {
    	int x, u;
    	cin >> x >> u;
    	u--;
    	queue<int> q, r;
    	if (x == 1) {
    		red[u] = 1;
    		if (full[u] < c[u].size() || full[u] == 0) {
    			full[u] = c[u].size();
    			q.push(u);
    		}
    		if (empty[u]) {
    			r.push(u);
    			empty[u] = 0;
    		}
    	} else {
    		cout << ((full[u] < c[u].size() || (full[u] == 0 && !red[u])) ? "YES" : "NO") << endl; 
    	}
    	while (!q.empty() || !r.empty()) {
    		if (!q.empty()) {
    			int v = q.front();
	    		q.pop();
	    		for (int u : p[v]) {
	    			if (empty[u]) {
	    				empty[u] = 0;
	    				r.push(u);
	    			}
	    		}
    		}
    		if (!r.empty()) {
    			int v = r.front();
    			r.pop();
    			for (int u : p[v]) {
    				full[u]++;
    				if (full[u] == c[u].size()) {
    					q.push(u);
    				}
    			}
    		}
    	}
    }
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
