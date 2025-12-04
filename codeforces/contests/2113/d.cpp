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
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
	function <bool(int)> check = [&] (int m) {
		int minn = 1e9;
		int sminn = 1e9;
		int idx = -1;
		for (int i = 0; i < m; i++) {
			if (a[i] < minn) {
				sminn = minn;
				minn = a[i];
				idx = i;
			} else if (a[i] < sminn) {
				sminn = a[i];
			}
		}
		int maxx = 0;
		for (int i = m; i < n; i++) {
			maxx = max(a[i], maxx);
		}
		if (maxx > sminn) {
			minn = sminn;
			sminn = maxx;
		} else if (maxx > minn) {
			minn = maxx;
		}

		int bminn = 1e9;
		for (int i = 0; i <= n - m; i++) {
			bminn = min(bminn, b[i]);
		}

		if (minn >= bminn) {
			return true;

		} else {
			return false;
		}
	};
	int l = 0;
	int r = n;
	while (l < r) {
		int m = (l + r + 1) / 2;
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
