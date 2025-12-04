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
	vi a(n);
	vvi p(1e5+1, vi(2));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[a[i]][i%2]++;
	}
	vi b = a;
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		p[b[i]][i%2]--;
	}
	for (int i = 1; i <= (1e5); i++) {
		if (p[i][0] || p[i][1]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
