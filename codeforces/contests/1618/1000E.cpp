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
    vector<map<int,pii>> val(n);
    int cur = 0;
    vi depth(n, -1);
    function <void(int, int)> prep = [&] (int u, int p) {
    	depth[u] = cur;
    	for (int v : e[u]) {
    		if (v != p) {
    			cur++;
    			prep(v, u);
    			cur--;
    		}
    	}
    };
    prep(0, -1);
    ll tot = 0;
    function <void(int, int)> dfs = [&] (int u, int p) {
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    		}
    	}
    	int sz = 0;
    	int idx = -1;
    	for (int v : e[u]) {
    		if (v != p) {
    			if (sz < val[v].size()) {
    				sz = val[v].size();
    				idx = v;
    			}
    		}
    	}
    	if (idx == -1) {
    		val[u][depth[u]] = {1, 1};
    	} else {
    		swap(val[idx], val[u]);
    		for (int v : e[u]) {
    			if (v != p && v != idx) {
    				auto it = val[v].lower_bound(depth[u] + 1);
    				while (it != val[v].end()) {
    					int idx = it -> first;
    					auto [x , y] = it -> second;
    					int zz = idx - depth[u];
    					auto it2 = val[u].find(idx);
    					assert(it2 != val[u].end());
    					auto [z, w] = it2 -> second;
    					tot += 1ll * (2 * zz - 1) * x * w;
    					tot += 1ll * (2 * zz - 1) * y * z;
    					tot -= 1ll * (2 * zz - 1) * x * z;
    					(it2 -> second).first += x;
    					(it2 -> second).second += y;
    					++it;
    				}
    			}
    		}
    		val[u][depth[u]] = {1, val[u][depth[u] + 1].second + 1};
    	}
    };
    dfs(0, -1);
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
