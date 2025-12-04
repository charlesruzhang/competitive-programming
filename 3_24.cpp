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
struct T {
	int x, y, idx;
};
void solve() {
	int n, k, c;
	cin >> n >> k >> c;
	if (k > n) k = n;
	vector<T> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].y;
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i].x;
		p[i].idx = i;
	}
	sort(p.begin(), p.end(), [&](T a, T b) {
		return a.x < b.x;
	});
	ll summ = 0;
	for (int i = 0; i < k; i++) {
		summ += p[i].x;
		if (summ > c) {
			cout << i << endl;
			return;
		}
	}
	int l = k;
	int r = n - 1;
	function <bool(int)> check = [&](int m) {
		vector<T> q;
		for (int i = 0; i < m; i++) {
			q.push_back(p[i]);
		}
		sort(q.begin(), q.end(), [](T a, T b) {
			return a.y - a.x > b.y - b.x;
		});
		ll summ = 0;
		for (int i = 0; i < k; i++) {
			summ += q[i].x;
		}
		for (int i = k; i < m; i++) {
			summ += q[i].y;
		}
		if (summ < c) return true;
		return false;
	};
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
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
