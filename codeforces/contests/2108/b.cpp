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
    int n, x;
    cin >> n >> x;
    function <int(int, int)> solver = [&](int n, int x) {
    	if (x == 0) {
	    	if (n % 2 == 1) {
	    		if (n == 1) {
	 				return -1;
	    		}
	    		return 6 + n - 3; 
	    	} else {
	    		return n;
	    	}
	    }
	    int y = x;
	    int cnt = 0;
	    while (y > 0) {
	    	cnt += y % 2;
	    	y /= 2;
	    }
	    if (x == 1) {
	    	if (n % 2 == 1) {
	    		return n;
	    	}
	    	return n - 2 + 5;
	    }
	    if (n <= cnt) {
	    	return x;
	    }
	    if ((n - cnt) % 2 == 1) {
	    	return n - cnt + x + 1;
	    }
	    return n - cnt + x;
    };
    cout << solver(n, x) << endl;

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
