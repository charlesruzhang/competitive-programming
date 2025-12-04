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
    vi a(n);
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi loc(n+1);
    vi dp(n+1);

    for (int i = 0; i < n; i++) {
    	loc[a[i]].push_back(i);
    	dp[i+1] = dp[i];
    	if (loc[a[i]].size() >= a[i]) {
    		dp[i+1] = max(dp[i+1], dp[loc[a[i]][loc[a[i]].size() - a[i]]] + a[i]);
    	}
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
