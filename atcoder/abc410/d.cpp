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
void solve() {
    int n, m;
    cin >> n >> m;
    int M = 1024;
    vector<vector<int>> e(n * M);
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        for (int j = 0; j < M; j++) {
            e[u * M + j].push_back(v * M + (j ^ w));
        }
    }
    int minn = 1e9;
    vi visited(n * M);
    function <void(int)> dfs = [&] (int u) {
        if (u / M == n - 1) {
            minn = min(minn, u % M);
        }
        visited[u] = 1;
        for (int v: e[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    };
    dfs(0);
    if (minn != 1e9) cout << minn << endl;
    else cout << -1 << endl;
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
