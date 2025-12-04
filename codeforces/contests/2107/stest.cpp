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
int solve(vvi a) {
    int n = 15;
    vvi dp(n+1, vi(2));
    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j < 2; j++) {
            if (a[1-j][i] && a[j][i+1]) {
                dp[i][j] = min(dp[i+1][j] + 1, dp[i+2][1-j] + 1);
            } else {
                if (a[1-j][i]) {
                    dp[i][j] = min(dp[i+1][j] + 1, dp[i+1][1-j]);
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[j][i]) cnt++;
        }
    }
    return cnt - dp[0][0];
}
constexpr int inf = 1E9;
int solve2(vvi a) {
    int n = 15;
    
    std::vector dp(2, std::vector<int>(n + 1, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[j][i + 1] = std::max(dp[j][i + 1], dp[j][i] + a[j][i + 1]);
            int t = std::min(i + 2, n);
            if (a[!j][i]) {
                dp[!j][t] = std::max(dp[!j][t], dp[j][i] + 1 + a[!j][i + 1] + a[!j][i + 2]);
            }
        }
    }
    
    return std::max(dp[0][n], dp[1][n]);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    for (int i = 0; i < (1 << 30); i++) {
        int n = 15;
        vvi a(2, vi(n+2));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                a[k][j] = (i & (1 << (k * n + j))) ? 1 : 0;
            }
        }
        a[0][0] = 0;
        int z = solve(a);
        int y = solve2(a);
        if (z != y) {
            cout << z << " " << y << endl;
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < n; j++) {
                    cout << a[k][j];
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}
