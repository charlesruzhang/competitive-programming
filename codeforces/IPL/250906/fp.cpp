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
    list<array<int, 3>> a;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (a.size() && a.back()[0] == x) {
    		auto [v, cnt, y] = a.back();
    		a.pop_back();
    		a.push_back({x, cnt + 1});
    	} else {
    		a.push_back({x, 1});
    	}
    }
    vvi ans;
    int idx = 0;
    while (a.size() >= 2) {
    	auto it = a.begin();
    	ans.push_back({});
    	while (it != a.end()) {
    		int off = 0;
    		auto [v, cnt, y] = *it;
    		if (it != a.begin()) {
    			--it;
    			auto [w2, cnt2, y2] = *it;
    			if (w2 > v) {
    				off++;
    			}
    			++it;
    		}
    		if (next(it) != a.end()) {
    			++it;
    			auto [w2, cnt2, y2] = *it;
    			if (w2 > v) {
    				off++;
    			}
    			--it;
    		}
    		(*it)[2] = min(cnt, off);
    		cnt = max(cnt - off, 0);
    		(*it)[1] = cnt;
    		++it;
    	}
    	it = a.begin();
    	while (it != a.end()) {
    		auto [v, cnt, off] = *it;
    		off = (*it)[2];
    		for (int i = 0; i < off; i++) {
    			ans[idx].push_back(v);
    		}
    		if (cnt == 0) {
    			auto it2 = next(it);
    			a.erase(it);
    			it = it2;
    		} else {
    			if (it != a.begin()) {
					auto it2 = prev(it);
					auto [v2, cnt2, off2] = *it2;
					if (v2 == v) {
						cnt += cnt2;
						a.erase(it2);
					}
					(*it)[1] = cnt;
    			}
    			++it;
    		}
    	}
    	++idx;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	for (int j = 0; j < ans[i].size(); j++) {
    		cout << ans[i][j] << " ";
    	}
    	cout << endl;
    }
    int x = a.front()[0];
    int cnt = a.front()[1];
    for (int i = 0; i < cnt; i++) {
    	cout << x << " ";
    }
    cout << endl;
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