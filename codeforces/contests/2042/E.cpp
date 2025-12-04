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
    n *= 2;
    vi val(n);
    vvi p(n / 2 + 1);
    for (int i = 0; i < n; i++) {
    	cin >> val[i];
    	p[val[i]].push_back(i);
    }
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[v].push_back(u);
    	e[u].push_back(v);
    }
    vi sz(n, 1);
    function <void(int, int)> dfs = [&] (int u, int par) {
    	for (int v: e[u]) {
    		if (v != par) {
    			dfs(v, u);
    			sz[u] += sz[v];
    		}
    	}
    };
    dfs(0, -1);
    int root = -1;
    function <void(int, int)> dfs2 = [&] (int u, int par) {
    	int flag = 1;
    	for (int v : e[u]) {
    		if (v != par && sz[v] * 2 > n) {
    			flag = 0;
    			dfs2(v, u);
    		}
    	}
    	if (flag) root = u;
    };
    dfs2(0, -1);
    //cout << "root = " << root + 1 << endl;
    preprocess(n, e, root);
    vi mark(n);
    vector<set<int>> vs(n);
    for (int i = 0; i < n; i++) {
    	vs[i].insert(val[i]);
    }
    function <void(int, int)> dfs3 = [&] (int u, int par) {
    	int maxx = 1;
    	int idx = u;
    	for (int v: e[u]) {
    		if (v != par) {
    			dfs3(v, u);
    			if (mark[v]) mark[u] = 1;
    			if (vs[v].size() > maxx) {
    				maxx = vs[v].size();
    				idx = v;
    			}
    		}
    	}
    	if (mark[u]) return;
    	swap(vs[idx], vs[u]);
    	for (int v : e[u]) {
    		if (v != par) {
    			auto it = vs[v].begin();
    			while (it != vs[v].end()) {
    				if (vs[u].find(*it) != vs[u].end()) {
    					mark[u] = 1;
    					return;
    				}
    				vs[u].insert(*it);
    				++it;
    			}
    		}
    	}
    };
    dfs3(root, -1);
    // for (int i = 0; i < n; i++) {
    // 	cout << mark[i];
    // }
    // cout << endl;
    vi visited(n);
    for (int i = n - 1; i >= 0; i--) {
    	if (i == root && mark[i]) {
    		int fll = 0;
    		for (int v : e[i]) {
    			if (sz[v] == n / 2 && !mark[v]) {
    				vi nmark(n);
    				int err = 0;
    				function <void(int, int)> dfs4 = [&] (int u, int par) {
    					nmark[u] = 1;
    					if (u > i) err = 1;
    					for (int vp: e[u]) {
    						if (vp != par) dfs4(vp, u);
    					};
    				};
    				dfs4(v, i);
    				if (!err) {
	    				swap(nmark, mark);
	    				fll = 1;
 	    				break;
	    			}
    			}
    		}
    		if (fll) break;
    	}
    	if (mark[i]) continue;
    	else {
    		if (vs[i].size() != sz[i]) {
    			set<int> ns;
    			function <void(int, int)> dfs5 = [&] (int u, int p) {
    				ns.insert(val[u]);
    				visited[u] = 1;
    				for (int v : e[u]) {
    					if (v != p) {
    						if (!visited[v]) dfs5(v, u);
    					}
    				}
    			};
    			dfs5(i, parent[i]);
    			swap(ns, vs[i]);
    		}
    		auto it = vs[i].begin();
    		while (it != vs[i].end()) {
    			int z = *it;
    			int f = p[z][0];
    			int s = p[z][1];
    			int ff = lca(i, f);
    			int ss = lca(i, s);
    			assert(ff == i || ss == i);
    			assert(ff != i || ss != i);
    			int cur = 0;
    			if (ff == i) {
    				cur = s;
    			} else {
    				cur = f;
    			}
    			while (!mark[cur]) {
    				mark[cur] = 1;
    				cur = parent[cur];
    			}
    			++it;
    		}
    	}
    }
    int summ = accumulate(mark.begin(), mark.end(), 0);
    cout << summ << endl;
    for (int i = 0; i < n; i++) {
    	if (mark[i]) cout << i + 1 << " ";
    }
    cout << endl;
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
	