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
    int n;
    cin >> n;
    ll ans = 0;
    vl a(n), b(n);
    vector<pll> c(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    	ans += b[i] - a[i];
    	c[i] = {a[i] + b[i], i};
    }
    sort(c.begin(), c.end());
    ll maxx = 0;
    ll minn = 1e9+7;
    for (int i = 0; i < n / 2; i++) {
    	ans -= a[c[i].second];
    	maxx = max(a[c[i].second], maxx);
    }
    for (int i = (n + 1) / 2; i < n; i++) {
    	ans += b[c[i].second];
    	minn = min(b[c[i].second], minn);
    }
    if (n % 2) {
    	ll m2x = 0;
		m2x = max(m2x, maxx - a[c[n/2].second]);
		m2x = max(m2x, - minn + b[c[n/2].second]);
		ans += m2x;
    }
    cout << ans << endl;
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
