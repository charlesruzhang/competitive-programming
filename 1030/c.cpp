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
void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
    	ans += __builtin_popcount(a[i]);
    }
    for (int i = 0; i < 62; i++) {
    	for (int j = 0; j < n; j++) {
    		if (a[j] & (1ll << i)) continue;
	    	if (k >= (1ll << i)) {
	    		k -= (1ll << i);
	    		ans++;
	    		a[j] += (1ll << i);
	    	} else {
	    		cout << ans << endl;
	    		return;
	    	}
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
