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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    auto f = [&](int z, int y, int x, int w) {
    	int tot = 0;
    	if (z == x && z == w) {
    		tot ++;
    	}
    	if (y == x && y == w) {
    		tot ++;
    	}
    	if (z == y && (z == x || z == w)) {
    		tot ++;
    	}
    	return min(2, tot);
    };
    int ans = 0;
    for (int i = 1; 2 * i <= n - 1; i++) {
    	ans += f(a[i], a[n - 1 - i], a[i-1], a[n - i]);
    }
    if (n % 2 == 0 && a[n / 2] == a[n/2-1] ) {
    	ans ++;
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
