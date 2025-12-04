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
void solve() {
    int n;
    cin >> n;
    vvi e(n);
    for (int i = 0; i < n-1; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi sz(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	int cur = 0;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    			cur += sz[v];
    		}
    	}
    	sz[u] = cur + 1;
    };
    dfs(0, -1);
    int tot = n / 2;
    int centroid = -1;
    function <void(int, int)> dfs2 = [&] (int u, int p) {
    	for (int v : e[u]) {
    		if (v != p && sz[v] > tot) {
    			dfs2(v, u);
    		}
    	}
    	if (centroid == -1) centroid = u;
    };
    dfs2(0, -1);
    vi depth(n);
    function <void(int, int)> dfs3 = [&] (int u, int p) {
    	for (int v : e[u]) {
    		if (v != p) {
    			depth[v] = depth[u] + 1;
    			dfs3(v, u);
    		}
    	}
    };
    dfs3(centroid, -1);
    int minn = 1e9;
    int mini = -1;
    for (int i = 0; i < n; i++) {
    	if (e[i].size() == 1) {
    		if (minn > depth[i]) {
    			minn = depth[i];
    			mini = i;
    		}
    	}
    }
    function <void(int, int, vvi&, int)> dfs4 = [&] (int u, int p, vvi& f, int idx) {
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs4(v, u, f, idx);
    		}
    	}
    	if (u != mini) f[idx].push_back(u);
    };
    vvi f(n);
    for (int v : e[centroid]) {
    	dfs4(v, centroid, f, v);
    }
    f[centroid].push_back(centroid);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++) {
    	if (!f[i].size()) continue;
    	pq.push({f[i].size(), i});
    }
    vi color(n);
    int cnt = 1;
    while (!pq.empty()) {
    	auto [x, i] = pq.top();
    	pq.pop();
    	assert(!pq.empty());
    	auto [y, j] = pq.top();
    	pq.pop();
    	int z = f[i].back();
    	int w = f[j].back();
    	f[i].pop_back();
    	f[j].pop_back();
    	color[z] = color[w] = cnt++;
    	x--; y--;
    	if (x) pq.push({x, i});
    	if (y) pq.push({y, j});
    }
    cout << mini+1 << " " << e[mini][0] + 1 << endl;
    if (mini < e[mini][0]) {
    	swap(color[mini], color[e[mini][0]]);
    }
    for (int i = 0; i < n; i++) {
    	cout << color[i] << " ";
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
