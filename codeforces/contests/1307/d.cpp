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
    vi p(k);
    for (int i = 0; i < k; i++) {
    	cin >> p[i];
    	p[i]--;
    }
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    auto bfs = [&] (int x, vi &dist) {
    	dist[x] = 0;
    	queue<int> q;
    	q.push(x);
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		for (int v : e[u]) {
    			if (dist[v] == INF) {
    				dist[v] = dist[u] + 1;
    				q.push(v);
    			} 
    		}
    	}
    };
    vi d1(n, INF), d2(n, INF);
    bfs(0, d1);
    bfs(n-1, d2);
    sort(p.begin(), p.end(), [&](int a, int b) {
    	return d1[a] - d2[a] < d1[b] - d2[b];
    });
    int maxx = d1[p[0]];
    int ans = 0;
    for (int i = 1; i < k; i++) {
    	ans = max(ans, maxx + d2[p[i]] + 1);
    	maxx = max(maxx, d1[p[i]]);
    }
    ans = min(ans, d1[n-1]);
    cout << ans << endl;
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
