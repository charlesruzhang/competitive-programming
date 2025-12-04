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
    int p;
    cin >> p;
    deque<pii> q;
    while (p--) {
    	int z;
    	cin >> z;
    	if (z == 1) {
    		int c, x;
    		cin >> c >> x;
    		q.push_back({c, x});
    	} else {
    		int k;
    		cin >> k;
    		ll ans = 0;
    		while (k > 0) {
    			auto [x, y] = q.front();
    			int zz = min(k, x);
    			k -= zz;
    			x -= zz;
    			ans += 1ll * zz * y;
    			q.pop_front();
    			if (x) q.push_front({x, y});
    		}
    		cout << ans << endl;
    	}
    }
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
