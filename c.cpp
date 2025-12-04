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
    cin >> n;
    vi a(n);
    vi v(2e5+1);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	v[a[i]]++;
    	maxx = max(maxx, a[i]);
    }
    vi pref(2e5+2);
    for (int i = 0; i <= 2e5; i++) {
    	pref[i+1] = pref[i] + v[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < i; j++) {
    		int l = abs(a[j] - a[i]) + 1;
    		int r = abs(a[j] + a[i]) - 1;
    		l = max(l, maxx + 1 - a[i] - a[j]);
    		if (l > r) continue;

    		ans += pref[r + 1] - pref[l];
    		if (a[i] <= r && a[i] >= l) ans--;
    		if (a[j] <= r && a[j] >= l) ans--;
    	}
    }
    cout << ans / 3 << endl;
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
