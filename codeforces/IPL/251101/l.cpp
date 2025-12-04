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
    vector<pii> edges;
    vector<vector<pii>> e(n);
    vi c(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back({v, i});
    	c[v]++;
    	edges.push_back({u, v});
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
    	if (c[i] == 0) {
    		q.push(i);
    	}
    }
    vi seq(n);
    vi ord(n);
    int timer = 0;
    while (!q.empty()) {
    	int x = q.front();
    	q.pop();
    	seq[x] = timer;
    	ord[timer] = x;
    	timer++;
    	for (auto [v, id]: e[x]) {
    		c[v]--;
    		if (c[v] == 0) {
    			q.push(v);
    		}
    	}
    }
    int cur = 0;
    vi color(m);
    for (auto [u, v] : edges) {
    	int x = seq[u];
    	int y = seq[v];
    	if (y / 40 == x / 40) {
    		color[cur++] = 0;
    	} else if (y / 1600 == x / 1600) {
    		color[cur++] = 1;
    	} else {
    		color[cur++] = 2;
    	}
    }
    for (int i = 0; i < m; i++) {
    	cout << "RGB"[color[i]] << endl;
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
