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
    ll n;
    cin >> n;
    map<ll, ll> ma;
    function <ll(ll)> f = [&] (ll x) {
    	if (x <= 1) return 0ll;
    	auto it = ma.find(x);
    	if (it != ma.end()) {
    		return it -> second;
    	}
    	ll ret = x + f(x / 2) + f((x + 1) / 2);
    	ma[x] = ret;
    	return ret;
    };
    cout << f(n) << endl;
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
