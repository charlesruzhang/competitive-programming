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
    vi len(n);
    vi depth(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
		int maxx = 0;
		for (int v : e[u]) {
			if (v != p) {
				depth[v] = depth[u] + 1;
				dfs(v, u);
				maxx = max(maxx, len[v]);
			}
		}				    
		len[u] = 1 + maxx;	
    };
    dfs(0, -1);
    vi h(n, 0);
    function <void(int, int)> dfs2 = [&] (int u, int p) {
    	vector<pii> vec;
    	for (int v: e[u]) {
    		if (v != p) {
    			vec.push_back({len[v], v});
    		}
    	}
    	sort(vec.begin(), vec.end(), greater<>());
    	for (int i = 0; i < vec.size(); i++) {
    		auto [val, v] = vec[i];
    		if (!i) {
    			h[v] = h[u];
    		} else {
    			h[v] = v;
    		}
    		dfs2(v, u);
    	}
    };

    vi v1(n), v2(n);
    function <void(int, int) > dfs3 = [&] (int u, int p) {
    	int max1 = 0;
    	int max2 = 0;
    	for (int v : e[u]) {
    		if (v == p) continue;
    		dfs3(v, u);
    		if (h[v] != h[u]) {
    			v1[u] = max(v1[u], len[u] - 1 + len[v]);
    		} else {
    			v1[u] = max(v1[u], v1[v]);
    		}
    		max2 = max(max2, v2[v]);
    	}
    	v2[u] = 1 + max2;
    };
    dfs2(0, -1);
    dfs3(0, -1);
    int q;
    cin >> q;
    while (q--) {
    	int v, k;
    	cin >> v >> k;
    	v--;
    	int u = h[v];
    	int ans = min(k, len[v]);
    	int diff = depth[v] - depth[u];
    	ans = max(ans, min(k + diff, v1[u] - len[v]));
    	if (u != 0) ans = max(ans, min(k + depth[v], v2[0] - len[v]));
    	cout << ans << " ";
    }
    cout << endl;
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
