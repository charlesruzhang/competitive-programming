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
const int LOG = 20;
vi parent;
vi depth;
vvi up;

void preprocess(int n, vvi &adj, int root = 0) {
    parent.resize(n);
    depth.resize(n);
    up.assign(n, vector<int>(LOG, -1));

    function<void(int, int)> dfs = [&](int v, int p) {
        parent[v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        up[v][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : adj[v]) {
            if (u != p) dfs(u, v);
        }
    };

    dfs(root, -1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if (diff & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}

void solve() {
    int n;
    cin >> n;
    vector<vvi> a(n, vvi(n, vi(n)));
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		string s;
    		cin >> s;
    		for (int k = 0; k < n; k++) {
    			a[i][j][k] = s[k] - '0';
    			a[j][i][k] = s[k] - '0';
    		}
    	}
    }
    // return if dist(x, z) == dist(y, z);
    auto C = [&] (int x, int y, int z) {
    	return a[x][y][z];
    };
    int err = 0;
    vector<pii> ans;
    function <void(vi&)> F = [&] (vi& e) {
    	if (!e.size()) {
    		err = 5;
    		return;
    	}
    	if (e.size() == 1) {
    		return;
    	}
    	if (e.size() == 2) {
    		ans.push_back({e[0], e[1]});
    		return;
    	}
    	int n = e.size();
    	vi tar;
	    for (int i = 0; i < n; i++) {
	    	for (int j = i + 1; j < n; j++) {
	    		for (int k = j + 1; k < n; k++) {
	    			if (C(e[i], e[j], e[k]) && C(e[i], e[k], e[j])) {
	    				tar = {e[i], e[j], e[k]};
	    				break;
	    			}
	    		}
	    		if (tar.size()) break;
	    	}
	    	if (tar.size()) break;
	    }
	    if (!tar.size()) {
	    	// should be a line.
	    	vi cnt(n);
	    	for (int i = 0; i < n; i++) {
	    		int flag = 0;
		    	for (int j = 0; j < n; j++) {
		    		for (int k = j + 1; k < n; k++) {
		    			if (j == i || k == i) continue;
		    			if (C(e[j], e[k], e[i])) {
		    				cnt[i]++;
		    				break;
		    			}
		    		}
		    	}
		    }
		    int flag3 = 0;
		    vi L;
		    for (int i = 0; i < n; i++) {
		    	if (!cnt[i]) {
		    		for (int j = 0; j < n; j++) {
		    			if (cnt[j] == 1) {
		    				int p1 = -1, p2 = -1;
		    				vi in(n);
		    				for (int k = 0; k < n; k++) {
		    					if (k == i || k == j) continue;
		    					if (C(e[i], e[k], e[j])) {
		    						flag3 = 1;
		    						L.push_back(i);
		    						L.push_back(j);
		    						L.push_back(k);
		    						p1 = j;
		    						p2 = k;
		    						in[i] = in[j] = in[k] = 1;
		    						break;
		    					}
		    				}
		    				if (flag3) {
		    					while (L.size() < n) {
		    						int done = 0;
		    						for (int k = 0; k < n; k++) {
		    							if (in[k]) continue;
		    							if (C(e[p1], e[k], e[p2])) {
		    								L.push_back(k);
		    								p1 = p2, p2 = k;
		    								in[k] = 1;
		    								done = 1;
		    								break;
		    							}
		    						}
		    						if (!done) {
		    							err = 8;
		    							return;
		    						}
		    					}
		    					for (int i = 1; i < n; i++) {
		    						ans.push_back({e[L[i-1]], e[L[i]]});
		    					}
		    					return;
		    				}
		    			}
		    		}
		    	}
		    }
		    if (!flag3) {
		    	err = 7;
		    	return;
		    }
	    } else {
	    	int x = tar[0];
	    	int y = tar[1];
	    	int z = tar[2];
	    	int cent = -1;
	    	for (int i = 0; i < n; i++) {
	    		if (C(x, y, e[i]) && C(y, z, e[i])) {
	    			cent = e[i];
	    			break;
	    		}
	    	}
	    	if (cent == -1) {
	    		err = 1;
	    		return;
	    	}
	    	for (int i = 0; i < n; i++) {
	    		if (e[i] == x || e[i] == y || e[i] == z) continue;
	    		if (C(x, e[i], cent)) {
	    			tar.push_back(e[i]);
	    		}
	    	}
	    	int sz = tar.size();
	    	vvi f(sz);
	    	for (int i = 0; i < n; i++) {
	    		if (e[i] == cent) continue;
	    		set<int> bad;
	    		for (int j = 0; j < sz; j++) {
	    			for (int k = j + 1; k < sz; k++) {
	    				if (!C(tar[j], tar[k], e[i])) {
	    					if (!bad.size()) {
	    						bad.insert(j);
	    						bad.insert(k);
	    					} else {
	    						if (bad.find(j) == bad.end() && bad.find(k) == bad.end()) {
	    							err = 2;
	    							return;
	    						}
	    						set<int> tmp;
	    						for (int x : bad) {
	    							if (x == j || x == k) {
	    								tmp.insert(x);
	    							}
	    						}
	    						swap(tmp, bad);
	    						if (bad.size() == 0) {
	    							err = 3;
	    							return;
	    						}
	    					}
	    				}
	    			}
	    		}
	    		assert(bad.size() == 1);
	    		int bd = *bad.begin();
	    		f[bd].push_back(e[i]);
	    	}
	    	for (int i = 0; i < sz; i++) {
	    		ans.push_back({cent, tar[i]});
	    		F(f[i]);
	    	}
	    }
	};
	vi e;
	for (int i = 0; i < n; i++) {
		e.push_back(i);
	}
	F(e);
	vvi E(n);
	if (err) {
		cout << "No" << endl;
		return;
	}
	assert(ans.size() == n - 1);
	for (auto [u, v] : ans) {
		E[u].push_back(v);
		E[v].push_back(u);
	}
	preprocess(n, E);
	for (int i = 0; i < n; i++) {
		if (err) break;
		for (int j = i + 1; j < n; j++) {
			if (err) break;
			for (int k = 0; k < n; k++) {
				int w = lca(i, k);
				int d1 = depth[i] + depth[k] - 2 * depth[w];
				int x = lca(j, k);
				int d2 = depth[j] + depth[k] - 2 * depth[x];
				if ((d1 == d2) != a[i][j][k]) {
					err = 4;
					break;
				}
			}
		}
	}
	if (err) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n - 1; i++) {
		auto [x, y] = ans[i];
		cout << x + 1 << " " << y + 1 << endl;
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
