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
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl b;
    for (int i = 0; i < n; i++) {
    	while (b.size() && a[b.back()] >= a[i]) {
    		b.pop_back();
    	}
    	b.push_back(i);
    }
    set<pll> s;
    for (int i = 0; i < b.size(); i++) {
    	s.insert({a[b[i]], i});
    }
    int m = b.size();
    vl dp(m+1, MAXX);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
    	dp[i+1] = min(dp[i+1], 1+dp[i]);
    	ll z = (a[b[i]] + 1) / 2;
    	auto it = s.lower_bound({z, -1});
    	auto [x, y] = *it;
    	dp[i+1] = min(dp[i+1], 2 + dp[y]);

    	z = (a[b[i]] + 2) / 3;
    	it = s.lower_bound({z, -1});
    	auto [xx, yy] = *it;
    	dp[i+1] = min(dp[i+1], 3 + dp[yy]);
    }
    cout << dp[m] << endl;
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
