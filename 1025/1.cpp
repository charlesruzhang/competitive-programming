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
void solve() {
    int n;
    cin >> n;
    vi l(n), r(n);
    for (int i = 0; i < n; i++) {
    	cin >> l[i] >> r[i];
    }
    vi p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b) {
    	if (l[a] == l[b]) {
    		return r[a] < r[b];
    	}
    	return l[a] < l[b];
    });
    vi dp(n+1);
    dp[n-1] = 1;
    for (int i = n - 2; i >= 0; i --) {
    	int best = 1e9;
    	int idx = -1;
    	int res = i;
    	for (int j = i + 1; j < n; j++) {
    		if (l[p[j]] <= r[p[i]]) {
    			if (best > r[p[j]]) {
    				best = r[p[j]];
    				idx = j;
    			}
    			res = j;
    		} else {
    			break;
    		}
    	}
    	dp[i] = dp[i+1] + 1;
    	int res2 = i;
    	if (res != i) {
    		for (int j = i + 1; j < n; j++) {
    			if (l[p[j]] <= max(r[p[i]], r[p[idx]])) {
    				res2 = j;
    			}
    		}
    		dp[i] = min(dp[i], dp[res2+1] + (res2 - i) - 1); 
    	}
    	//cout << i << ", " << dp[i] << " , " << l[p[i]] << " , " << r[p[i]] << " . " << res << " ? " << res2 <<  endl;
    }
    cout << dp[0] << endl;
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
