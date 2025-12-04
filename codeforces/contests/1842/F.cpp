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
    vl ans(n + 1);
    for (int i = 0; i < n; i++) {
    	queue<pii> q;
    	q.push({i, 0});
    	vi vis(n);
    	int cnt = 0;
    	ll tot = 0;
    	while (!q.empty()) {
    		auto [u, d] = q.front();
    		q.pop();
    		cnt++;
    		vis[u] = 1;
    		tot += d;
    		ans[cnt] = max(ans[cnt], 1ll * cnt * (n - 1) - 2 * tot);
    		for (int v : e[u]) {
    			if (!vis[v]) {
    				q.push({v, d+1});
    			}
    		}
    	}
    }
    for (int i = 0; i <= n; i++) {
    	cout << ans[i] << " ";
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
