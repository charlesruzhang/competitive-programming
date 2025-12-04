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
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }
    DSU (const DSU& D2) {
    	parent = D2.parent;
    	rank = D2.rank;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> e(n);
    for (int i = 0; i < m; i++) {
    	int x, y, w; 
    	cin >> x >> y >> w;
    	x--; y--;
    	e[x].push_back(pii(y, w));
    	e[y].push_back(pii(x, w));
    }
    int LOG = 30;
    vector<DSU> D(LOG+1, DSU(n+1));
    vi vis(n);
    function <void(int)> dfs2 = [&](int u) {
    	vis[u] = 1;
    	for (auto [v, w] : e[u]) {
    		if (!vis[v] && !(w & 1)) {
    			D[LOG].unite(u, n);
    			D[LOG].unite(v, n);
    			dfs2(v);
    		}
    	}
    };
    for (int i = 0; i < n; i++) {
    	if (!vis[i]) dfs2(i);
    }
    vector<DSU> D2(LOG, DSU(D[LOG]));
    function <void(int, int, int)> dfs = [&](int u, int idx, int flag) {
    	vis[u] = 1;
    	for (auto [v, w] : e[u]) {
    		if (!vis[v] && (w & (1 << idx))) {
    			 //cout << u << " " << v << " " << idx << endl;
    			if (!flag) D[idx].unite(u, v);
    			else D2[idx].unite(u,v);
    			dfs(v, idx, flag);
    		}
    	}
    };
    for (int k = 0; k <= 1; k++) {
    	for (int j = k; j < LOG; j++) {
	    	fill(vis.begin(), vis.end(), 0);
    		for (int i = 0; i < n; i++)  {
	    		if (!vis[i]) dfs(i, j, k);
    		}
    	}
    }
    vi fl(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 1; j < LOG; j++) {
    		if (D2[j].find(i) == D2[j].find(n)) {
    			fl[i] = 1;
    			break;
    		}
    	}
    }
    int q;
    cin >> q;
    while (q--) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	int f = 1;
    	for (int i = 0; i < LOG; i++) {
    		// cout << u << " ? " << v << " ! " << D[i].find(u) << " " << D[i].find(v) << endl;
    		if (D[i].find(u) == D[i].find(v)) {
    			cout << 0 << endl;
    			f = 0;
    			break;
    		}
    	}
    	if (f) {
    		if (fl[u]) {
    			cout << 1 << endl;
    		} else {
    			cout << 2 << endl;
    		}
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
