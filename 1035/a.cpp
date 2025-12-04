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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) {
    	if (a % 2 == 1 && b == a - 1) {
    		cout << y << endl;
    	} else {
    		cout << -1 << endl;
    	}
    	return;
    }
    ll tot = 0;
    for (int i = a + 1; i <= b; i++) {
    	if (i % 2 == 1) {
    		tot += min(x, y);
    	} else {
    		tot += x;
    	}
    }
    cout << tot << endl;
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
