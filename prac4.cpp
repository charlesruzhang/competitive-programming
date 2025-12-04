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
    vvi e(n);
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vi c(n, 0);
    // Tarjan begin
    int time = 0; 
    vi disc(n, -1), low(n, -1); 
    vi visited(n, -1);
    function<void(int, int)> dfs = [&](int u, int parent) {
        visited[u] = 1;
        disc[u] = low[u] = time++;
        int children = 0;
        for (int v : e[u]) {
            if (v == parent) {
                continue;
            }
            if (visited[v] == -1) {
                children++; 
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (parent != -1 && low[v] >= disc[u]) {
                    c[u] = 1;
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (parent == -1 && children > 1) {
            c[u] = 1;
        }
    };
    for (int i = 0; i < n; ++i) {
        if (visited[i] == -1) {
            dfs(i, -1);
        }
    }
        //Tarjan end
    cout << accumulate(c.begin(), c.end(), 0) << endl;
    for (int i = 0; i < n; i++) {
        if (c[i]) cout << i+1 << " ";
    }
    cout << endl;
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