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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi x;
    vi mark(n);
    for (int i = 0; i < n; i++) {
    	if (!x.size() || a[i] > x.back()) {
    		x.push_back(a[i]);
    		mark[i] = 1;
    	}
    }
    vvi dp(k + 1, vi(k + 1));
    int prev = 0;
    for (int i = 0; i < n; i++) {
    	if (mark[i]) {
    		vvi ndp = dp;
    		for (int j = a[i]; j > prev; j--) {
    			for (int l = 0; l < j; l++) {
    				for (int t = 0; t + j <= k; t++) {
    					ndp[j][t + j] = max(ndp[j][t+j], dp[l][t] + (j - l) * (n - i));
    				}
    			}
    		}
    		prev = a[i];
    		swap(dp, ndp);
    	}
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
    	ans = max(ans, dp[i][k]);
    }
    cout << ans << endl;
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
