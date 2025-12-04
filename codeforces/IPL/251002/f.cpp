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
    int n, m, h;
    cin >> n >> m >> h;
    vi mark(n);
    vector<vector<pii>> e(2 * n);
    for (int i = 0; i < h; i++) {
    	int x;
    	cin >> x;
    	e[x-1].push_back({x - 1 + n, 0});
    }
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	e[u].push_back({v, w});
    	e[v].push_back({u, w});
    	e[u+n].push_back({v+n, w / 2});
    	e[v+n].push_back({u+n, w / 2});
    }
    auto Dijk = [&] (int u) {
    	vl dist(2 * n, MAXX);
    	dist[u] = 0;
    	priority_queue<pll, vector<pll>, greater<>> pq;
    	pq.push({0, u});
    	vi vis(2 * n);
    	while (!pq.empty()) {
    		auto [val, u] = pq.top();
    		pq.pop();
    		if (vis[u]) continue;
    		vis[u] = 1;
    		for (auto [v, w] : e[u]) {
    			if (dist[v] > val + w) {
    				dist[v] = val + w;
    				pq.push({dist[v], v});
    			}
    		}
    	}
    	return dist;
    };
    auto D = Dijk(0);
    auto E = Dijk(n - 1);
    ll ans = MAXX;
    for (int i = 0; i < n; i++) {
    	D[i] = min(D[i], D[n + i]);
    	E[i] = min(E[i], E[n + i]);
    	ans = min(ans, max(D[i], E[i]));
    }
    cout << (ans == MAXX ? -1 : ans) << endl;
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
