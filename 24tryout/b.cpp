#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

void solve() {
	int n, H;
	cin >> n >> H;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		vi a(3);
		for (int j = 0; j < 3; j++) {
			cin >> a[j];
		}
		sort(a.begin(), a.end());
		for (int j = 2; j >= 0; j--) {
			if (a[j] <= H) {
				if (j > 0) {
					ans += a[0];
				} else {
					ans += a[1];
				}
				break;
			} else if (j == 0) {
				cout << "impossible" << endl;
				return;
			}
		}
	}
	cout << ans << endl;
}


int main() {
	solve();
	return 0;
}