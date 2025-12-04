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
    int n, m, k;
    cin >> n >> m >> k;
    int l = 1; 
    int r = m;
    auto check = [&](int mi) {
    	if (1ll * n * (m - m / (mi + 1)) >= k) {
    		return true;
    	} else {
    		return false;
    	}
    };
    while (l < r) {
    	int mi = (l + r) / 2;
    	if (check(mi)) {
    		r = mi;
    	} else {
    		l = mi + 1;
    	}
    }
    cout << l << endl;
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
