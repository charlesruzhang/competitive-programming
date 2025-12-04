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
void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1) {
    	cout << l << endl;
    	return;
    }
    if (n == 2) {
    	cout << -1 << endl;
    	return;
    }
    int idx = 0;
    for (int i = 61; i >= 0; i --) {
    	if ((1ll << i) & l) {
    		idx = i;
    		break;
    	}
    }
    if ((1ll << (idx + 1)) > r) {
    	cout << -1 << endl;
    } else {
    	if (k == n || k == n - 1) {
    		cout << (1ll << (idx + 1)) << endl;
    	} else {
    		cout << l << endl;
    	}
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
