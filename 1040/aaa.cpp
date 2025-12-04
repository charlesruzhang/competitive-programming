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

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
int maxM = 1e4+5;
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
void comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
}
using vvmi = vector<vector<mi>>;
void solve() {
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b = n/2;
    int cnt = 0;
    while (b) {
        cnt++;
        b/=2;
    }
    cnt = (cnt + 1) * 2;
    vector<vector<vvmi>> dp(n+2, vector<vvmi>(n+2, vvmi(cnt, vector<mi>(cnt, 0))));
    for (int d = 1; d <= n; d++) {
        for (int l = 0; l + d < n; l++) {
            int r = l + d;
            for (int i = 0; i < cnt; i++) {
                for (int j = 0; j < cnt; j++) {
                    if (d == 1) {
                        if (i == 0 && j == 0) dp[l][r][i][j] = 1;
                        continue;
                    }
                    for (int m = l + 1; m < r; m++) {
                        int s = m - l; int t = r - m;
                        if (s <= t) {
                            mi tot = 0, tot2 = 0;
                            if (!i) continue;
                            if (a[m] == -1) {
                                for (int k = 0; k < cnt; k++) {
                                    tot += dp[l][m][i-1][k];
                                }
                                for (int t = 0; t < cnt; t++) {
                                    tot2 += dp[m][r][t][j];
                                }
                                dp[l][r][i][j] += ncr(r - l - 2, m - l - 1) * tot * tot2;
                            } else {
                                for (int k = 0; k < a[m]; k++) {
                                    int t = a[m] - k;
                                    dp[l][r][i][j] += ncr(r - l - 2, m - l - 1) * dp[l][m][i-1][k] * dp[m][r][t][j];    
                                }
                            }
                        } else {
                            mi tot = 0, tot2 = 0;
                            if (j && a[m] == -1) {
                                for (int k = 0; k < cnt; k++) {
                                    tot += dp[l][m][i][k];
                                }
                                for (int t = 0; t < cnt; t++) {
                                    tot2 += dp[m][r][t][j-1];
                                }
                                dp[l][r][i][j] += ncr(r - l - 2, m - l - 1) * tot * tot2;
                            } else {
                                for (int k = 0; k < a[m]; k++) {
                                    int t = a[m] - k;
                                    if (j) dp[l][r][i][j] += ncr(r - l - 2, m - l - 1) * dp[l][m][i][k] * dp[m][r][t][j-1];    
                                }
                            }
                        }
                    }
                }
            }
        }
        int r = d - 1;
        for (int j = 0; j < cnt; j++) {
            if (d == 1) {
                if (j == 0) dp[n][r][0][j] = 1;
                continue;
            }
            for (int m = 0; m < r; m++) {
                for (int k = 0; k < cnt; k++) {
                    for (int t = 0; k + t < cnt; t++) {
                        if (j && (a[m] == -1 || a[m] == k + t)) dp[n][r][0][j] += ncr(r - 1, m) * dp[n][m][0][k] * dp[m][r][t][j-1];
                    }
                }
            }
        }
        int l = n - d;
        for (int i = 0; i < cnt; i++) {
            if (d == 1) {
                if (i == 0) dp[l][n+1][i][0] = 1;
                continue;
            }
            for (int m = l + 1; m < n; m++) {
                for (int k = 0; k < cnt; k++) {
                    for (int t = 0; k + t < cnt; t++) {
                        if (i && (a[m] == -1 || a[m] == k + t)) dp[l][n+1][i][0] += ncr(n - l - 2, m - l - 1) * dp[m][n+1][t][0] * dp[l][m][i-1][k];
                    }
                }
            }
        }
    }
    mi ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int k = 0; j + k < cnt; k++) {
                if (a[i] == -1 || a[i] == j + k) ans += ncr(n - 1, i) * dp[n][i][0][j] * dp[i][n+1][k][0];  
            }  
        }
        //cout <<(int) ans << " " << i << endl;
    }
    cout << (int) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
