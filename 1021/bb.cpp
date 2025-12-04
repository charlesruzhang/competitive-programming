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
    ll n, a, b;
    cin >> n >> a >> b;
    if (n < a) {
    	cout << 0 << endl;
    	return;
    }
    if (a <= b) {
    	cout << n - a + 1 << endl;
    	return;
    }
    ll ans = 0;
    ll tmp = (n % a >= b) ? b: ((n % a) + 1);
    ans = (n / a - 1) * b + tmp;
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
