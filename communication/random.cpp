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
    for (int i = 0; i < (1 << n); i++) {
    	for (int j = 0; j < n; j++) {
    		for (int k = 0; k < n; k++) {
    			// verify that j and k are set in the states.
    			dp[i][j] = min(dp[i][j], dp[i ^ (1 << k)][k] + dist[j][k]);
    		}
    	}
    }
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
