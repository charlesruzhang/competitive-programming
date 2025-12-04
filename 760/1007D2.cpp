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
    ll l, r;
    cin >> n >> l >> r;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    int cur = 0;
    for (int i = 1; i <= n / 2; i++) {
    	cur += a[i];
    }
    if (n % 2 == 0) {
    	a.push_back(cur % 2);
    	n++;
    }
    vi pref(n + 2);
    for (int i = 1; i <= n; i++) {
    	pref[i + 1] = pref[i] ^ a[i];
    }
    function <int(ll)> g = [&] (ll x) {
    	if (x <= n) {
    		return a[x];
    	}
    	if (x / 2 <= n) {
    		return pref[x / 2 + 1];
    	}
    	if ((x / 2) % 2 == 0) {
    		return pref[n + 1] ^ g(x / 2);
    	} else {
    		return pref[n + 1];
    	}
    };
    function <ll(ll)> f = [&] (ll x) {
    	if (x <= n) {
    		ll c = 0;
    		for (int i = 1; i <= x; i++) {
    			c += a[i];
    		}
    		return c;
    	}
    	ll ans = cur;
    	ll L = -1;
    	for (int i = n / 2 + 1; i <= n; i++) {
    		ll l = 2 * i;
    		ll r = 2 * i + 1;
    		ll tot = a[i];
    		ll prev = a[i];
    		while (l <= x) {
    			if (r > x) {
    				L = l;
    				break;
    			}
    			ll sz = (r - l + 1) / 2;
    			int head = g(l - 1);
    			if (head) {
    				if (prev % 2 == 1) {
    					prev = 0;
    				} else {
    					prev += (sz - prev) * 2;
    				}
    			} else if (prev % 2 == 1) {
    				prev = 2;
    			}
    			tot += prev;
    			l *= 2;
    			r = 2 * r + 1;
    		}
    		ans += tot;
    	}
    	if (L == -1) {
    		return ans;
    	}
    	//cout << x << " , " << ans << endl;
    	ll Z = x - L + 1;
    	for (int i = 60; i >= 0; i--) {
    		if (Z & (1ll << i)) {
    			ll l = L >> i;
    			ll r = l;
    			ll prev = g(l);
    			l *= 2;
    			r = 2 * r + 1;
    			for (int j = 1; j <= i; j++) {
    				ll sz = 1ll << (j - 1);
    				int head = g(l - 1);
	    			if (head) {
	    				if (prev % 2 == 1) {
	    					prev = 0;
	    				} else {
	    					prev += (sz - prev) * 2;
	    				}
	    			} else if (prev % 2 == 1) {
	    				prev = 2;
	    			}
	    			l *= 2;
	    			r = 2 * r + 1;
    			}
    			ans += prev;
    			L += 1ll << i;
    		}
    	}
    	return ans;
    };
    //cout << f(r) << " " << f(l-1) << endl;
    cout << f(r) - f(l - 1) << endl;
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
