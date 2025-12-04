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
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi parent(n, -1);
    vi color(n, -1);
    function <void(int, int, int)> dfs = [&] (int u, int p, int c) {
    	parent[u] = p;
    	color[u] = c;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u, c ^ 1);
    		}
    	}
    };
    dfs(0, -1, 0);
    vi mark(n);
    vi P;
    mark[0] = 1;
    int cur = n - 1;
    while (cur != 0) {
    	mark[cur] = 1;
    	P.push_back(cur);
    	cur = parent[cur];
    }
    P.push_back(0);
    reverse(P.begin(), P.end());
    vector<pii> ans;
    vvi L(2);
    vi f(n);
    for (int i = 0; i < n; i++) {
    	f[i] = e[i].size();
    	if (!mark[i] && f[i] == 1) {
    		L[color[i]].push_back(i);
    	}
    }
    int C = 0;
    while (L[0].size() || L[1].size()) {
    	if (L[C ^ 1].empty()) {
    		C ^= 1;
    		ans.push_back({1, -1});
    		continue;
    	} else {
    		int x = L[C^1].back();
    		L[C^1].pop_back();
    		int px = parent[x];
    		f[px]--;
    		if (!mark[px] && f[px] == 1) {
    			L[color[px]].push_back(px);
    		}
    		ans.push_back({2, x});
    		ans.push_back({1, -1});
    		C ^= 1;
    	}
    }
    int D = 0;
    while (D + 1 < P.size()) {
    	int x = P[D];
    	if (color[x] == C) {
    		ans.push_back({1, -1});
    		C ^= 1;
    	} else {
    		ans.push_back({2, x});
    		D++;
    		C ^= 1;
    		ans.push_back({1, -1});
    	}
    }
    assert(ans.size() <= 3 * n);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	auto [x, y] = ans[i];
    	if (x == 1) {
    		cout << 1 << endl;
    	} else {
    		cout << 2 << " " << y + 1 << endl;
    	}
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
