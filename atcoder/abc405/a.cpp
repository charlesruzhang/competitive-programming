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
    int n, x;
    cin >> n >> x;
    if (x == 1) {
    	if (n <= 2999 && n >= 1600) {
    		cout << "Yes" << endl;
    	} else {
    		cout << "No" << endl;
    	}
    } else {
    	if (n <= 2399 && n >= 1200) {
    		cout << "Yes" << endl;
    	} else {
    		cout << "No" << endl;
    	}
    }
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
