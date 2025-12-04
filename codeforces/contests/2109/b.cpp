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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    function <int(int, int)> f = [&] (int x, int y) {
    	int z = 0;
    	while (y > 1) {
    		y = y - y / 2;
    		z ++;
    	}
    	while (x > 1) {
    		x = x - x / 2;
    		z ++;
    	}
    	return z;
    };
    int res = 1 + min(f(n, min(m - b + 1, b)), f(min(n - a + 1, a), m));
    cout << res << endl;
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
