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
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    preprocess(n, e);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	a--; b--;
    	int x = lca(a, b);
    	if (depth[a] - depth[x] >= c) {
    		int cur = a;
    		for (int i = LOG - 1; i >= 0; i--) {
    			if ((1 << i) & c) {
    				cur = up[cur][i];
    			}
    		}
    		cout << cur + 1 << endl;
    		continue;
    	}
    	c -= depth[a] - depth[x];
    	if (depth[b] - depth[x] >= c) {
    		int cur = b;
    		int y = depth[b] - depth[x] - c;
    		for (int i = LOG - 1; i >= 0; i--) {
    			if ((1 << i) & y) {
    				cur = up[cur][i];
    			}
    		} 
    		cout << cur + 1 << endl;
    		continue;
    	}
    	cout << b + 1 << endl;
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
