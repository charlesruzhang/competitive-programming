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
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    x--; y--;
    vi a(k);
    for (int i = 0; i < k; i++) {
    	cin >> a[i];
    	a[i]--;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    // for (int i = 0; i < a.size(); i++) {
    // 	//cout << a[i] << " %% " <<endl;
    // }
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	v--; u--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi p(n, -1);
    function <void(int)> dfs = [&](int u) {
    	for (int v : e[u]) {
    		if (v != p[u]) {
    			p[v] = u;
    			dfs(v);
    		}
    	}
    };
    dfs(x);
    vi mark(n);
    mark[x] = 1;
    for (int i = 0; i < a.size(); i++) {
    	int cur = a[i];
    	while (!mark[cur]) {
    		mark[cur] = 1;
    		cur = p[cur];
    	}
    }
    int cur = y;
    while (cur != x) {
    	mark[cur] = 2;
    	cur = p[cur];
    }
    mark[x] = 2;
    int cnt = 0;
    vi ans(n);
    function <void(int)> dfs2 = [&] (int u) {
    	ans[u] = 1;
    	for (int v : e[u]) {
    		if (v != p[u] && mark[v] == 1) {
    			dfs2(v);
    			ans[u] += ans[v];
    		}
    	}
    };
    ll res = 0;
    // for (int i = 0; i < n; i++) {
    // 	cout << mark[i] << " " << i << endl;
    // }
    for (int i = 0; i < n; i++) {
    	if (mark[i] == 2) {
    		dfs2(i);
    		res += ans[i] * 2 - 1;
    	}
    }
    cout << res - 1 << endl;
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
