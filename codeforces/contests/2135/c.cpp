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
struct SCC {
    int n;
    vector<pair<int,int>> edges;
    vector<vector<pair<int,int>>> g;
    vector<int> disc, low, comp;
    vector<char> is_bridge, seen;
    int timer = 0, comp_cnt = 0;

    vector<vector<int>> tree;

    SCC(int n): n(n), g(n) {}

    void add_edge(int u, int v) {
        int id = (int)edges.size();
        edges.push_back({u, v});
        g[u].push_back({v, id});
        g[v].push_back({u, id});
    }

    void dfs_bridges(int u, int peid) {
        disc[u] = low[u] = ++timer;
        for (auto [v, id] : g[u]) {
            if (id == peid) continue;
            if (!disc[v]) {
                dfs_bridges(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) is_bridge[id] = 1; 
            } else {
                low[u] = min(low[u], disc[v]); 
            }
        }
    }

    void dfs_comp(int u, int cid) {
        comp[u] = cid;
        for (auto [v, id] : g[u]) {
            if (comp[v] != -1) continue;
            if (is_bridge[id]) continue; 
            dfs_comp(v, cid);
        }
    }

    void run() {
        disc.assign(n, 0); low.assign(n, 0);
        is_bridge.assign(edges.size(), 0);
        comp.assign(n, -1);
        timer = 0; comp_cnt = 0;
        for (int i = 0; i < n; ++i) if (!disc[i]) dfs_bridges(i, -1);
        for (int i = 0; i < n; ++i) if (comp[i] == -1) dfs_comp(i, comp_cnt++);
        tree.assign(comp_cnt, {});
        for (int id = 0; id < (int)edges.size(); ++id) if (is_bridge[id]) {
            auto [u, v] = edges[id];
            int a = comp[u], b = comp[v];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
};

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
void solve() {
    int n, m, V;
    cin >> n >> m >> V;
    SCC S(n);
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	S.add_edge(u, v);
    }
    S.run();
    vvi e(n);
    for (int i = 0; i < S.edges.size(); i++) {
    	if (!S.is_bridge[i]) {
        	auto [u, v] = S.edges[i];
    		e[v].push_back(u);
    		e[u].push_back(v);
    	}
    }
    vi vis(n);
    vi color(n, -1);
    mi ans = 1;
    for (int i = 0; i < n; i++) {
    	if (!vis[i]) {
    		queue<int> q;
    		q.push(i);
    		vis[i] = 1;
    		color[i] = 1;
    		vi s;
    		int flag = 0;
    		while (!q.empty()) {
    			int u = q.front();
    			q.pop();
    			s.push_back(u);
    			for (int v : e[u]) {
    				if (!vis[v]) {
    					vis[v] = 1;
    					q.push(v);
    					color[v] = 1 - color[u];
    				} else if (color[u] == color[v]) {
    					flag = 1;
    				}
    			}
    		}
    		if (flag) {
    			int prev = -1;
    			for (int v : s) {
    				if (a[v] != -1 && a[v] != 0) {
						cout << 0 << endl;
						return;
    				}
    			}
    		} else {
    			int prev = -1;
    			for (int v : s) {
    				if (a[v] != -1 && prev != -1) {
    					if (a[v] != prev) {
    						cout << 0 << endl;
    						return;
    					}
    				} else if (a[v] != -1) {
    					prev = a[v];
    				}
    			}
    			if (prev == -1) {
    				ans *= V;
    			}
    		}
    	}
    }
    cout << (int) ans << endl;
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
