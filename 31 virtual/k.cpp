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
int query(int idx) {
	cout << "buf[" << idx << "]" << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
	int res = 1;
	ll cur = 1;
	ll ans = 0;
	while (res) {
		cur *= 2;
		res = query(cur);
	}
	ll l = cur / 2;
	ll r = cur - 1;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (!query(mid)) {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
    cout << "strlen(buf) = " << l + 1 << endl;
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
