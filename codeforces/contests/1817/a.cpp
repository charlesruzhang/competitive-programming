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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi mark(n);
    for (int i = 2; i < n; i++) {
    	if (a[i-2] >= a[i-1] && a[i-1] >= a[i]) {
    		mark[i] = 1;
    	}
    }
    vi pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + mark[i];
    }
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int ans = pref[r+1] - pref[l];
    	if (mark[l]) {
    		ans--;
    	}
    	if (l != r && mark[l+1]) {
    		ans--;
    	}
    	cout << r - l + 1 - ans << endl;
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
