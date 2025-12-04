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
    int n, m, l;
    cin >> n >> m >> l;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi vec(l, vi(m));
    for (int i = 0; i < l; i++) {
    	for (int j = 0; j < m; j++) {
    		for (int k = i; k < n; k += l) {
    			vec[i][j] += (a[k] > j) ? (m + j - a[k]) : (j - a[k]);
    		}
    	}
    }
    vi dp(m, INF);
    dp[0] = 0;
    for (int i = 0; i < l; i++) {
    	vi ndp(m, INF);
    	for (int j = 0; j < m; j++) {
			for (int t = 0; t < m; t++) {
				int z = (j + t) % m;
				ndp[z] = min(ndp[z], dp[j] + vec[i][t]);
			}
    	}
    	swap(ndp, dp);
    }
    cout << dp[0] << endl;
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
