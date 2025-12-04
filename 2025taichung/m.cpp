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
    vi a(n);
    vvi A(k+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	A[a[i]].push_back(i);
    }
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    queue<pii> q;
    q.push({0, 0});
    vi visited(n);
    visited[0] = 1;
    vi d(n);
    while (!q.empty()) {
    	auto [x, y] = q.front();
    	q.pop();
    	for (int v: e[y]) {
    		if (!visited[v]) {
    			d[v] = x + 1;
    			q.push({x + 1, v});
    			visited[v] = 1;
    		}
    	}
    }
    for (int i = 1; i <= k; i++) {
    	int ans = 0;
    	for (int x: A[i]) {
    		ans = max(ans, d[x]);
    	}
    	cout << ans << " ";
    }
    cout << endl;
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
