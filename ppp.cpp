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
    int n, m;
    cin >> n >> m;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    int s = sqrt(n);
    vector<ll> block(s+1);
    for (int i = 0; i < s; i++) {
    	ll summ = 0;
    	for (int j = (i * s); j < (i * s + s); j++) {
    		summ += a[j];
    	}
    	block[i] = summ;
    }
    for (int i = 0; i < m; i++) {
    	int l, r; 
    	cin >> l >> r;
    	ll ans = 0;
    	for (int j = l; j <= r; j++) {
    		int x = l ^ (j / s);
			int lb = ((x & (-x)) == 1) ? -1 : 1;
    		ans += a[j] * lb;
    	}
    	cout << ans << endl;
    	// if (r == n) {
    	// 	int lb = ((l ^ s) & (-(l ^ s)) == 1) ? -1 : 1;
    	// 	ans += a[n] * lb;
    	// 	r--;
    	// }
    	// int l2 = (l + s - 1) / s;
		// int x = l ^ (l2 - 1);
		// int lb = ((x & (-x)) == 1) ? -1 : 1;
    	// for (int j = l; j < l2 * s; j++) {
    	// 	ans += a[j] * lb;
    	// }
    	// int r2 = (r + 1) / s;
    	// x = l ^ (r2);
    	// lb = ((x & (-x)) == 1) ? -1 : 1;
    	// for (int j = (r2 * s); j <= r; j++) {
    	// 	ans += a[j] * lb;
    	// }
    	// for (int j = l2; j < r2; j++) {
    	// 	x = l ^ j;
    	// 	lb = ((x & (-x)) == 1) ? -1 : 1;
    	// 	ans += block[j] * lb;
    	// }
    	// cout << ans << endl;
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
