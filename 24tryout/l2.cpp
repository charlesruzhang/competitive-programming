#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

int k;
ll f(ll x) {
	return (x + k - 1) / k;
}
void solve() {
	cin >> k;
	vl c(8);
	for (int i = 1; i <= 7; i++) {
		cin >> c[i];
	}
	swap(c[5], c[6]);
	ll ans = 1e18;
	// ans = min(ans, f(c[1] + c[4]) + max(f(c[2]) + f(c[3] + c[6]), f(c[2] + c[3] + c[6] + c[5] + c[7])));
	// ans = min(ans, f(c[1] + c[6]) + max(f(c[2] + c[4]) + f(c[3]), f(c[2] + c[3] + c[4] + c[5] + c[7])));

	// ans = min(ans, f(c[2] + c[4]) + max(f(c[1]) + f(c[3] + c[5]), f(c[1] + c[3] + c[6] + c[5] + c[7])));
	// ans = min(ans, f(c[2] + c[5]) + max(f(c[1] + c[4]) + f(c[3]), f(c[1] + c[3] + c[4] + c[6] + c[7])));

	// ans = min(ans, f(c[3] + c[5]) + max(f(c[2]) + f(c[1] + c[6]), f(c[2] + c[1] + c[6] + c[4] + c[7])));
	// ans = min(ans, f(c[3] + c[6]) + max(f(c[2] + c[5]) + f(c[1]), f(c[2] + c[1] + c[4] + c[5] + c[7])));

	// ans = min(ans, f(c[3] + c[6] + c[7]) + max(f(c[2] + c[5]) + f(c[1]), f(c[2] + c[1] + c[4] + c[5] + c[7])));
	
	for (int i = 1; i <= 3; i++) {
		for (int j = 4; j <= 6; j++) {
			if (i + j == 7) continue;
			vl tmp = c;
			int rem = c[i] % k;
			int other = i + 8 - j;
			ll tot = c[i] / k;
			auto find = [&]() {
				vl T = tmp;
				ll best = 1e18;
				if (i == 3) {
					T[1] += T[5];
					T[2] += T[6];
					T[4] += T[7];
					best = min(best, max(f(T[1] + T[2] + T[4]), f(T[1]) + f(T[2])));
				} else if (i == 2) {
					T[1] += T[4];
					T[3] += T[6];
					T[5] += T[7];
					best = min(best, max(f(T[1] + T[3] + T[5]), f(T[1]) + f(T[3])));
				} else if (i == 1) {
					T[2] += T[4];
					T[3] += T[5];
					T[6] += T[7];
					best = min(best, max(f(T[2] + T[3] + T[6]), f(T[2]) + f(T[3])));
				}
				//cout << i << " " << j << " " << best << endl;
				return best;
			};
			if (rem > 0) {
				tot++;
				if (rem + tmp[other] >= k) {
					tmp[other] -= k - rem;
					rem = 0;
				} else {
					rem += tmp[other];
					tmp[other] = 0;
					if (rem + tmp[7] >= k) {
						tmp[7] -= k - rem;
						rem = 0;
					} else {
						tmp[7] = 0;
					}
				}
			}
			ans = min(find() + tot, ans);
		}
	}
	cout << ans << endl;
}


int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}