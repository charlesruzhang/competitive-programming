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
    int n;
    cin >> n;
    ll w;
    cin >> w;
    vector<priority_queue<ll>> vpq(61);
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	vpq[x].push(y);
    }
    ll tot = 0;
    ll res = 0;
    vector<priority_queue<ll, vl, greater<>>> ans(61);
    for (int i = 59; i >= 0; i--) {
    	while (vpq[i].size() && tot + (1ll << i) <= w) {
    		ll y = vpq[i].top();
    		vpq[i].pop();
    		ans[i].push(y);
    		res += y;
    		tot += (1ll << i);
    	}
    }

    for (int i = 0; i < 60; i++) {
    	while (1) {
	    	if (!ans[i].size() || !vpq[i].size() || ans[i].top() >= vpq[i].top()) {
	    		while (vpq[i].size() >= 2) {
	    			ll x = vpq[i].top();
	    			vpq[i].pop();
	    			ll y = vpq[i].top();
	    			vpq[i].pop();
	    			vpq[i+1].push(x+y);
	    		}
	    		if (vpq[i].size() == 1) {
	    			ll x = vpq[i].top();
	    			vpq[i].pop();
	    			vpq[i+1].push(x);
	    		}
	    		break;
	    	} else {
	    		ll prev = ans[i].top();
	    		ans[i].pop();
	    		ll now = vpq[i].top();
	    		vpq[i].pop();
	    		ans[i].push(now);
	    		vpq[i].push(prev);
	    		res += now - prev;
	    	}
    	}
    }
    cout << res << endl;
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
