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
int query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int l = 2;
    int r = 999;
    while (l < r) {
    	int m1 = (2 * l + r + 1) / 3;
    	int m2 = (l + 2 * r + 2) / 3;
    	int res = query(m1, m2);
    	if (res == m1 * m2) {
    		l = m2 + 1;
    	} else if (res == (m1 + 1) * (m2 + 1)) {
    		r = m1;
    	} else {
    		l = m1 + 1;
    		r = m2;
    	}
    }
    cout << "! " << l << endl;
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
