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
void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vvi e(n);
    x--; y--;
    vector<pii> edges;
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    	edges.push_back({u, v});
    }
    vi mark(n);
    int cur = 0;
    vi ans;
    function <bool(int)> dfs = [&] (int u) {
    	DSU D(n);
    	if (u == y) {
    		return false;
    	}
    	for (int i = 0; i < m; i++) {
    		auto [u, v] = edges[i];
    		if (mark[u] || mark[v]) {
    			continue;
    		} else {
    			D.unite(u, v);
    		}
    	}
    	mark[u] = 1;
    	if (D.find(u) != D.find(y)) {
    		return true;
    	}
    	sort(e[u].begin(), e[u].end());
    	for (int v : e[u]) {
    		if (!mark[v]) {
    			if (!dfs(v)) {
    				ans.push_back(v);
    				return false;
    			} 
    		}
    	}
    	assert(false);
    	return true;
    };
    dfs(x);
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] + 1 << " ";
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
