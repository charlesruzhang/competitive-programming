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
	    vi w(n);
	    for (int i = 0; i < n; i++) {
	    	cin >> w[i];
	    }
	    for (int i = 0; i < n-1; i++) {
	    	int x, y;
	    	cin >> x >> y;
	    	x--; y--;
	    	e[x].push_back(y);
	    	e[y].push_back(x);
	    }
	    vi p(n, -1);
	    int ans = 1;
	    vector<set<int>> ret(n);
		vi xo(n);
	    function <void(int)> dfs = [&](int u) {
	    	map<int, int> ma;
	    	if (e[u].size() == 1 && u) {
		    	ret[u].insert(0);
		    	ans++;
		    }
	    	for (int v : e[u]) {
	    		if (p[u] != v) {
	    			p[v] = u;
	    			dfs(v);
	    			if (ret[u].size() < ret[v].size()) {
	    				swap(ret[u], ret[v]);
	    				swap(xo[u], xo[v]);
	    			}
	    			for (int res: ret[v]) {
	    				res ^= xo[u] ^ xo[v];
	    				if (ret[u].find(res) == ret[u].end()) {
	    					ret[u].insert(res);
	    				} else {
	    					ma[res ^ xo[u]]++;
	    				}
	    			}
	    		}
	    	}
	    	if (!ma.empty()) {
	    		int maxx = 0;
	    		for (auto[_, v]: ma) {
	    			maxx = max(maxx, v);
	    		}
	    		ret[u].clear();
	    		xo[u] = w[u];
	    		for (auto [x, v]: ma) {
	    			if (v == maxx) {
	    				ret[u].insert(x);
	    			}
	    		}
		    	ans-=maxx;
		    } else {
		    	xo[u] ^= w[u];
		    }
		    
	    };
	    dfs(0);
	    for (int x : ret[0]) {
	    	if (x == xo[0]) {
	    		ans--;
	    		break;
	    	}
	    }
	    cout << ans << endl;
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
