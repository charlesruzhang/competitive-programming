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
    ll n;
    cin >> n;
    ll ans = 0;
    function <ll(ll)> comp = [&] (ll x) {
        ll y = 1;
        ll anss = 0;
        while (y <= x) {
            ll z = x / y;
            while (z) {
                z/=2;
                anss++;
            }
            y *= 5;
        }
        return anss;
    };
    function <ll(ll)> f = [&] (ll vx) {
        return (vx / 10) * 4 + (vx % 10 >= 1) + (vx % 10 >= 3) + (vx % 10 >= 7) + (vx % 10 >= 9);
    };
    for (ll i = 1, j; i <= n; i = j) {
        if (1ll * i * i <= n) {
            j = i + 2;
            if (i % 5 != 0) {
                ans += 1ll * (n / i) * (comp(n / i));
            }
        } else {
            ll v = min(n / (n / i), n);
            ll count = f(v) - f(i-1);
            j = v + 1;
            ans += 1ll * count * (n / i) * (comp(n / i));
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
