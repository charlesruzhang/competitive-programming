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
ll rev(ll x) {
	vi res;
	ll xx = x;
	while (x) {
		res.push_back(x % 2);
		x /= 2; 
	}
	ll tot = 0;
	for (int y : res) {
		tot = tot * 2 + y;
	}
	//cout << xx << " ? ??" << tot << endl;
	return tot;
}
bool find(ll x, ll y) {
	int z = 64 - __builtin_clzll(x);
	int w = 64 - __builtin_clzll(y);
	ll yp = rev(y);
	if (64 - __builtin_clzll(yp) != w) {
		return false;
	}
	//cout << z << " " << x << " " << w << " " << y << endl;
	for (int i = 0; i < 61; i++) {
		int j = w - z - i;
		//cout << i << " " << j << endl;
		if (j < 0) break;
		ll first = (1ll << i) - 1;
		ll second = (1ll << j ) - 1;
		if ((first << (z + j)) + (x << j) + second == y) {
			return true;
		}
		if ((first << (z + j)) + (x << j) + second == yp) {
			return true;
		}
	} 
	return false;
}
void solve() {
    ll x, y;
    cin >> x >> y;
    if (find(rev(2 * x + 1), y) || find(rev(x), y) || x == y) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
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
