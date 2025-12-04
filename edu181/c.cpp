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
    ll l, r;
    cin >> l >> r;
    vi a = {2, 3, 5, 7, 30, 105, 70, 42};
    vi b = {6, 10, 14, 15, 21, 35, 210};
    ll ans = r - l + 1;
    for (int v : a) {
    	ans -= r / v - (l - 1) / v;
    }
    for (int w : b) {
    	ans += r / w - (l - 1) / w;
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
