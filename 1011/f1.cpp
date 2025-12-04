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
void solve(ll xx, ll yy) {
	ll x = xx;
	ll y = yy;
    if (x == y) {
    	cout << -1 << endl;
    	return;
    }
    ll tot = 0;
    ll prev = 0;
    for (int i = 0; i < 31; i++) {
    	int p = (x & (1ll << i));
    	int q = (y & (1ll << i));
    	if (p && q) {
    		if (!prev) prev = (1ll << i);
    		tot += prev;
	    	x += prev;
	    	y += prev;
	    	prev = 0;
    	}
    	p = (x & (1ll << i));
    	q = (y & (1ll << i));
    	if (!p && !q) {
    		if (prev) prev += (1ll << i);
    	} else {
    		prev = (1ll << i);
    	}
    }
    assert((x + y) == (x ^ y));
    //cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			solve(i,j);
		}
	}
    return 0;
}
