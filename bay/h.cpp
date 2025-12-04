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
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	int m = s.size();
	int cur = x;
	for (int i = 0; i < m; i++) {
		int d = floor(log2(cur));
		if (s[i] == 'U') {
			if (cur == 1) {
				cout << -1 << endl;
				return;
			}
			int D;
			if (cur & (1 << (d - 1))) {
				D = 1 << d;
			} else {
				D = 1 << (d - 1);
			}
			cur = cur - D;
			continue;
		} else if (s[i] == 'L') {
			// mod (1 << d) == cur
			int cnt = (n - cur) / (1 << d);
			if (cnt % 2) {
				cur += (1 << d);
			} else {
				cur += (1 << (d + 1));
			}
			if (cur > n) {
				cout << -1 << endl;
				return;
			}
		} else {
			int cnt = (n - cur) / (1 << d);
			if (cnt % 2 == 0) {
				cur += (1 << d);
			} else {
				cur += (1 << (d + 1));
			}
			if (cur > n) {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << cur << endl;
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
