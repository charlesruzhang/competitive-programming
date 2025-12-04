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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vi c(n * m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            c[a[i][j]] = max(c[a[i][j]], 1);
            if (i > 0 && a[i][j] == a[i-1][j]) {
                c[a[i][j]] = 2;
            }
            if (j > 0 && a[i][j] == a[i][j-1]) {
                c[a[i][j]] = 2;
            }
        }
    }
    int maxx = 0;
    int summ = 0;
    for (int i = 1; i <= n*m; i++) {
        maxx = max(maxx, c[i]);
        summ+= c[i];
    }
    cout << summ - maxx << endl;
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