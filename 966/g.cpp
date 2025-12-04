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
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    vector<vector<array<int, 3>>> e(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w, x;
    	cin >> u >> v >> w >> x;
    	u--; v--;
    	e[u].push_back({v, w, x});
    	e[v].push_back({u, w, x});
    }
    priority_queue<array<int, 2>> pq;
    pq.push({t0, n-1});
    vi vis(n);
    vi best(n, -INF);
    best[n-1] = t0;
    while (!pq.empty()) {
    	auto [val, u] = pq.top();
    	pq.pop();
    	if (vis[u]) continue;
    	vis[u] = 1;
    	//cout << u << " " << best[u] << endl;
    	for (auto [v, w, x] : e[u]) {
    		int tar = min(val, t1) - w;
    		if (val - w >= t2) {
    			tar = val - w;
    		}
    		if (val - x >= 0) {
    			tar = max(tar, val - x);
    		}
    		if (tar >= 0 && tar >= best[v]) {
    			best[v] = tar;
    			pq.push({best[v], v});
    		}
    	}
    }
   	if (best[0] < 0) cout << -1 << endl;
   	else cout << best[0] << endl;
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
