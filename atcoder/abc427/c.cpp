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
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	edges.push_back({u, v});
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
    	vi a(n);
    	for (int j = 0; j < n; j++) {
    		a[j] = (i & (1 << j)) ? 1 : 0;
    	}
    	int tot = m;
    	for (int j = 0; j < m; j++) {
    		auto [u, v] = edges[j];
    		if (a[u] == a[v]) {
    			tot--;
    		}
    	}
    	ans = max(ans, tot);
    }
    cout << m - ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
