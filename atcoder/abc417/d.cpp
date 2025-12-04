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
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 3; j++) {
    		cin >> a[i][j];
    	}
    }
    vvl dp(n+1, vl(1001));
    for (int i = 0; i <= 1000; i++) {
    	dp[n][i] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
    	for (int j = 0; j <= 1000; j++) {
    		if (j > a[i][0]) {
    			dp[i][j] = dp[i+1][max(0, j - a[i][2])];
    		} else {
    			dp[i][j] = dp[i+1][j + a[i][1]];
    		}
    	}
    }
    set<pii> s;
    s.insert({0, -1});
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	tot += a[i][2];
    	s.insert({tot, i});
    }
    int q;
    cin >> q;
    while (q--) {
    	int x;
    	cin >> x;
    	if (x >= 1000) {
    		int target = x - 1000;
    		auto it = s.lower_bound({target, 0});
    		if (it == s.end()) {
    			auto it2 = s.end();
    			--it2;
    			cout << x - (it2 -> first) << endl; 
    		} else {
    			auto [z, y] = *it;
    			cout << dp[y+1][x - z] << endl;
    		}
    	} else {
    		cout << dp[0][x] << endl;
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
