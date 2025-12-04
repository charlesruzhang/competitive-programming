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
    int n, k;
    cin >> n >> k;
    vi w(n);
    vi c(n);
    for (int i = 0; i < n; i++) {
    	cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi mark(n);
    vector<set<int>> vs(n);
    function <void(int, int)> dfs3 = [&] (int u, int p) {
    	vector<pii> vec;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs3(v, u);
    			vec.push_back({vs[v].size(), v});
    		}
    	}
    	if (vec.size() == 0) {
    		if (c[u]) vs[u].insert(c[u]);
    	} else {
    		sort(vec.begin(), vec.end(), greater<>());
    		swap(vs[vec[0].second], vs[u]);
    		if (c[u]) vs[u].insert(c[u]);
    		for (int v: e[u]) {
    			if (v != p) {
    				auto it = vs[v].begin();
    				while (it != vs[v].end()) {
    					auto x = *it;
    					if (vs[u].find(x) != vs[u].end() && x != c[u]) {
    						if (c[u] == 0) {
    							c[u] = x;
    						} else {
    							mark[u] = 1;
    						}
    					} else {
    						vs[u].insert(x);
    					}
    					++it;
    				}
    			}
    		}
    		if (c[u] == 0 && vs[u].size()) {
    			c[u] = *(vs[u].begin());
    		}
    	}
    };
    dfs3(0, -1);
    function <void(int, int)> dfs4 = [&] (int u, int p) {
    	for (int v : e[u]) {
    		if (v != p) {
    			if (c[v] == 0) {
    				c[v] = c[u];
    			}
    			dfs4(v, u);
    		}
    	}
    };
    if (c[0] == 0) {
    	c[0] = 1;
    }
    dfs4(0, -1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (mark[i]) {
    		ans += w[i];
    	}
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
    	cout << c[i] << " ";
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
