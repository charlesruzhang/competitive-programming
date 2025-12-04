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
    up.assign(n, vector<int>(LOG, INF));

    function<void(int, int)> dfs = [&](int v, int p) {
        parent[v] = p;
        depth[v] = (p == INF) ? 0 : depth[p] + 1;
        up[v][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != INF)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : adj[v]) {
            if (u != p) dfs(u, v);
        }
    };

    dfs(root, INF);
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
    int n, z;
    cin >> n >> z;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi r(n);
    int j = 0;
    vvi e(n+1);
    for (int i = 0; i < n; i++) {
    	while (j < n && a[j] - a[i] <= z) {
    		j++;
    	}
    	r[i] = j;
    	e[i].push_back(j);
    	e[j].push_back(i);
    }
    preprocess(n + 1, e, n);
    vi dp(n+1, 1);
	
    vvi up2(n+1, vi(LOG, INF));
    vvi val(n+1, vi(LOG));
    for (int i = n - 1; i >= 0; i--) {
    	int v = lca(i, i + 1);
    	up2[i][0] = v;
    	val[i][0] = depth[i] + depth[i+1] - 2 * depth[v];
    }
    for (int i = 1; i < LOG; i++) {
    	for (int j = 0; j <= n; j++) {
            if (up2[j][i - 1] != INF) {
    			up2[j][i] = up2[up2[j][i-1]][i-1];
    			val[j][i] = val[j][i-1] + val[up2[j][i-1]][i-1];
    		}
    	}
    }
    int q;
    cin >> q;
    vector<vector<array<int , 2>>> qrs(n+1);
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int cur = l;
    	int tot = 0;
    	for (int j = LOG - 1; j >= 0; j--) {
    		if (up2[cur][j] <= r) {
    			tot += val[cur][j];
    			cur = up2[cur][j];
    		}
    	}
    	int x = cur;
    	int y = cur + 1;
    	tot += (x <= r ? 1 : 0) + (y <= r ? 1 : 0);
    	for (int j = LOG - 1; j >= 0; j--) {
    		if (up[x][j] <= r) {
    			tot += (1 << j);
    			x = up[x][j];
    		}
    		if (up[y][j] <= r) {
    			tot += (1 << j);
    			y = up[y][j];
    		}
    	}
    	cout << tot << endl;
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
