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
    int n;
    cin >> n;
    vector<vector<pii>> e(n);
    vector<pii> edges;
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back({v, i-1});
    	e[v].push_back({u, i-1});
    	edges.push_back({u, v});
    }
    vi mark(n);
    vi me(n - 1);
    vector<pii> ans;
    vvi pend(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	int tot = 0;
    	for (auto [v, w] : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    			if (!mark[v]) tot++;
    		}
    	}
    	if (pend[u].size() >= 1 || tot >= 3) {
    		mark[u] = 1;
    		ans.push_back({2, u});
    		for (auto [v, w]: e[u]) {
    			me[w] = 1;
    		}
    	} else if (tot == 2) {
    		if (p != -1) pend[p].push_back(u);
    	}
    };
    dfs(0, -1);
    vi done(n);
    function <void(int)> dfs2 = [&] (int u) {
    	done[u] = 1;
    	ans.push_back({1, u});
    	for (auto [v, w] : e[u]) {
    		if (me[w]) continue;
    		me[w] = 1;
    		dfs2(v);
    	}
    };
    vi q;
    function <void(int)> dfs3 = [&] (int u) {
    	int cnt = 0;
    	for (auto [v, w] : e[u]) {
    		if (!me[w]) cnt++;
    	}
    	if (cnt == 1) {
    		q.push_back(u);
    	} else if (cnt == 0) {
    		ans.push_back({1, u});
    	}
    };
    for (int i = 0; i < n; i++) {
    	dfs3(i);
    }
    for (int i = 0; i < q.size(); i++) {
    	if (!done[q[i]]) dfs2(q[i]);
    }
    cout << ans.size() << endl;
    //assert(ans.size() <= 5 * n / 4);
    for (int i = 0; i < ans.size(); i++) {
    	auto [x, y] = ans[i];
    	cout << x << " " << y + 1 << endl;
    }
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
