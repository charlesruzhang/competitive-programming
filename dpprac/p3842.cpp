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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	int l, r;
    	cin >> l >> r;
    	a[i] = {l, r};
    }
    vvi dp(n, vi(2));
    auto [l, r] = a[0];
    dp[0][0] = (r - 1) + (r - l);
    dp[0][1] = (l - 1) + (r - l);
    for (int i = 1; i < n; i++) {
    	auto [L, R] = a[i - 1];
    	auto [l, r] = a[i];
    	dp[i][0] = min(abs(r - L) + 1 + r - l + dp[i - 1][0], abs(r - R) + 1 + r - l + dp[i - 1][1]);
    	dp[i][1] = min(abs(l - L) + 1 + r - l + dp[i - 1][0], abs(l - R) + 1 + r - l + dp[i - 1][1]);
    } 
    auto [L, R] = a[n - 1];
    cout << min(dp[n - 1][0] + abs(n - L), dp[n - 1][1] + abs(n - R)) << endl;
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
