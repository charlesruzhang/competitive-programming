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
const int LOG = 20;
vi parent;
vi depth;
vl summ;
vvi up;

void preprocess(int n, vector<vector<pii>> &adj, int root = 0) {
    parent.resize(n);
    depth.resize(n);
    summ.assign(n, 0);
    up.assign(n, vector<int>(LOG, -1));

    function<void(int, int)> dfs = [&](int v, int p) {
        parent[v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        up[v][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto [u, w] : adj[v]) {
            if (u != p) {
        		summ[u] = summ[v] + w;
            	dfs(u, v);
        	}
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
    int n, m;
    cin >> n >> m;
    DSU D(n);
    vi vec;
    vector<vector<pii>> e(n);
    vector<array<int, 3>> f;
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	if (D.find(u) == D.find(v)) {
    		vec.push_back(u);
    		f.push_back({u, v, w});
    	} else {
    		e[u].push_back({v, w});
    		e[v].push_back({u, w});
    		D.unite(u, v);
    	}
    }

    preprocess(n, e);
    for (auto [u, v, w] : f) {
    	e[v].push_back({u, w});
    	e[u].push_back({v, w});
    }
    int z = vec.size();
    vvl x(z, vl(n, MAXX));
    for (int i = 0; i < z; i++) {
    	priority_queue<pll, vector<pll>, greater<>> pq;
    	x[i][vec[i]] = 0;
    	pq.push({0, vec[i]});
    	vi done(n);
    	while (!pq.empty()) {
    		auto [dist, u] = pq.top();
    		pq.pop();
    		if (done[u]) continue;
    		done[u] = 1;
    		for (auto [v, w] : e[u]) {
    			if (x[i][v] > x[i][u] + w) {
    				x[i][v] = x[i][u] + w;
    				pq.push({x[i][v], v});
    			}
    		}
    	}
    }
    int Q; 
    cin >> Q;
    for (int i = 0; i < Q; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	int y = lca(u, v);
    	ll minn = summ[u] - 2 * summ[y] + summ[v];
    	for (int j = 0; j < z; j++) {
    		minn = min(minn, x[j][u] + x[j][v]);
    	}
    	cout << minn << endl;
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
