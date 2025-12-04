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
    vi cnt(5001);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	a[i] = min(a[i], 5000);
    	cnt[a[i]]++;
    }
    int mex = -1;
    for (int i = 0; i <= 5000; i++) {
    	if (!cnt[i]) {
    		mex = i;
    		break;
    	}
    }
    if (mex == 0) {
    	cout << 0 << endl;
    	return;
    }
    ll minn = 1e18;
    vi dp(5001);
    for (int i = mex - 1; i >= 0; i--) {
    	dp[i] = mex * (cnt[i] - 1) + i;
    	for (int j = i + 1; j < mex; j++) {
    		dp[i] = min(dp[i], dp[j] + j * (cnt[i] - 1) + i);
    	}
    }
    cout << dp[0] << endl;

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
