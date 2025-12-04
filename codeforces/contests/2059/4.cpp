#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
const ll MAXX = 100000000000;
int solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--; s2--;
    int m1, m2;
    cin >> m1;
    vvi a(n);
    vvi aa(n, vi(n, 0));
    for (int i= 0; i < m1; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
        aa[u][v] = 1;
        aa[v][u] = 1;
    }
    cin >> m2;
    vvi b(n);
    vi res(n);
    for (int i= 0; i < m2; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        b[u].push_back(v);
        b[v].push_back(u);
        if (aa[u][v] == 1) {
            res[u] = 1;
            res[v] = 1;
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, MAXX));
    dp[s1][s2] = 0;
    queue<pii> q;
    q.push(pii(s1,s2));
    while (!q.empty()) {
        pii pp = q.front();
        int x = pp.first;
        int y = pp.second;
        q.pop();
        for (int u : a[x]) {
            for (int v : b[y]) {
                if (dp[x][y] + abs(u-v) < dp[u][v]) {
                    dp[u][v] = dp[x][y] + abs(u-v);
                    q.push(pii(u,v));
                }
            }
        }
    }
    ll ans = MAXX;
    for (int i = 0; i < n; i++) {
        if (res[i] == 1) {
            ans = min(ans, dp[i][i]);
        }
    }
    if (ans != MAXX) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
