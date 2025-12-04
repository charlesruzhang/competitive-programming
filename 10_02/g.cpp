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
	    int n, m, k;
	    cin >> n >> m >> k;
	    int start = -1;
	    vector<vector<pii>> e(k + n + m + 1);
	    map<pii, int> ma;
	    int end = -1;
	    for (int i = 0; i < k; i++) {
	    	int u, v;
	    	cin >> u >> v;
	    	u--; v--;
	    	e[i].push_back({k + u + 1, 1});
	    	e[k + u + 1].push_back({i, 0});

	    	if (u) {
		    	e[i].push_back({k + u, 1});
		    	e[k + u].push_back({i, 0});
	    	}

	    	if (u != n - 1) {
	    		e[i].push_back({k + u + 2, 1});
	    		e[k + u + 2].push_back({i, 0});
	    	}

	    	e[i].push_back({k + n + v + 1, 1});
	    	e[k + n + v + 1].push_back({i, 0});

	    	if (v) {
	    		e[i].push_back({k + n + v, 1});
	    		e[k + n + v].push_back({i, 0});
	    	}

	    	if (v != m - 1) {
	    		e[i].push_back({k + n + v + 2, 1});
	    		e[k + n + v + 2].push_back({i, 0});
	    	}
	    	auto it = ma.begin();
	    	if ((it = ma.find({u - 1, v})) != ma.end()) {
	    		int v = it -> second;
	    		e[i].push_back({v, 0});
	    		e[v].push_back({i, 0});
	    	}
	    	if ((it = ma.find({u, v - 1})) != ma.end()) {
	    		int v = it -> second;
	    		e[i].push_back({v, 0});
	    		e[v].push_back({i, 0});
	    	}
	    	if ((it = ma.find({u + 1, v})) != ma.end()) {
	    		int v = it -> second;
	    		e[i].push_back({v, 0});
	    		e[v].push_back({i, 0});
	    	}
	    	if ((it = ma.find({u, v + 1})) != ma.end()) {
	    		int v = it -> second;
	    		e[i].push_back({v, 0});
	    		e[v].push_back({i, 0});
	    	}
	    	if (u == 0 && v == 0) {
	    		start = i;
	    	}
	    	if (u == n - 1 && v == m - 1) {
	    		end = i;
	    	}
	    	ma[{u, v}] = i;
	    }
	    if (end == -1) end = k;
	    e[k + n - 1 + 1].push_back({k, 0});
	    e[k + m - 1 + n + 1].push_back({k, 0});
	    auto Dijk = [&] (int u) {
	    	vl dist(k + n + m + 1, MAXX);
	    	dist[u] = 0;
	    	priority_queue<pll, vector<pll>, greater<>> pq;
	    	pq.push({0, u});
	    	vi vis(k + n + m + 1);
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
	    auto D = Dijk(start);
	    cout << (D[end] == MAXX ? -1 : D[end]) << endl;
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
