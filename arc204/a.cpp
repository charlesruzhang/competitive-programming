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
    int n, k;
    cin >> n >> k;
    vi a(n * k + 1);
    for (int i = 1; i <= n * k; i++) {
    	cin >> a[i];
    }
    vvi loops;
    vi marked(n * k + 1);
    for (int i = 1; i <= n * k; i++) {
    	if (marked[i]) continue;
    	int cur = i;
    	int first = 1;
    	vi tmp;
    	while (first || cur != i) {
    		marked[cur] = 1;
    		first = 0;
    		tmp.push_back(cur);
    		cur = a[cur];
    	}
    	loops.push_back(move(tmp));
    }
    int ans = 0;
    auto find = [&](vi &b) {
    	int m = b.size();
    	vvi dp(m, vi(m));
    	vvi vs(n);
    	for (int i = 0; i < m; i++) {
    		//cout << (b[i] % n) << " ";
    		vs[b[i] % n].push_back(i);
    	}
    	//cout << endl;
    	for (int d = 1; d < m; d++) {
    		for (int i = 0; i < m - d; i++) {
    			int j = i + d;
    			dp[i][j] = dp[i+1][j];
    			int y = b[i] % n;
    			for (int k = 0; k < vs[y].size(); k++) {
    				if (vs[y][k] <= i || vs[y][k] > j) continue;
    				int z = vs[y][k];
					dp[i][j] = max(dp[i][j], 1 + dp[i][z-1] + dp[z][j]);
    			}
    		}
    	}
    	ans += dp[0][m-1];
    };

    for (int i = 0; i < loops.size(); i++) {
    	find(loops[i]);
    }
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
