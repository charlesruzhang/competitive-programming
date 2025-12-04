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
    string s;
    cin >> s;
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    preprocess(n, e);
    vector<array<int, 3>> vec;
    for (int i = 0; i < n; i++) {
    	for (int j = i; j < n; j++) {
    		int x = lca(i, j);
    		int z = depth[i] + depth[j] - 2 * depth[x];
    		vec.push_back({z, i, j});
    	}
    }
    sort(vec.begin(), vec.end());
    vvi dp(n, vi(n));
   	for (int i = 0; i < vec.size(); i++) {
   		auto [d, u, v] = vec[i];
   		if (d == 0) {
   			dp[u][v] = 1;
   		} else if (d == 1) {
   			dp[u][v] = dp[v][u] = (s[u] == s[v]) ? 2 : 1;
   		} else {
   			int x = lca(u, v);
   			if (depth[u] > depth[v]) swap(u, v);
   			int uu, vv;
   			vv = parent[v];
   			if (x != u) {
   				uu = parent[u];
   			} else {
   				int d = depth[v] - depth[u] - 1;
   				int cur = v;
   				for (int i = LOG - 1; i >= 0; i--) {
   					if (d & (1 << i)) {
   						cur = up[cur][i];
   					}
   				}
   				uu = cur;
   			}
   			dp[u][v] = max(dp[u][vv], dp[v][uu]);
   			if (s[u] == s[v]) dp[u][v] = max(dp[u][v], dp[uu][vv] + 2);
   			dp[v][u] = dp[u][v];
   		}
   	}
   	int ans = 0;
   	for (int i = 0; i < n; i++) {
   		for (int j = i; j < n; j++) {
   			ans = max(ans, dp[i][j]);
   		}
   	}
   	cout << ans << endl;
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
