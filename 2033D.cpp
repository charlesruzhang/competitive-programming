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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll tot = 0;
    map<ll, int> ma;
    ma[0] = 0;
    vi dp(n+1);
    for (int i = 0; i < n; i++) {
    	tot += a[i];
    	dp[i+1] = dp[i];
    	auto it = ma.find(tot);
    	if (it != ma.end()) {
    		auto [x, y] = *it;
    		dp[i+1] = max(dp[i+1], dp[y] + 1);
    	}
    	ma[tot] = i + 1;
    }
    cout << dp[n] << endl;
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
