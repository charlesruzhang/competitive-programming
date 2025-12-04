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
struct VirtualTree {
    int n, LOG, root;
    vector<vector<int>> e;        // base tree edges (0-indexed)
    vector<vector<int>> up;       // up[v][i] = 2^i ancestor
    vector<int> depth, tin, tout;
    int timer = 0;

    VirtualTree(int n=0): n(n) {}

    void init(int _n, const vector<vector<int>>& _e, int _root=0) {
        n = _n; e = _e; root = _root;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;

        // iterative DFS for tin/tout + binary lifting table
        vector<int> parent(n, -1), it(n, 0);
        vector<int> st; st.reserve(n);
        st.push_back(root);
        parent[root] = root;
        up[root][0] = root;

        while (!st.empty()) {
            int v = st.back();
            if (it[v] == 0) tin[v] = timer++;

            if (it[v] < (int)e[v].size()) {
                int to = e[v][it[v]++];
                if (to == parent[v]) continue;
                parent[to] = v;
                depth[to] = depth[v] + 1;
                up[to][0] = v;
                for (int j = 1; j < LOG; j++) up[to][j] = up[ up[to][j-1] ][j-1];
                st.push_back(to);
            } else {
                tout[v] = timer++;
                st.pop_back();
            }
        }
    }

    bool is_ancestor(int a, int b) const {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }

    int lca(int a, int b) const {
        if (is_ancestor(a, b)) return a;
        if (is_ancestor(b, a)) return b;
        for (int j = LOG - 1; j >= 0; j--) {
            int x = up[a][j];
            if (!is_ancestor(x, b)) a = x;
        }
        return up[a][0];
    }

    // Builds a *rooted* virtual tree (parent -> children, directed).
    // Inputs:
    //   v: important nodes (0-indexed)
    // Outputs:
    //   vt: adjacency list over original node IDs (size n). Only nodes in `verts` are touched/cleared/filled.
    //   verts: all nodes used in the virtual tree (v + LCAs), sorted by tin
    // Returns:
    //   root of the virtual tree (an element of verts), or -1 if v empty.
    int buildVT(vector<int> v, vector<vector<int>>& vt, vector<int>& verts) const {
        if (v.empty()) { verts.clear(); return -1; }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        auto byTin = [&](int a, int b){ return tin[a] < tin[b]; };
        sort(v.begin(), v.end(), byTin);

        verts = v;
        for (int i = 0; i + 1 < (int)v.size(); i++) verts.push_back(lca(v[i], v[i+1]));

        sort(verts.begin(), verts.end(), byTin);
        verts.erase(unique(verts.begin(), verts.end()), verts.end());

        for (int x : verts) vt[x].clear();

        vector<int> st;
        st.reserve(verts.size());
        st.push_back(verts[0]);
        for (int i = 1; i < (int)verts.size(); i++) {
            int u = verts[i];
            while (!is_ancestor(st.back(), u)) st.pop_back();
            vt[st.back()].push_back(u);
            st.push_back(u);
        }
        return verts[0];
    }
};

/*
Usage:

int n; cin >> n;
vector<vector<int>> e(n);
for (int i=0;i<n-1;i++){
  int a,b; cin>>a>>b;
  e[a].push_back(b);
  e[b].push_back(a);
}
VirtualTree VT;
VT.init(n, e, 0);

vector<int> important = {...};
vector<vector<int>> vt(n);
vector<int> verts;
int r = VT.buildVT(important, vt, verts);

// vt[x] lists children of x in the virtual tree, for x in verts.
*/
void solve() {
    int n;
    cin >> n;
    vvi e(n);
    vi c(n);
    vvi C(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    	C[c[i]].push_back(i);
    }
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    VirtualTree VT;
    VT.init(n, e, 0);
    vi val(n);
    ll ans = 0;
    vvi E(n);
    for (int i = 1; i <= n; i++) {
    	if (C[i].size() <= 1) continue;
    	vi V;
    	int root = VT.buildVT(C[i], E, V);
    	function <void(int, int)> dfs = [&] (int u, int p) {
    		vi vals;
    		for (int v : E[u]) {
    			if (v != p) {
    				dfs(v, u);
    				vals.push_back(val[v]);
    			}
    		}
    		if (c[u] == i) {
    			for (int x : vals) {
    				ans += x;
    			}
    			val[u] = 1;
    		} else {
    			val[u] = 0;
    			for (int x: vals) {
    				ans += 1ll * val[u] * x; 
    				val[u] += x;
    			}
    		}
    	};
    	dfs(root, -1);

    	for (int u: V) {
    		E[u].clear();
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
