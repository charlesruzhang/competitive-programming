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
const ll MAXX = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll maxx = -MAXX;
    ll minn = MAXX;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	maxx = max(maxx, a[i]);
    	minn = min(minn, a[i]);
    	tot += a[i];
    }
    if ((tot + (n - 2) * maxx) < 0 || (tot + (n-2) * minn) > 0) {
    	cout << "INF" << endl;
    	return;
    }
    sort(a.begin(), a.end());
    int p, q;
    if (n % 2 == 1) {
    	p = (n - 1) / 2;
		q = p;
    } else {
    	p = (n - 1) / 2;
    	q = n / 2;
    }
    vector<ll> pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    auto f = [&](int x) {
    	ll t = a[x];
    	ll ans = -(a[0] - t) * (a[n-1] - t);
    	ans += (a[n-1] - t) * (pref[x] - x * t);
    	ans += (a[0] - t) * ((pref[n] - pref[x+1]) - (n - x - 1) * t);
		ans -= (n - 1) * (t * t);
		return ans;
    };
    ll res = -MAXX;
    for (int i = 0; i < n; i++) {
    	res = max(res, f(i));
    }
    cout << res << endl;
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
