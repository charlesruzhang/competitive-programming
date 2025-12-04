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
    int n;
    cin >> n;
    vi a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    vi p3(n+1);
    p3[n] = 0;
    for (int i=n-1; i>=0; i--) {
        p3[i] = p3[i+1];
        if (a[i] == 3) {
            p3[i]++;
        }
    }
    ll ans = 0;
    int c1 = 0;
    int c12 = 0;
    ll summ = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            c1++;
        } else if (a[i] == 2) {
            c12 = (summ + c1) % MOD;
            ans = (ans + (c12 * 1ll * p3[i]) % MOD) % MOD;
            summ= ((2 * summ) % MOD + c1) % MOD;
        }
    }
    cout << ans << endl;
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
