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
const int INF = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vvi vs(n, vi(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			vs[i][j] = s[j] - '0';
		}
	}
	vvi ans(n, vi(n));
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (j == i + 1) {
				ans[i][j] = vs[i][j];
			} else {
				int x = 0;
				for (int k = i + 1; k < j; k++) {
					x = (x + vs[i][k] * ans[k][j]) % 10;
				}
				if (x == vs[i][j]) {
					ans[i][j] = 0;
				} else {
					ans[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
		}
		cout << endl;
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
