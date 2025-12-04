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
	vector<vvi> a(n, vvi(n, vi(n)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> a[i][j][k];
			}
		}
	}
	vvi e(n+1);
	for (int i = 0; i < (1 << (2 * n)); i++) {
		int z = i >> n;
		int x = __builtin_popcount(z);
		if (x * 2 != __builtin_popcount(i)) continue;
		e[x].push_back(i);
	}
	vl ans((1 << 2 * n), 1e18);
	ans[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i-1].size(); j++) {
			int z = e[i-1][j];
			for (int k = 0; k < n; k++) {
				if ((1 << (k + n)) & z) continue;
				for (int l = 0; l < n; l++) {
					if ((1 << l) & z) continue;
					int y = (z ^ (1 << (k + n))) ^ (1 << l);
					ans[y] = min(ans[y], ans[z] + a[i-1][k][l]);
				}
			}
		}
	}
	cout << ans[(1 << (2 * n)) - 1] << endl;
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
