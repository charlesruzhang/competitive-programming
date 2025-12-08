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
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = 0; i < min(k, 32ll); i++) {
    	ll x = n & (-n);
    	n += x;

    	ll y = n & (-n);
    	ll z = y / x;
    	ans += __lg(z);
    }
    k -= min(k, 32ll);
    ans += k;
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
