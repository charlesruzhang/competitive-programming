#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

void solve() {
	int n, w;
	cin >> n >> w;
	vector<array<int, 3>> store;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "!") {
			int p, l, a;
			cin >> p >> l >> a;
			store.push_back({p, l, a});
		} else {
			int x;
			cin >> x;
			ll ans = 0;
			for (auto [p, l, a] : store) {
				if (!(p + l - 1 >= x && p <= x)) continue;
				if (x % 4 == p % 4) {
					ans += a;
				} else if (x % 4 == (p + 2) % 4) {
					ans -= a;
				}
			}
			cout << ans << endl;
		}
	}
}


int main() {
	solve();
	return 0;
}