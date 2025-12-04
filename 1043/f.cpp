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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> e(n);
    vector<pii> edges;
    queue<array<int, 3>> pq;
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back({v, i});
    	e[v].push_back({u, i});
    	edges.push_back({u, v});
    }
    int time = 0;
	vi disc(n, -1), low(n, -1);
	vi bridge(m);
	function <void(int, int)> dfs = [&] (int u, int p) {
	    disc[u] = low[u] = time++;
	    for (auto [v, w] : e[u]) {
	        if (w == p) continue;                
	        if (disc[v] == -1) {           
	            dfs(v, w);
	            low[u] = min(low[u], low[v]);
	            if (low[v] > disc[u]) bridge[w] = 1;
	        } else {
	            low[u] = min(low[u], disc[v]);
	        }
	    }
	};
    dfs(0, -1);
    vector<pii> par(n, {-1, -1});
    vi vis(n);
    function <void(int, int, int)> dfs2 = [&] (int u, int ed, int p) {
	    par[u] = {ed, p};
	    vis[u] = 1;
	    for (auto [v, w] : e[u]) {
	    	if (!vis[v]) {
	    		dfs2(v, w, u);
	    	}
	    }
	};
	dfs2(0, -1, -1);
	int cur = n - 1;
	vi bri(m);
	while (cur != -1) {
		auto [ed, p] = par[cur];
		if (ed != -1) bri[ed] = bridge[ed] & 1;
		cur = p;
	}
    for (int i = 0; i < m; i++) {
    	if (bri[i]) {
    		auto [u, v] = edges[i];
    		pq.push({0, u, i});
    		pq.push({0, v, i});
    	}
    }
    vi vis2(n, -1);
    while (!pq.empty()) {
    	auto [val, u, idx] = pq.front();
    	pq.pop();
    	if (vis2[u] != -1) {
    		continue;
    	}
    	vis2[u] = idx;
    	for (auto [v, w] : e[u]) {
    		pq.push({val + 1, v, idx});
    	}
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	x--;
    	if (vis2[x] != -1) cout << vis2[x] + 1 << " ";
    	else cout << -1 << " ";
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
