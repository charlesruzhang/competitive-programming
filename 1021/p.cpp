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
int MOD = 998244353;
const ll MAXX = 1e16;
void solve() {
    int n, m;
    cin >> n >> m;
    vvi e(n);
    vvi dist(n, vi(n, 1e9));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vvi ans(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = 0;
            ll cur = 1;
            for (int u = 0; u < n; u++) {
                if (u == i || u == j) continue;
                if (dist[i][u] + dist[u][j] == dist[i][j]) {
                    cnt++;
                    continue; 
                }
                int cnt2 = 0;
                for (int v : e[u]) {
                    if (dist[i][v] + 1 == dist[i][u] && dist[j][v] + 1 == dist[j][u]) {
                        cnt2++;
                    }
                }
                cur = (cur * cnt2) % MOD;
            }
            if (cnt > max(0, dist[i][j] - 1)) {
                ans[i][j] = 0;
            } else {
                ans[i][j] = cur;
            }
            ans[j][i] = ans[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
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
