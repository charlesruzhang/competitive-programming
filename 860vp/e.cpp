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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi dp(n + 1, INF);
    dp[n] = 0;
    vi A(n + 1, -1);
    int maxx = 0;
    vi pot(n + 1, -1);
    pot[n] = 0;
    pot[n-1] = 1;
    for (int i = n - 2; i >= 0; i--) {
    	int x = a[i];
    	if (x + i + 1 <= n) {
    		dp[i] = min(dp[i], dp[x + i + 1] + 1);
    		pot[i] = max(pot[i], pot[x + i + 1] + 1);
    	}
    	pot[i] = max(pot[i], maxx + 1);
    	if (dp[i] <= n) {
    		A[dp[i]] = max(A[dp[i]], i);
    		maxx = max(maxx, dp[i]);
    	}
    }
    vi ans;
    for (int i = n - 2; i >= 0; i--) {
    	int x = dp[i + 1];
    	if (x == a[i]) {
    		ans.push_back(0);
    		continue;
    	}
    	if (x != INF) {
    		ans.push_back(1);
    		continue;
    	}
    	int y = a[i];
    	if (pot[i + 1] >= y) {
    		ans.push_back(1);
    		continue;
    	}
    	ans.push_back(2);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n - 1; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
