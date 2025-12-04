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
    vvi a(n, vi(n));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
    	}
    }
    vvi valid(n, vi(n));
    pii even = {n / 2 - 1, n / 2 - 1};
    pii odd = {n / 2 - 1, n / 2 - 1};
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if ((i + j) % 2 == 0) {
    			int x = min(i, n - 2 - i);
    			int y = min(j, n - 2 - j);
    			if (min(x, y) % 4 == 0 || min(x,y) % 4 == 1) {
    				valid[i][j] = 1;
    			}
    		} else {
    			int x = min(i, n - 2 - i);
    			int y = min(j - 1, n - 1 - j);
    			if (min(x, y) % 4 == 0 || min(x,y) % 4 == 1) {
    				valid[i][j] = 1;
    			}
    		}
    	}
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (valid[i][j]) {
    			ans ^= a[i][j];
    		}
    	}
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
