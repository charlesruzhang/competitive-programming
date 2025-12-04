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
vvi minn;
void preprocess(int n, vector<vector<pii>> &adj, int root = 0) {
    parent.resize(n);
    depth.resize(n);
    up.assign(n, vector<int>(LOG, -1));
    minn.assign(n, vector<int>(LOG, INF));
    function<void(int, int, int)> dfs = [&](int v, int p, int w) {
        parent[v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        up[v][0] = p;
        minn[v][0] = w;
        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1) {
                up[v][i] = up[up[v][i - 1]][i - 1];
                minn[v][i] = min(minn[v][i-1], minn[up[v][i-1]][i-1]);
            }
        }
        for (auto [u, ww] : adj[v]) {
            if (u != p) dfs(u, v, ww);
        }
    };

    dfs(root, -1, INF);
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
    vector<vector<pii>> e(n);
    for (int i = 1; i < n; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	e[u].push_back({v, w});
    	e[v].push_back({u, w});
    }
    preprocess(n, e);
    vi seq(n);
    vi ord(n);
    int timer = 0;
    function <void(int, int)> dfs = [&] (int u, int p) {
    	ord[u] = timer;
    	seq[timer++] = u;
    	for (auto [v, w] : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    		}
    	}
    };
    dfs(0, -1);
    int q;
    cin >> q;
    vi match(n);
    for (int i = 0; i < q; i++) {
    	int sz;
    	cin >> sz;
    	vi a(sz);
    	set<int> S;
    	for (int j = 0; j < sz; j++) {
    		cin >> a[j];
    		a[j]--;
    		S.insert(a[j]);
    	}
    	sort(a.begin(), a.end(), [&](int u, int v) {
    		return ord[u] < ord[v];
    	});
    	vector<vector<pii>> f;
    	f.push_back({});
    	stack<int> st;
    	st.push(0);
    	int timer = 1;
    	vector<pii> V;
    	V.push_back({0, 0});
        auto F = [&] (int y, int z) {
            int diff = depth[y] - depth[z];
            int w = INF;
            int cur = y;
            for (int k = LOG - 1; k >= 0; k--) {
                if (diff & (1 << k)) {
                    w = min(w, minn[cur][k]);
                    cur = up[cur][k];
                }
            }
            return w;
        };
    	for (int j = 0; j < sz; j++) {
    		int x = lca(st.top(), a[j]);
    		if (a[j]) {
    			match[a[j]] = timer++;
    			f.push_back({});
    			V.push_back({a[j], 1});
    		} else {
    			V[0] = {0, 1};
    		}
    		while (depth[x] < depth[st.top()]) {
    			int y = st.top();
    			int Y = match[y];
    			st.pop();
    			if (depth[x] >= depth[st.top()]) {
    				if (depth[x] > depth[st.top()]) {
		    			st.push(x);
		    			match[x] = timer++;
		    			f.push_back({});
		    			V.push_back({x, 0});
		    		}
	    			int X = match[x];
                    
                    int w = F(y, x);
	    			f[Y].push_back({X, w});
	    			f[X].push_back({Y, w});
    			} else {
    				int z = st.top();
    				int Z = match[z];
                    int w = F(y, z);
    				f[Z].push_back({Y, w});
    				f[Y].push_back({Z, w});
    			}
    		}
    		
    		if (a[j]) st.push(a[j]);
    	}
    	while (st.size() >= 2) {
    		int v = st.top();
    		st.pop();
    		int u = st.top();
    		int vv = match[v];
    		int uu = match[u];
            int w = F(v, u);

    		f[vv].push_back({uu, w});
    		f[uu].push_back({vv, w});
    	}
    	int szz = f.size();
    	vl dp(szz, MAXX);
    	function <void(int, int, ll)> dfs = [&] (int u, int p, ll w) {
    		int W = V[u].second;
    		ll tot2 = 0;
            if (!W) {
                for (auto [v, ww] : f[u]) {
                    if (v != p) {
                        dfs(v, u, ww);
                        tot2 += dp[v];
                    }
                }
            }
    		if (W) {
    			dp[u] = w;
    		} else {
    			dp[u] = min(w, tot2);
    		}
    	};
    	dfs(0, -1, MAXX);
    	cout << dp[0] << endl;
    	for (auto [v, w] : V) {
    		match[v] = 0;
    	}
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
