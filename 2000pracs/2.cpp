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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (n == 2) {
    	int x = max(a[1], a[0]);
    	cout << max(a[1] + a[0], abs(a[1] - a[0]) * 2) << endl;
    	return;
    } else if (n == 3) {
    	ll ans = max(3ll * a[0], 3ll * a[2]);
    	ans = max(ans, (ll)a[0] + a[1] + a[2]);
    	ans = max(ans, 2ll * (abs(a[0] - a[1])) + a[2]);
    	ans = max(ans, 3ll * (abs(a[0] - a[1])));
    	ans = max(ans, 3ll * (abs(a[2] - a[1])));
    	ans = max(ans, 2ll * (abs(a[2] - a[1])) + a[0]);
    	cout << ans << endl;
    	return;
    } else {
    	int x = *max_element(a.begin(), a.end());
    	cout << 1ll * x * n << endl;
    	return;
    }
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
