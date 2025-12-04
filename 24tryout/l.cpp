#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

void solve() {
	int k;
	cin >> k;
	vl c(8);
	for (int i = 1; i <= 7; i++) {
		cin >> c[i];
	}
	ll minn = 1e18;
	ll dans = c[1] / k;
	ll eans = c[1] / k;
	c[1] = c[1] % k;
	vl d = c;
	vl e = c;
	ll ans = 1e18;
	if (d[4] + d[1] >= k) {
		d[4] -= k - d[1];
		d[2] += d[4];
		d[3] += d[6];
		d[7] += d[5];
	} else {
		d[1] += d[4];
		d[4] = 0;
		if (d[6] + d[1] >= k) {
			d[6] -= k - d[1];
			d[3] += d[6];
			d[7] += d[5];
		} else {
			d[1] += d[6];
			d[6] = 0;
			if (d[7] + d[1] >= k) {
				d[7] -= k - d[1];
				d[7] += d[5];
			} else {
				d[7] = d[5];
			}
		}
	}
	ans = min(ans, min(1 + (d[2] + k - 1) / k + (d[3] + k - 1) / k, 1 + (d[2] + d[3] + d[7] + k - 1) / k));
	cout << ans + eans - (c[1] == 0 ? 1 : 0) << endl;
}


int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}