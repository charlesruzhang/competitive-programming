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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        e[u].push_back({v, d});
    }
    vvl ans(n, vl(32, 1));
    const ll INF = 1e9 + 1;
    for (int i = 1; i <= 31; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : e[u]) {
                ans[u][i] = min(INF, max(ans[v][i-1] * w, ans[u][i]));
            }
        }
    }
    while (q--) {
        int u, x;
        cin >> u >> x;
        u--;
        for (int i = 1; i <= 31; i++) {
            if (ans[u][i] > x) {
                cout << i << endl;
                break;
            } 
        }
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
