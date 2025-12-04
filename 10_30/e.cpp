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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    d++;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    vl ans(n);
    ll A = MAXX;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
    	set<pll> s;
    	vl dp(m + 1);
    	dp[0] = 1;
    	s.insert({1, 0});
    	for (int j = 1; j < m; j++) {
    		dp[j] = (*s.begin()).first + 1 + a[i][j];
    		s.insert({dp[j], j});
    		if (s.size() > d) {
    			assert(j >= d);
    			s.erase({dp[j-d], j - d});
    		}
    	}
    	ans[i] = dp[m-1];
    	cur += dp[m-1];
    	if (i >= k) {
    		cur -= ans[i - k];
    	}
    	if (i >= k - 1) {
    		A = min(A, cur);
    	}
    
    }
    cout << A << endl;
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
