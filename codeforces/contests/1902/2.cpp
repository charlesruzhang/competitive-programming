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
	ll n, P, l, t;
	cin >> n >> P >> l >> t;
	ll mt = (n + 6) / 7; 
    ll d = (P - 1) / (l + 2 * t) + 1;
    ll ans = 0;
    if (d * 2 > mt && (P - mt * t - 1) >= 0) {
    	ans = (P - mt * t - 1) / l + 1;  
    } else {
    	ans = d;
    }
    cout << n - ans << endl;
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
