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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int c = 0; c < n; c++) {
    	cin >> a[c];
    }
    sort(a.begin(), a.end(), greater<>());
    int l = 0;
    int r = 1e6 + 1;
    auto check = [&] (int m ) {
    	ll tot = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] < m + k) break;
    		tot += a[i] - m - k;
    	}

    	ll tot2 = 0;
    	for (int i = n - 1; i >= 0; i--) {
    		if (a[i] >= m) break;
    		tot2 += m - a[i];
    	}
    	if (tot >= tot2) return true;
    	else return false;
    };
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	if (check(m)) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }

    int m = l;
    ll tot = 0;
	ll ans = 0;
	vi b = a;
	for (int i = 0; i < n; i++) {
		if (a[i] < m + k) break;
		tot += a[i] - m - k;
		a[i] = m + k;
	}

	ll tot2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] >= m) break;
		tot2 += m - a[i];
		a[i] = m;
	}
	assert(tot - tot2 < n);
	int tar = tot - tot2;
	for (int i = 0; i < tot - tot2; i++) {
		if (a[i] >= m + k) {
			a[i]++;
			tar--;
		} else {
			break;
		}
	}
	for (int i = n - 1; i >= 0; i --) {
		if (tar <= 0) break;
		a[i]++;
		tar--;
		tot2++;
	}
	// for (int i = 0; i < n; i++) {
	// 	if (b[i] >= m && a[i] > b[i]) {
	// 		tot2++;
	// 	}
	// }
	for (int i = 0; i < n; i++) {
		ans += 1ll * a[i] * (a[i] + 1) / 2;
	}
	ans += 1ll * k * tot2;
	//cout << m << " ? " << tot2 << endl;
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
