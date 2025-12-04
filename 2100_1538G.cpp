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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b) {
    	cout << min(x, y) / a << endl;
    	return;
    }
    if (a < b) {
    	swap(a, b);
    }
    int l = 0;
    int r = (x + y) / (a + b);
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	ll p, q;
    	if (a * 1ll * m - y <= 0) {
    		p = 0;
    	} else {
    		p = ((a * 1ll * m - y - 1) / (a - b)) + 1;
    	}
    	if (x - b * 1ll * m < 0) {
    		q = -1;
    	} else {
    		q = (x - b * 1ll * m) / (a - b);
    	}
    	q = min(q, (ll) m);
    	if (p <= q) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    cout << l << endl;
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
