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
	int n, a, b;
	cin >> n >> a >> b;
	vi arr;
	if (n % b == 1) {
		cout << "YES" << endl;
		return;
	}
	while (n && (n % a == 0 || n > b)) {
		if (n % a == 0) {
			n /= a;
			if (n % b == 1) {
				cout << "YES" << endl;
				return;
			}
		} else {
			n -= b;
		}
		
	}
	cout << "NO" << endl;
	return;
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
