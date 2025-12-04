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
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<pii>> e(n);
    for (int i = 0; i < m; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        s--; t--;
        e[s].push_back({t, w});
    }
    int l = 0;
    int r = 1e9 + 1;
    auto check = [&] (int m) {
        vl maxx(n, -1);
        maxx[0] = 0;
        for (int u = 0; u < n - 1; u++) {
            if (maxx[u] == -1) continue;
            maxx[u] += b[u];
            for (auto [v, w] : e[u]) {
                if (w > m) continue;
                if (w > maxx[u]) continue;
                maxx[v] = max(maxx[v], maxx[u]);
            }
        }
        if (maxx[n-1] != -1) {
            return true;
        } else {
            return false;
        }
    };
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l == 1e9 + 1) {
        cout << -1 << endl;
    } else {
        cout << l << endl;
    }
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
