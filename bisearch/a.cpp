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
    int l, r;
    cin >> l >> r;
    r -= l;
    if (r == 0) {
    	cout << 1 << endl;
    	return;
    }
    int L = 1;
    int R = 1e5;
    while (L < R) {
    	int m = (L + R + 1) / 2;
    	if (1ll * m * (m - 1) / 2 <= r) {
    		L = m;
    	} else {
    		R = m - 1;
    	}
    }
    cout << L << endl;
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
