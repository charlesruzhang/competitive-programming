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
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
     void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
	int n;
    cin >> n;
    vector<vvi> a(n, vvi(n, vi(n)));
    DSU D(n * n);
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
	    	D.unite(i * n + j, j * n + i);
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		string s;
    		cin >> s;
    		for (int k = 0; k < n; k++) {
    			a[i][j][k] = s[k] - '0';
    			a[j][i][k] = s[k] - '0';
    			if (a[i][j][k]) {
    				D.unite(i * n + k, j * n + k);
    			} 
    		}
    	}
    }
    vvi V(n * n);
    for (int i = 0; i < n * n; i++) {
    	V[D.find(i)].push_back(i);
	}
	for (int i = 0; i < n * n; i++) {
	    if (V[i].size() != 2 * n - 2) continue;
	    vvi E(n);
	    DSU d2(n);
	    vector<pii> ans;
	    for (int x: V[i]) {
	    	int u = x / n;
	    	int v = x % n;
	    	E[u].push_back(v);
	    	if (u < v) ans.push_back({u, v});
	    	d2.unite(u, v);
	    }
	    if (d2.size[d2.find(0)] != n) {
	    	continue;
	    }
		preprocess(n, E);
		int err = 0;
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
			continue;
		}
		cout << "Yes" << endl;
		for (int i = 0; i < n - 1; i++) {
			auto [x, y] = ans[i];
			cout << x + 1 << " " << y + 1 << endl;
		}
		return;
	}
	cout << "No" << endl;
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
