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
    int n, m;
    cin >> n >> m;
    int flag = 0;
    if (n > m) {
    	swap(n, m);
    	flag = 1;
    }
    int x = 1;
    int y = 1;
    vector<pii> ans;
    pii cent = {(n + 1) / 2, (m + 1) / 2};
    ans.push_back(cent);
    while (x < n || y < m) {
    	int xx = (x + 1) / 2;
    	int yy = (y + 1) / 2;
    	if (y < m) {
    		int idx = 0;
	    	while (idx * 2 + 1 < x + 2) {
	    		if (idx) {
	    			ans.push_back({cent.first - idx, cent.second - yy});
	    			ans.push_back({cent.first - idx, cent.second + yy});
	    		}
	    		ans.push_back({cent.first + idx, cent.second - yy});
	    		ans.push_back({cent.first + idx, cent.second + yy});
	    		idx++;
	    	}
	    	y += 2;
    	}
		if (x < n) {
			int idx = 0;
	    	while (idx * 2 + 1 < y + 2) {
	    		if (idx) {
	    			ans.push_back({cent.first - xx, cent.second - idx});
	    			ans.push_back({cent.first + xx, cent.second - idx});
	    		}
	    		ans.push_back({cent.first - xx, cent.second + idx});
	    		ans.push_back({cent.first + xx, cent.second + idx});
	    		idx++;
	    	}
	    	x += 2;
    	}
    }
    for (int i = 0; i < ans.size(); i++) {
    	if (!flag) cout << ans[i].first << " " << ans[i].second << endl;
    	else cout << ans[i].second << " " << ans[i].first << endl;
    }
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
