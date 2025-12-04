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
    int x, y;
    cin >> x >> y;
    if (x == y) {
    	cout << x << endl;
    	return;
    }
    if (x > y) {
    	cout << x + y << endl;
    	return;
    }
    int z = y / 2 + 1;
    int w = z % x;
    int z2 = y - z;
    int z3 = z2 % x;
    if (z3 < w) {
    	z3 += x;
    }
    int t = (z3 + w) / 2;
    cout << t << " "  << w << endl;
    cout << y - t << endl;
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
