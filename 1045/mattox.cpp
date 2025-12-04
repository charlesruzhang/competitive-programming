#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const ll MOD = 998244353;
const ll MAXX = 100000000;
const ld EPS = 1e-9;
int dp[105][105][105][105][2];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int s = 1; s <= n + m - 2; s++) {
        for (int k = 0; k <= s; k++) {
            for (int b = 0; b <= 1; b++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i + k >= n || j + (s-k) >= m) {
                            continue;
                        }
                        if (b == 0 && s == 1) {
                            dp[i][j][k][s-k][b] = MAXX;
                        } else if (b == 1 && s == 1) {
                            dp[i][j][k][s-k][b] = 1;
                        } else if (b == 1 && s == 2 && (k != 1)) {
                            dp[i][j][k][s-k][b] = 1;
                        } else if (b == 0 && s == 2) {
                            if (k == 0) {
                                dp[i][j][k][s-k][b] = (j + max(i, n-i-1) + 1) * 2;
                            } else if (k == 2) {
                                dp[i][j][k][s-k][b] = (max(j, m-j-1) + i + 1) * 2;
                            } else {
                                dp[i][j][k][s-k][b] = (j + i + 1) * 2;
                            }
                        } else if (b == 1 && s == 2 && k == 1) {
                            dp[i][j][k][s-k][b] = MAXX;
                            if (i != 0) {
                                dp[i][j][k][s-k][b] = min(dp[i][j][k][s-k][b], dp[n-i-1][j][k][s-k][1-b] + 1);
                            } 
                            if (j != 0) {
                                dp[i][j][k][s-k][b] = min(dp[i][j][k][s-k][b], dp[i][m-j-1][k][s-k][1-b] + 1);
                            }
                            
                        } else if (b == 0) {
                            dp[i][j][k][s-k][b] = 0;
                            if (s != k) {
                                if (j != m -1) {
                                    dp[i][j][k][s-k][b] = max(dp[i][j][k][s-k][b], dp[i][j+1][k][s-1-k][1-b] + 1);
                                }
                            } else {
                                if (j != 0) {
                                    dp[i][j][k][s-k][b] = max(dp[i][j][k][s-k][b], dp[i][j-1][k-2][1][b] + 2);
                                }
                                if (m - j != 1) {
                                    dp[i][j][k][s-k][b] = max(dp[i][j][k][s-k][b], dp[i][m-j-2][k-2][1][b] + 2);
                                }
                            }  
                            if (k != 0) {
                                if (i != n - 1) {   
                                    dp[i][j][k][s-k][b] = max(dp[i][j][k][s-k][b], dp[i+1][j][k-1][s-k][1-b] + 1);
                                }
                            } else {
                                if (i != 0) {
                                    dp[i][j][k][s-k][b] = max(dp[i][j][k][s-k][b], dp[i-1][j][1][s-2][b] + 2);
                                }
                                if (n - i != 1) {
                                    dp[i][j][k][s-k][b] = max(dp[i][j][k][s-k][b], dp[n-i-2][j][1][s-2][b] + 2);
                                }
                            }
                            
                        } else {
                            dp[i][j][k][s-k][b] = MAXX;
                            if (s != k) {
                                if (s - k != 1) {
                                    dp[i][j][k][s-k][b] = min(dp[i][j][k][s-k][b], dp[i][j][k][s-k-2][1-b] + 1);
                                }
                                dp[i][j][k][s-k][b] = min(dp[i][j][k][s-k][b], dp[i][j][k][s-k-1][1-b] + 1);
                            }
                            if (k != 0) {
                                if (k != 1) {
                                    dp[i][j][k][s-k][b] = min(dp[i][j][k][s-k][b], dp[i][j][k-2][s-k][1-b] + 1);
                                }
                                dp[i][j][k][s-k][b] = min(dp[i][j][k][s-k][b], dp[i][j][k-1][s-k][1-b] + 1);
                            }
                        }
                    }
                }
                
            }
        }
    }
    cout << dp[0][0][n-1][m-1][0] / 2 << endl;
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