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
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi diameter(n);
    vector<pii> pai(n);
    vi depth(n);
    vi par(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	int maxx = 0;
    	int ix = -1, ix2 = -1;
    	par[u] = p;
    	int max2 = 0;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    			if (depth[v] > maxx) {
    				max2 = maxx;
    				ix2 = ix;
    				maxx = depth[v];
    				ix = v;
    			} else if (depth[v] > max2) {
    				max2 = depth[v];
    				ix2 = v;
    			}
    		}
    	}
    	diameter[u] = maxx + max2 + 1;
    	pai[u] = {ix, ix2};
    	depth[u] = maxx + 1;
    };
    dfs(0, -1);
    int ans = 0;
    int idx = -1;
    for (int i = 0; i < n; i++) {
    	if (ans < diameter[i]) {
    		ans = diameter[i];
    		idx = i;
    	}
    	//cout << i << "!" << diameter[i] << " " << depth[i] << endl;
    }
    //cout << ans << " ? " << idx << endl;
    if (ans == n) {
    	cout << -1 << endl;
    	return;
    }
    if (idx != 0) {
    	assert(pai[idx].first != -1 && pai[idx].second != -1);
    	cout << pai[idx].first + 1 << " " << idx + 1 << " " << par[idx] + 1 << endl;
    } else {
    	if (e[0].size() >= 3) {
    		for (int v : e[0]) {
    			if (v != pai[0].first && v != pai[0].second) {
    				cout << pai[0].first + 1 << " "  << 1 << " " << v + 1 << endl;
    				return;
    			}
    		}
    	} else {
    		array<int, 3> res;
    		function <void(int)> dfs2 = [&] (int u) {
    			for (int v : e[u]) {
    				if (v != par[u] && v != pai[u].first) {
    					res = {par[u], u, v};
    					return;
    				}
    			}
    			if (pai[u].first != -1) dfs2(pai[u].first);
    		};
    		dfs2(pai[0].first);
    		if (pai[0].second != -1) dfs2(pai[0].second);
    		cout << res[0] + 1 << " " << res[1] + 1 << " " << res[2] + 1 << endl;
    		return;
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
