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
    vvi dp(6, vi(6));
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[0][1] = 2;
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 6; j++) {
    		if (i + j <= 1) {
    			continue;
    		}
    		for (int k = 0; k <= i; k++) {
    			for (int l = 0; l <= j; l++) {
    				if (k != i || l != j) {
    					dp[i][j] += dp[k][l];
    				}
    			}
    		}
    	}
    }
    vector<array<int, 4>> ans;
    function<void(vi&, int, int, int)> play = [&] (vi& a, int L, int x, int y) {
    	if (x == 5 && y == 5) return;
    	//cout << a.size() << L << " " << x << " " << y << endl;
    	if (x + y == 9 && a.size() == 2) {
    		if (a[0] > a[1]) {
    			ans.push_back({x, y, (x == 5 ? 0 : 1), 2});
    		} else {
    			ans.push_back({x, y, (x == 5 ? 0 : 1), 1});
    			ans.push_back({x, y, (x == 5 ? 0 : 1), 1});
    		}
    		return;
    	}
    	assert(a.size() <= dp[5-x][5-y]);
    	set<pii> s;
    	int cur = L;
    	vi F(36);
    	for (int i = x; i < 6; i++) {
    		for (int j = y; j < 6; j++) {
    			if (i == x && j == y) continue;
    			s.insert({cur, i * 6 + j});
    			F[i * 6 + j] = cur;
    			cur += dp[5 - i][5 - j];
    		}
    	}
    	vvi e(36);
    	int m = a.size();
    	for (int i = m - 1; i >= 0; i--) {
    		int v = a[i];
    		auto it = s.upper_bound({v, 45});
    		--it;
    		int z = it -> second;
    		int xx = z / 6;
    		int yy = z % 6;
    		for (int i = x; i < xx; i++) {
    			ans.push_back({i, y, 1, 1});
    		}
    		for (int i = y; i < yy; i++) {
    			ans.push_back({xx, i, 0, 1});
    		}
    		e[z].push_back(v);
    	}
    	for (int i = 35; i >= 0; i--) {
    		if (e[i].size()) {
    			//cout << "???" << i << " " << L << " " << x << " " << y << endl;
    			play(e[i], F[i], i / 6, i % 6);
    		}
    	}
    };
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    play(a, 1, 0, 0);
    for (int i = 0; i < ans.size(); i++) {
    	auto [x, y, z, w] = ans[i];
    	cout << x + 1 << " " << y + 1 << " " << (z ? 'D' : 'R') << " " << w << endl;
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
