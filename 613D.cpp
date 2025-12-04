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
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    preprocess(n, e);
    vi seq(n);
    vi ord(n);
    int timer = 0;
    function <void(int, int)> dfs = [&] (int u, int p) {
    	ord[u] = timer;
    	seq[timer++] = u;
    	for (int v : e[u]) {
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
    	if (sz == 1) {
    		cout << 0 << endl;
    		continue;
    	}
    	sort(a.begin(), a.end(), [&](int u, int v) {
    		return ord[u] < ord[v];
    	});
    	int flag = 0;
    	for (int j = 0; j < sz; j++) {
    		if (S.find(parent[a[j]]) != S.end()) {
    			cout << -1 << endl;
    			flag = 1;
    			break;
    		}
    	}
    	if (flag) continue;
    	vvi f;
    	f.push_back({});
    	stack<int> st;
    	st.push(0);
    	int timer = 1;
    	vector<pii> V;
    	V.push_back({0, 0});
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
	    			f[Y].push_back(X);
	    			f[X].push_back(Y);
    			} else {
    				int z = st.top();
    				int Z = match[z];
    				f[Z].push_back(Y);
    				f[Y].push_back(Z);
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
    		f[vv].push_back(uu);
    		f[uu].push_back(vv);
    	}
    	int szz = f.size();
    	vl dp(szz, INF); // no black
    	vl dp2(szz, INF); // black
    	function <void(int, int)> dfs = [&] (int u, int p) {
    		int w = V[u].second;
    		int ans = 0;
    		ll tot = 0, tot2 = 0, maxx = 0;
    		for (int v : f[u]) {
    			if (v != p) {
    				dfs(v, u);
    				if (w) {
    					ans += min(dp[v], dp2[v] + 1);
    				} else {
    					tot += dp2[v];
    					tot2 += dp[v];
    					maxx = max(maxx, dp[v] - dp2[v]);
    				}	
    			}
    		}
    		if (f[u].size() == 1 && u != 0) {
    			if (w) {
    				dp2[u] = 0;
    			} else {
    				dp2[u] = dp[u] = 0;
    			}
    		} else if (w) {
    			dp[u] = INF;
    			dp2[u] = ans;
    		} else {
    			dp[u] = min(tot + 1, tot2);
    			dp2[u] = min(dp[u], tot2 - maxx);
    		}
    	};
    	dfs(0, -1);
    	cout << min(dp[0], dp2[0]) << endl;
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
