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
    string s;
    cin >> s;
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[v].push_back(u);
    }
    vvi dp(2 * k + 1, vi(n));
    for (int i = 0; i < n; i++) {
    	dp[0][i] = s[i] - 'A';
    }
    for (int i = 0; i < k; i++) {
    	for (int u = 0; u < n; u++) {
    		for (int v : e[u]) {
    			dp[2 * i + 1][v] = max(dp[2 * i + 1][v], dp[2 * i][u]);
    		}
    	}
    	for (int u = 0; u < n; u++) {
    		dp[2 * i + 2][u] = 1;
    	}
    	for (int u = 0; u < n; u++) {
    		for (int v : e[u]) {
    			dp[2 * i + 2][v] = min(dp[2 * i + 2][v], dp[2 * i + 1][u]);
    		}
    	}
    }
    cout << (dp[2 * k][0] ? "Bob" : "Alice") << endl;
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
