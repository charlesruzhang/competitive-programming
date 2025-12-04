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
    int n;
    cin >> n;
    vi x(n), y(n);
    int mx = -1, my = -1;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    	mx = max(mx, x[i]);
    	my = max(my, y[i]);
    	tot += 1ll * x[i] * y[i];
    }
    auto check = [&] (ll X, ll Y) {
    	priority_queue<array<int, 3>> pq;
    	priority_queue<array<int, 3>> pq2;
    	vi used(n);
    	for (int i = 0; i < n; i++) {
	    	pq.push({x[i], y[i], i});
	    	pq2.push({y[i], x[i], i});
    	}
    	int cnt = 0;
    	while (cnt < n) {
    		while (pq.size() && used[pq.top()[2]]) {
    			pq.pop();
    		}
    		while (pq2.size() && used[pq2.top()[2]]) {
    			pq2.pop();
    		}
    		int done = 0;
    		if (pq.size()) {
    			auto [x, y, z] = pq.top();
    			//cout << "1 : " << x << " " << y << " " << z << endl;
    			if (x == X) {
    				used[z] = 1;
    				cnt++;
    				pq.pop();
    				Y -= y;
    				continue;
    			}
    		}
			if (pq2.size()) {
    			auto [y, x, z] = pq2.top();
    			//cout << "2 : " << x << " " << y << " " << z << endl;
    			if (y == Y) {
    				used[z] = 1;
    				cnt++;
    				pq2.pop();
    				X -= x;
    				continue;
    			}
    		}
    		return false;
    	}
    	return true;
    };
    vector<pll> ans;
    if (tot % mx == 0) {
    	int flag = check(mx, tot / mx);
    	if (flag) ans.push_back({mx, tot / mx});
    }
    if (tot % my == 0 && 1ll * mx * my != tot) {
    	int flag = check(tot / my, my);
    	if (flag) ans.push_back({tot / my, my});
    }
    cout << ans.size() << endl;
    for (auto [x, y]: ans) {
    	cout << x << " " << y << endl;
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
