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
    int x, y, z;
    ll k;
    cin >> x >> y >> z >> k;
    ll ans = 0;
    for (int i = 1; i <= x; i++) {
    	ll Z = k;
    	if (Z % i == 0) {
    		Z /= i;
	    	for (int j = 1; j <= y; j++) {
	    		if (Z % j == 0) {
	    			Z /= j;
	    			if (Z <= z) {
	    				ans = max(ans, 1ll * (x - i + 1) * (y - j + 1) * (z - Z + 1));
	    			}
	    			Z *= j;
	    		}
	    	}
	    	Z *= i;
    	}
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
