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
    auto it = upper_bound(pr.begin(), pr.end(), m - 40);
    int P;

    if (it == pr.begin()) {
        P = 1;
    } else {
        --it;
        P = *it;
    }
    it = upper_bound(pr.begin(), pr.end(), n - 40);
    int Q;
    if (it == pr.begin()) {
        Q = 1;
    } else {
        --it;
        Q = *it;
    }
    
    ll maxx = 0;
    //cout << P << " " << Q << endl;
    vvi dp(m - P + 1, vi(n - Q + 1));
    for (int i = P; i <= m; i++) {
    	for (int j = Q; j <= n; j++) {
    		if (gcd(i, j) == 1 && ((i == P || dp[i-P-1][j-Q]) || (j == Q || dp[i-P][j - Q - 1]))) {
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
