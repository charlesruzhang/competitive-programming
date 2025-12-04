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
    int n, m;
    cin >> n >> m;
    // int tot = 0;
    // // for (int i = 2; i <= m; i++) {
    // // 	int x = m;
    // // 	while (x >= i) {
    // // 		x /= i;
    // // 		tot ++;
    // // 	}
    // // }
    // cout << tot << endl;
    vector<pii> res;
    res.push_back({m, 0});
    vi best(m + 560, 0);
    for (int i = n; i >= 2; i--) {
    	int x = m;
    	int cnt = 0;
    	while (x >= i) {
    		x /= i;
    		cnt++;
    	}
    	vector<pii> res2;
    	int sz = res.size();
    	auto [xz, y] = res.back();
    	int cur = 1;
    	for (int j = 0; j <= cnt; j++) {
    		for (auto [x, y] : res) {
    			int z = x % cur;
    			best[y + j] = max(best[y+j], x - z - 1);
    		}
    		cur *= i;
    	}
    	for (int j = y + sz + cnt - 1; j >= y; j--) {
    		if (best[j] < i - 1) continue;
    		res2.push_back({best[j], j});
    		if (res2.size() >= 20) break;
    	}
    	for (int j = y; j < y + sz + cnt; j++) {
    		best[j] = 0;
    	}
    	swap(res2, res);
        // for (auto [x, y] : res) {
        //     cout << i << " " << x << " " << y << endl;
        // }
    }
    cout << res[0].second << endl;
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
