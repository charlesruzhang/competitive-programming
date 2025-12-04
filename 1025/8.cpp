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
    int m, d, w;
    cin >> m >> d >> w;
    int wp = w / gcd(d - 1, w);
    m = min(m, d);
    int q = m / wp;
    int z = m % wp;
    ll ans = 1ll * z * (q + 1) * q / 2 + 1ll * (wp - z) * q * (q - 1) / 2; 
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
