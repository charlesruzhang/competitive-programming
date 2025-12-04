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
    ll k;
    cin >> k;
    ll l = 1;
    ll r = 1e15;
    auto check = [&] (ll m) {
    	ll y = m;
    	int cnt = 0;
    	while (m) {
    		cnt++;
    		m /= 10;
    	}
    	ll cur = 9;
    	ll tot = 0;
    	for (int i = 1; i < cnt; i++) {
    		tot += cur * i;
    		cur *= 10;
    	}
    	cur /= 9;
    	tot += 1ll * (y - cur) * cnt;
    	return k - tot; 
    };
    ll last;
    while (l < r) {
    	ll m = (l + r + 1) / 2;
    	ll rem = check(m);
    	if (rem >= 0) {
    		last = rem;
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    l--;
    function <ll(ll)> f = [&] (ll L) {
    	if (L <= 0) {
    		return 0ll;
    	}
    	int z = L % 10;
    	ll ans = f(L / 10 - 1) * 10 + (L / 10) * 45;
    	for (ll i = (L / 10) * 10; i <= (L / 10) * 10 + z; i++) {
    		string s = to_string(i);
    		for (int j = 0; j < s.size(); j++) {
    			ans += s[j] - '0';
    		}
    	}
    	return ans;
    };
    ll ans = f(l);
    string t = to_string(l+1);
    assert(t.size() > last);
    for (int i = 0; i < last; i++) {
    	ans += t[i] - '0';
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
