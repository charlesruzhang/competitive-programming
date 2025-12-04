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
    vi a(n);
    vvi V(22);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	for (int j = 21; j >= 0; j--) {
    		if ((a[i] >> j) & 1) {
    			V[j].push_back(a[i]);
    			break;
    		}
    	}
    }
    vi dp(22);
    int ans = 0;
    for (int i = 0; i < 22; i++) {
    	for (int x : V[i]) {
    		dp[i] = max(dp[i], 1);
    		for (int j = i - 1; j >= 0; j--) {
    			if ((x >> j) & 1) continue;
    			dp[i] = max(dp[i], dp[j] + 1);
    		}
    	}
    	ans = max(ans, dp[i]);
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
