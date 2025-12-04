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
int N = 5000;
vector<vector<ld>> dp(N + 1, vector<ld>(N));
void comp() {
	for (int i = 1; i <= N; i++) {
		dp[i][0] = ((ld)1 / i);
		for (int j = 1; j < i; j++) {
			if (j >= 2) dp[i][j] += (((ld) j - 1) / i) * dp[i-2][j-2];
			dp[i][j] += (((ld) i - j - 1) / i) * dp[i-2][j-1];
			//if (i <= 10) cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
}
void solve() {
    int n, m;
    cin >> n >> m;
    vvi children(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	children[u].push_back(v);
    }
    vector<ld> ans(n);
    ans[n-1] = 1;
    for (int i = n - 2; i >= 0; i--) {
    	sort(children[i].begin(), children[i].end(), [&](int a, int b) {
    		return ans[a] > ans[b];
    	});
    	int z = children[i].size();
    	for (int j = 0; j < z; j++) {
    		ans[i] += dp[z][j] * ans[children[i][j]];
    	}
    }
    cout << setprecision(20) << ans[0] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
