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
void solve() {
    int a;
    ll n;
    cin >> a >> n;
    ll cur = 0;
    ll z = 1;
    set<ll> s;
    ll ans = 0;
    while (cur <= n) {
    	vi vec;
    	ll x = z;
    	while (x) {
    		vec.push_back(x % 10);
    		x /= 10;
    	}
    	reverse(vec.begin(), vec.end());
    	vi w = vec;
    	int m = w.size();
    	for (int i = 0; i < m; i++) {
    		w.push_back(w[m - i - 1]);
    	}
    	ll t = 0;
    	for (int i = 0; i < w.size(); i++) {
    		t = 10 * t + w[i];
    	}
    	if (t <= n && s.find(t) == s.end()) {
    		s.insert(t);
    		vi v2;
    		ll u = t;
    		while (t) {
    			v2.push_back(t % a);
    			t /= a;
    		}
    		vi w2 = v2;
    		reverse(w2.begin(), w2.end());
    		if (v2 == w2) {
    			ans+= u;
    		}
    	}
    	for (int i = 0; i < m - 1; i++) {
    		vec.push_back(vec[m - i - 2]);
    	}
    	t = 0;
    	for (int i = 0; i < vec.size(); i++) {
    		t = 10 * t + vec[i];
    	}
    	ll u = t;
    	if (t <= n && s.find(t) == s.end()) {
    		s.insert(t);
    		vi v2;
    		while (t) {
    			v2.push_back(t % a);
    			t /= a;
    		}
    		vi w2 = v2;
    		reverse(w2.begin(), w2.end());
    		if (v2 == w2) {
    			ans+=u;
    		}
    	}
    	cur = u;
    	z++;
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
