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
    vl a(n);
    vector<pair<ll, int>> b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cin >> b[i].first;
    	b[i].second = i;
    }
    sort(b.begin(), b.end(), greater<>());
    ll ans = 0;
    ll tot = 0;
    ll ans2 = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
    	while (b[j].first <= tot) {
    		tot += a[b[j].second];
    		ans += a[b[j].second];
    		j--;
    		if (i > j) break;
    	}
    	if (i > j) break;
    	if (a[b[i].second] + tot > b[j].first) {
    		ll tmp = b[j].first - tot;
    		tot += tmp;
    		ans += 2 * tmp;
    		a[b[i].second] -= tmp;
    	} else {
    		tot += a[b[i].second];
    		ans += 2 * a[b[i].second];
    		i++;
    	}
    }
    cout << ans << endl;
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
