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
#define endl '\n';
const ll MOD = 998244353;
const ll MAXX = 1e16;
void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    if (l == r) {
    	if (l != 1) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    	return;
    }
    auto f = [&] (int x) {
    	return (x + 1) / 2;
    };
    int y = f(r) - f(l-1);
    if (k >= y) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
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
