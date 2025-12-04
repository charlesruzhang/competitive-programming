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
    string s;
    string t;
    cin >> s>> t;
    int n = s.size();
    int m = t.size();
    vvi dp(n+1, vi(m+1));
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            if (s[i-1] == t[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]); 
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    cout << dp[n][m] << endl;
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
