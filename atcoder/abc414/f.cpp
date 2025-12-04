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
    int n, k;
    cin >> n >> k;
    vvi e(n);
    vvi f(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    //preprocess(n, e);
    vi par(n, -1);
    vvi done(n, vi(k + 1));
    done[0][0] = 1;
    function <void(int)> df = [&] (int u) {
    	for (int v : e[u]) {
    		if (v !=  par[u]) {
    			par[v] = u;
    			df(v);
    		}
    	}
    };
    df(0);
    queue<pii> q;
    q.push({0, -1});
    vi vis(n);
    vis[0] = 1;
    function <void(int, int, int, int)> dfs = [&] (int u, int cur, int from, int noo) {
    	if (noo == -1) done[u][cur] = 1;
    	else done[u][cur] = noo + 2;
    	if (cur == 0 && !vis[u]) {
    		vis[u] = 1;
    		q.push({u, from});
    	}
    	for (int v : e[u]) {
    		if (v != par[u] && v != noo) {
    			if (cur >= 1 && done[v][cur - 1] == 0) dfs(v, cur - 1, from, -1);
    			else if (cur >= 2 && done[v][cur - 1] >= 2) {
    				int z = done[v][cur - 1];
    				done[v][cur-1] = 0;
    				if (done[dfs(z - 2, cur - 2, from, -1);
    			}
    		}
    	}
    	int v = u;
    	if (u == from) {
	    	for (int i = 0; i < cur; i++) {
	    		int prev = (i < cur - 1) ? v : -1;
	    		v = par[v];
	    		if (v == -1) break;
	    		if (!done[v][cur - i - 1]) dfs(v, cur - i - 1, from, prev);
	    		else if (cur - i - 2 >= 0 && done[v][cur - i - 1] >= 2) {
	    			if (done[v][cur - i - 1] == prev + 2) continue;
	    			else {
	    				int z = done[v][cur - i - 1];
	    				done[v][cur - i - 1] = 0;
	    				dfs(z - 2, cur - i - 2, from, -1);
	    			}
	    		}
	    	}
    	}
    };
    vi ans(n, -1);
    ans[0] = 0;
    while (!q.empty()) {
    	auto [x, y] = q.front();
    	q.pop();
    	if (x > 0) {
    		ans[x] = ans[y] + 1;
    	}
    	dfs(x, k, x, -1);
    }
    for (int i = 1; i < n; i++) {
    	cout << ans[i] << " ";
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
