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
    int x;
    ll m;
    cin >> x >> m;
    ll ans = 0;
    for (int i = 1; i <= min(1ll * x, m); i++) {
    	int y = x ^ i;
    	if (y % i == 0 || y % x == 0) {
    		ans++;
    	}
    }
    ll t = m / x;
    if (t > 0) ans += t - 1;
    if (t > 0 && ((t * x) ^ x) > m) {
    	ans--;
    }
    if (((((t + 1) * x) ^ x) <= m) && ((((t+1) * x) ^ x) > 0)) {
    	ans++;
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
