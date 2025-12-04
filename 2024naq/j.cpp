#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pll = pair<ll, ll>;

void solve() {
	int n;
	cin >> n;
	int x1, x2, y1, y2, z1, z2;
	cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
	ll a1 = 0, a2 = x2, an = x1;
	ll b1 = 0, b2 = y2, bn = y1;
	ll c1 = 0, c2 = z2, cn = z1;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		long double ma1 = (2 * a1 + a2) / 3;
		long double ma2 = (a1 + 2 * a2) / 3;
		if (an < ma2 && an > ma1) {
			cnt++;
			a1 = ma1;
			a2 = ma2;
		} else if (ma2 <= an) {
			a1 = ma2;
		} else {
			a2 = ma1;
		}

		ll mb1 = (2 * b1 + b2) / 3;
		ll mb2 = (b1 + 2 * b2) / 3;
		if (bn < mb2 && bn > mb1) {
			cnt++;
			b1 = mb1;
			b2 = mb2;
		} else if (mb2 <= bn) {
			b1 = mb2;
		} else {
			b2 = mb1;
		}

		long double mc1 = (2 * c1 + c2) / 3;
		long double mc2 = (c1 + 2 * c2) / 3;
		if (cn < mc2 && cn > mc1) {
			cnt++;
			c1 = mc1;
			c2 = mc2;
		} else if (mc2 <= cn) {
			c1 = mc2;
		} else {
			c2 = mc1;
		}

		// cout << i << " " << cnt << endl;
		// cout << i << " " << ma1 << " " << ma2 << " " << an << endl;
		// cout << i << " " << mb1 << " " << mb2 << " " << bn << endl;
		// cout << i << " " << mc1 << " " << mc2 << " " << cn << endl;
		if (cnt >= 2) {
			cout << 0 << endl;
			return;
		}
	}
	cout << 1 << endl;
}

int main() {

	solve();
	return 0;
}