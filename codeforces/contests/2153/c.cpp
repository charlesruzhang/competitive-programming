// By Auchenai01
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
const int INF = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    map<int, int, greater<>> ma;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	ma[a[i]]++;
    }
    auto it = ma.begin();

    ll tot = 0;
    ll D = 0;
    while (it != ma.end()) {
    	auto [x, y] = *it;
    	D += (y - y % 2);
    	tot += 1ll * x * (y - y % 2);
    	y = y % 2;
    	it -> second = y;
    	++it;
    }
    it = ma.begin();
    while (it != ma.end()) {
    	while (it != ma.end() && it -> second == 0) {
    		++it;
    	}
    	auto it2 = next(it);
    	while (it2 != ma.end() && it2 -> second == 0) {
    		++it2;
    	}
    	ll r = (it == ma.end() ? 0 : it -> first);
    	ll l = (it2 == ma.end() ? 0 : it2 -> first);
    	if (r >= l + tot) {
    		it = it2;
    	} else {
    		cout << r + l + tot << endl;
    		return;
    	}
    }
    if (D == 2) {
    	cout << 0 << endl;
    	return;
    }
    cout << tot << endl;
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
