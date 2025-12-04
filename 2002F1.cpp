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
const int N = 20000000;
vector<int> lp(N+1);
vector<int> pr;

void sieve() {
	for (int i=2; i <= N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j = 0; i * pr[j] <= N; ++j) {
	        lp[i * pr[j]] = pr[j];
	        if (pr[j] == lp[i]) {
	            break;
	        }
	    }
	}
}
void solve() {
    int n, m, l, f;
    cin >> n >> m >> l >> f;
    if (l > f) swap(l, f);
    auto it = upper_bound(pr.begin(), pr.end(), n);
    --it;
    int P = *it;
    int Q;
    if (it != pr.begin()) {
    	--it;
    	Q = *it;
    } else {
    	Q = 1;
    }
    ll maxx = 0;
    if (Q <= 20) {
    	vvi dp(n+1, vi(m+1));
    	dp[0][0] = 1;
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= m; j++) {
	    		if (gcd(i, j) == 1 && ((i && dp[i-1][j]) || (j && dp[i][j - 1]))) {
	    			dp[i][j] = 1;
	    			maxx = max(maxx, 1ll * j * l + 1ll * i * f);
	    		}
    		}
    	}
    	cout << maxx << endl;
    	return;
    } 
    vvi dp(n - P + 1, vi(n - Q + 1));
    for (int i = P; i <= n; i++) {
    	dp[i-P][0] = 1;
    	maxx = max(maxx, 1ll * Q * l + 1ll * i * f);
    }
    for (int i = Q; i < P; i++) {
		dp[0][i-Q] = 1;
		maxx = max(maxx, 1ll * i * l + 1ll * P * f);
    }
    for (int i = P+1; i <= n; i++) {
    	for (int j = Q+1; j <= n; j++) {
    		if (gcd(i, j) == 1 && (dp[i-P-1][j-Q] || dp[i-P][j - Q - 1])) {
    			dp[i-P][j-Q] = 1;
    			maxx = max(maxx, 1ll * j * l + 1ll * i * f);
    		}
    	}
    }
    cout << maxx << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
