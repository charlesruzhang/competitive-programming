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
    vi c(n);
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }
    vector<vector<pii>> a(m, vector<pii>(n));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[j][i].first;
    		a[j][i].second = i;
    	}
    }
    for (int i = 0; i < m; i++) {
    	sort(a[i].begin(), a[i].end());
    }
    vector<vector<pll>> e(m * n + n);
    for (int i = 0; i < m; i++) {
    	for (int j = 1; j < n; j++) {
    		int u = a[i][j-1].second;
    		int v = a[i][j].second;
    		int x = a[i][j].first - a[i][j-1].first;
    		e[u * m + i].push_back({v * m + i, x});
    		e[v * m + i].push_back({u * m + i, 0});
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		e[m * n + i].push_back({i * m + j, c[i]});
    		e[i * m + j].push_back({m * n + i, 0});
    	}
    }

    // Run Dijkstra
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({0, m * n + n - 1});
    vl dist(m * n + n, 1e18);
    while (!pq.empty()) {
    	auto [d, u] = pq.top();
    	pq.pop();
    	if (dist[u] < d) continue;
    	for (auto [v, w] : e[u]) {
    		if (dist[v] > d + w) {
    			dist[v] = d + w;
    			pq.push({dist[v], v});
    		}
    	}
    }
    cout << dist[m * n] << endl;
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