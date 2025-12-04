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
    int n;
    ll l, r;
    cin >> n >> l >> r;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    int cur = 0;
    for (int i = 1; i <= n / 2; i++) {
    	cur += a[i];
    }
    if (n % 2 == 0) {
    	a.push_back(cur % 2);
    	n++;
    }
    vi pref(n + 2);
    for (int i = 1; i <= n; i++) {
    	pref[i + 1] = pref[i] ^ a[i];
    }
    function <int(ll)> g = [&] (ll x) {
    	// if (x <= n) {
    	// 	return a[x];
    	// }
    	if (x / 2 <= n) {
    		return pref[x / 2 + 1];
    	}
    	if ((x / 2) % 2 == 0) {
    		return pref[n + 1] ^ g(x / 2);
    	} else {
    		return pref[n + 1];
    	}
    };
    cout << g(l) << endl;
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
