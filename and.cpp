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
const int N = 22;
static bitset<(2 << N)> visited;
int T, maxx;
int n, m;
void dfs (int u) {
    visited[u] = 1;
    if (u >= T) {
        if (!visited[u - T]) {
            dfs(u-T);
        }
    } else {
        for (int i = 0; i < n; i++) {
            int z = (u | (1 << i));
            if (z != u && !visited[z]) {
                dfs(z);
            }
        }
        if (!visited[maxx - u + T]) dfs(maxx - u + T);
    }
}
void solve() {
    cin >> n >> m;
    maxx = (1 << n) - 1;
    T = (1 << n);
    
    for (int i = (1 << n); i < (2 << n); i++) {
        visited[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        visited[x + T] = 0;
    }
    int ans = 0;
    for (int i = (1 << n); i < (2 << n); i++) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
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
