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
    vi m(3);
    cin >> n;
    for (int i = 0; i < 3; i++) {
    	cin >> m[i];
    }
    vector<vector<int>> dp(3, vector<int>(n + 1));
    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < m[i]; j++) {
    		int cost, boost;
    		cin >> cost >> boost;
    		for (int k = n; k >= cost; k--) {
    			dp[i][k] = max(dp[i][k - cost] + boost, dp[i][k]);
    		}
    	}
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j + i <= n; j++) {
    		ans = max(ans, 1ll * dp[0][i] * dp[1][j] * dp[2][n - i - j]);
    	}
    }
    cout << ans << endl;
}
// Hint for C:
// Hint 2: Assume that S is large enough, what item should you pick?
// What is the cutoff for S to be "large enough"? 
// Hint 3: Now you should get an algorithm that runs in O(n^3), but it's still too slow!
// Hint 4: Can we break the loop early? (Some items are not contributing to the best answer as S increases) 
// Try sorting the items!

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
