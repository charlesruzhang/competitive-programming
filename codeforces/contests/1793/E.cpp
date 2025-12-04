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
    set<int, greater<>> s;
    s.insert(-1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] <= i + 1) {
            s.insert(i);    
        }
    }
    vi dp(n);
    vi ans(n+1);
    for (int i = 0; i < n; i++) {
    	if (a[i] > i + 1) {
    		ans[n - a[i] + 1] = max(ans[n - a[i] + 1], i + 1);
    	} else {
            int z = *(s.lower_bound(i - a[i]));
            dp[i] = (z == -1 ? 1 : dp[z] + 1);
            ans[dp[i] + n - i - 1] = max(ans[dp[i] + n - i - 1], i + 1);
        }
    	if (i) dp[i] = max(dp[i], dp[i-1]);
    }
    for (int i = n - 1; i >= 2; i--) {
    	ans[i] = max(ans[i], ans[i+1]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	cout << ans[x] << endl;
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
