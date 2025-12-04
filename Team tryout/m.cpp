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
    string s;
    cin >> s;
    vvi dp(n + 1, vi(26));
    vvi idx(n, vi(26, -1));
    for (int i = 0; i < n; i++) {
    	int minn = dp[i][0];
    	for (int j = 0; j < 26; j++) {
    		idx[i][j] = (j ? idx[i][j-1] : 0);
    		if (minn > dp[i][j]) {
    			minn = dp[i][j];
    			idx[i][j] = j;
    		}
    		dp[i+1][j] = minn + (s[i] - 'a' == j ? 0 : 1);
    	}
    }
    int ans = INF;
    int id = -1;
    for (int i = 0; i < 26; i++) {
    	if (ans > dp[n][i]) {
    		ans = dp[n][i];
    		id = i;
    	}
    }
    cout << ans << endl;
    vi T(n);
    int cur = id;
    for (int i = n - 1; i >= 0; i--) {
    	T[i] = cur;
    	cur = idx[i][cur];
    }
    for (int i = 0; i < n; i++) {
    	cout << (char) (T[i] + 'a');
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
