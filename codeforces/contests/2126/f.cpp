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
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<vector<pii>> e(n);
    ll tot = 0;
    for (int i = 1; i < n; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	if (a[u] != a[v]) tot += w;
    	e[u].push_back({v, w});
    	e[v].push_back({u, w});
    }
    vi parent(n, -1);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	for (auto [v, w] : e[u]) {
    		if (v != p) {
    			parent[v] = u;
    			dfs(v, u);
    		}
    	}
    };
    dfs(0, -1);
    vector<map<int, ll>> vm(n);
    vi val(n);
    for (int i = 0; i < n; i++) {
    	for (auto [v, w] : e[i]) {
    		if (v != parent[i]) {
    			vm[i][a[v]] += w;
    		} else {
    			val[i] = w;
    		}
    	}
    }
    ll now = tot;
    while (q--) {
    	int v, x;
    	cin >> v >> x;
    	v--;
    	if (v) {
    		vm[parent[v]][a[v]] -= val[v];
    		vm[parent[v]][x] += val[v];
    	}
    	if (v && a[v] != a[parent[v]]) {
    		now -= val[v];
    	}
		now += vm[v][a[v]];
		now -= vm[v][x];
    	a[v] = x;
    	if (v && a[v] != a[parent[v]]) {
    		now += val[v];
    	}
    	cout << now << endl;
    }
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
