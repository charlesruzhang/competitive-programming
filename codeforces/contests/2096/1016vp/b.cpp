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
	int n, k;
	cin >> n >> k;
	if (k > 1 && n > 1) {
		cout << "NO" << endl;
		return;
	}
	if (k == 1 && n == 1) {
		cout << "NO" << endl;
		return;
	}
	if (k > 1) {
		n = 0;
		int cur = 1;
		for (int i = 0; i < k; i++) {
			n += cur;
			cur *= 10; 
		}
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
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
