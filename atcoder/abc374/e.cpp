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
    int n, x;
    cin >> n >> x;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 4; j++) {
    		cin >> a[i][j];
    	}
    }
    auto check = [&] (ll m) {
    	ll tot = 0;
    	ll y = x;
    	for (int i = 0; i < n; i++) {
    		auto [A, p, B, q] = a[i];
    		ll minn = 1e18;
    		for (int j = 0; j <= y / p; j++) {
    			ll need = m - j * A;
    			if (need < 0) {
    				minn = min(minn, 1ll * j * p);
    				break;
    			};
    			minn = min(minn, 1ll * ((need + B - 1) / B) * q + 1ll * j * p); 
    		
    		}
    		y -= minn;
    		if (y < 0) {
    			return false;
    		}
    	}
    	return true; 
    };
    ll l = 0;
    ll r = 1e9;
    while (l < r) {
    	ll m = (l + r + 1) / 2;
    	if (check(m)) {
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
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
