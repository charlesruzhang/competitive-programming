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
const int m = 500;
vi x(m+1);
void prep() {
	for (int i = 1; i <= m; i++) {
		x[i] = (i - 1) * i / 2;
	}
}
void solve() {
	int k;
	cin >> k;
    int xx = m;
    int a = 0, b = 0;
    int dir = 0;
    vector<pii> ans;
    ans.push_back(pii(a,b));
    while (k > 0) {
    	if (x[xx] <= k) {
    		k -= x[xx];
    		for (int i = 0; i < xx - 1; i++) {
    			if (dir) {
    				b--;
    			} else {
    				a--;
    			}
    			ans.push_back(pii(a,b));
    		}
    		dir = 1 - dir;
    	} else {
    		xx--;
    	}
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first << " " << ans[i].second << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    prep();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
