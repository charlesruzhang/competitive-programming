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
    vvi f(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i + a[i] >= n || i + a[i] < 0) {
            f[n].push_back(i);
        } else {
            f[i + a[i]].push_back(i);
        }
    }
    
    vi done(n);
    function <void(int)> dfs = [&] (int u) {
        done[u] = 1;
        if (u + a[u] >= n || u + a[u] < 0) {
            done[u] = 2; 
        } else {
            if (done[u + a[u]]) {
                done[u] = done[u + a[u]];
            } else {
                dfs(u + a[u]);
                done[u] = done[u + a[u]];
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!done[i]) dfs(i);
    }
    vi ma(n+1);
    function <void(int, int)> dfs2 = [&] (int u, int parr) {
        ma[u] = 1;
        for (int v : f[u]) {
            if (v != parr) {
                dfs2(v, u);
                ma[u] += ma[v];
            }
        }
    };
    dfs2(n, -1);
    ll ans = 0;
    if (done[0] == 1) {
        int cur = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (done[i] == 2) {
                tot++;
            }
        }
        vi visited(n);
        while (!visited[cur]) {
            visited[cur] = 1;
            ans += n + 1 + tot;
            cur = cur + a[cur];
        }
        cout << ans << endl;
    } else {
        int cur = 0;
        int tot = 0;
        ans = 1ll * (2 * n + 1) * n;
        for (int i = 1; i < n; i++) {
            if (done[i] == 1) {
                tot++;
            }
        }
        while (cur < n && cur >= 0) {
            ans -= tot + ma[cur];
            cur = cur + a[cur];
        }
        cout << ans << endl;
        return;
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
