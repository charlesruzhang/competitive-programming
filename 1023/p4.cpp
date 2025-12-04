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
    int p1, p2;
    ll t1, t2;
    cin >> p1 >> t1 >> p2 >> t2;
    int h, s;
    cin >> h >> s;
    vl dp(h+max(p1,p2)+1);
    if (t1 == t2) {
        cout << ((h - 1)  / (p1 + p2 - s) + 1) << endl;
        return;
    }
    int target = (t1 < t2) ? (p1 - s) : (p2 - s);
    ll time = min(t1, t2);
    for (int i = 1; i <= h + max(p1, p2); i++) {
        if (i >= target) dp[i] = dp[i - target] + time;
        if ((i - p1 - p2 + s) >= 0) dp[i] = min(dp[i], dp[i - p1 - p2 + s] + max(t1, t2));
    }
    for (int i = h + max(p1, p2) - 1; i >= 1; i--) {
        if (dp[i] > dp[i+1]) dp[i] = dp[i+1];
    }
    cout << dp[h] << endl;   
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
