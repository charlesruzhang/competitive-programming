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
    string s;
    cin >> s;
    int n = s.size();
    ll cur = 0;
    set<pll> S;
    ll l = 0, r = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '-') {
    		l = cur;
    		cur = 0;
    	} else if (s[i] == ',') {
    		r = cur;
    		cur = 0;
    		S.insert({l, -1});
    		S.insert({r, 1});
    	} else {
    		cur *= 10;
    		cur += s[i] - '0';
    	}
    }
    r = cur;
    S.insert({l, -1});
    S.insert({r, 1});
    set<ll> T;
    for (int i = 1; i <= 1000000; i++) {
    	ll x = i;
    	ll y = x; 
    	ll tot = 1;
    	while (y) {
    		y /= 10;
    		tot *= 10;
    	}
    	while (x <= 1e13) {
    		x = x * tot + i;
	    	auto it = S.lower_bound({x, 0});
	    	if (it == S.end()) continue;
	    	auto [p, id] = *it;
	    	if (id == 1) {
	    		T.insert(x);
	    	}
    	}
    }
    for (ll x : T) {
    	ans += x;
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
