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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	string s;
    	cin >> s;
    	if (s == "->") {
    		int x, y;
    		cin >> x >> y;
    		x--; y--;
    		int cur = 0;
    		ll ans = 0;
    		while (cur < n) {
    			ll w = (1ll << (n - cur - 1));
    			int xx = x / w;
    			int yy = y / w;
    			ll z = (1ll << (2 * (n - cur - 1)));
    			if (xx && yy) {
    				ans += z;
    			} else if (xx) {
    				ans += 2 * z;
    			} else if (yy) {
    				ans += 3 * z;
    			}
    			x %= w;
    			y %= w;
    			cur++;
    		}
    		cout << ans + 1 << endl;
    	} else {
    		ll d;
    		cin >> d;
    		d--;
    		int cur = 0;
    		ll xx = 0;
    		ll yy = 0;
    		while (cur < n) {
    			ll w = (1ll << (n - cur - 1));
    			int x = d >> (2 * (n - cur - 1));
    			if (x == 1) {
    				xx += w;
    				yy += w;
    			} else if (x == 2) {
    				xx += w;
    			} else if (x == 3) {
    				yy += w;
    			}
    			d -= x * (1ll << (2 * (n - cur - 1)));
    			cur++;
    		}
    		cout << xx + 1 << " " << yy + 1 << endl;
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
