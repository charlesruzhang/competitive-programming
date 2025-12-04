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
    vi a(2 * n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	a[n+i] = a[i];
    }
    vl dp(2 * n + 1, MAXX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
    	dp[i+1] = min(dp[i - 1] + abs(a[i] - a[i-1]), dp[i+1]);
    	if (i >= 2) {
    		vi v = {a[i], a[i-1], a[i-2]};
    		sort(v.begin(), v.end());
    		dp[i+1] = min(dp[i-2] + v[2] - v[0], dp[i+1]);
    	}
    }
    vl ndp(2 * n + 1, MAXX);
    ndp[1] = 0;
    for (int i = 2; i < n + 1; i++) {
    	ndp[i+1] = min(ndp[i - 1] + abs(a[i] - a[i-1]), ndp[i+1]);
    	if (i >= 3) {
    		vi v = {a[i], a[i-1], a[i-2]};
    		sort(v.begin(), v.end());
    		ndp[i+1] = min(ndp[i-2] + v[2] - v[0], ndp[i+1]);
    	}
    }
    vl nndp(2 * n + 1, MAXX);
    nndp[2] = 0;
    for (int i = 3; i < n + 2; i++) {
    	nndp[i+1] = min(nndp[i - 1] + abs(a[i] - a[i-1]), nndp[i+1]);
    	if (i >= 4) {
    		vi v = {a[i], a[i-1], a[i-2]};
    		sort(v.begin(), v.end());
    		nndp[i+1] = min(nndp[i-2] + v[2] - v[0], nndp[i+1]);
    	}
    }
    cout << min(nndp[n+2], min(dp[n], ndp[n+1])) << endl;
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
