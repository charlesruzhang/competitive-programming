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
    n /= 10;
    vector<pii> a(m);
    vi parent(m, 0);
    for (int i = 0; i < m; i++) {
    	cin >> a[i].first >> a[i].second;
    	a[i].first /= 10;
    	cin >> parent[i];
    }
    vl dp(n + 1, -MAXX);
    dp[0] = 0;
    vvi V(m);
    for (int i = 0; i < m; i++) {
    	if (parent[i]) {
    		V[parent[i] - 1].push_back(i);
    	}
    }
    for (int j = 0; j < m; j++) {
    	vector<pll> W;
    	if (V[j].size() == 0) {
    		if (parent[j]) continue;
    		W.push_back({a[j].first, a[j].first * a[j].second});
		} else if (V[j].size() == 1) {
			int id = V[j][0];
			auto [x, y] = a[id];
			auto [X, Y] = a[j];
			W.push_back({X, X * Y});
			W.push_back({X + x, X * Y + x * y});
		} else {
			int id = V[j][0];
			auto [x, y] = a[id];
			int id2 = V[j][1];
			auto [x2, y2] = a[id2];
			auto [X, Y] = a[j];
			W.push_back({X, X * Y});
			W.push_back({X + x, X * Y + x * y});
			W.push_back({X + x2, X * Y + x2 * y2});
			W.push_back({X + x + x2, X * Y + x * y + x2 * y2});
		}
    	vl ndp = dp;
		int Z = W.size();
    	for (int i = n; i >= 0; i--) {
    		for (int t = 0; t < Z; t++) {
    			if (i >= W[t].first && dp[i - W[t].first] != -MAXX) ndp[i] = max(ndp[i], dp[i - W[t].first] + W[t].second);
    		}
    	}
    	swap(ndp, dp);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
    	ans = max(ans, (int)dp[i]);
    }
    cout << ans * 10 << endl;
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
