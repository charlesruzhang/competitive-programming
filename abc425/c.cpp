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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll off = 0;
    vl pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	if (x == 1) {
    		int c;
    		cin >> c;
    		off += c;
    	} else {
    		ll l, r;
    		cin >> l >> r;
    		l--; r--;
    		l += off; r += off;
    		l %= n; r %= n;
    		if (r < l) {
    			cout << pref[n] - (pref[l] - pref[r+1]) << endl;
    		} else {
    			cout << pref[r + 1] - pref[l] << endl;
    		}
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
