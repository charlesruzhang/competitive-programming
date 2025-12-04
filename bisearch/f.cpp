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
    ll m;
    cin >> n >> m;
    vector<pll> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
    	cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	ll tot = a[i].first * a[i].second;
    	ans = max(ans, min(tot, m / a[i].first * a[i].first));
    }
    for (int i = 1; i < n; i++) {
    	if (a[i].first - a[i-1].first == 1) {
    		ll a2 = 0;
    		ll tot1 = a[i-1].first * a[i-1].second;
    		ll tot2 = a[i].first * a[i].second;
    		
    		ll now = (tot2 > m / a[i].first * a[i].first) ? (m / a[i].first * a[i].first) : tot2;
    		ll u2 = now / a[i].first;
    		ll off = m - now;
    		ll z = off / a[i-1].first;
			ll used = min(a[i-1].second, z);
			ll left = a[i-1].second - used;
			off %= a[i-1].first;
			if (((a[i-1].first - off) % (a[i-1].first)) <= min(left - 1,u2) ) {
				a2 = m;
			} else {
				a2 = now + used * a[i-1].first;
			}
    		ans = max(ans, a2);
    	}
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
