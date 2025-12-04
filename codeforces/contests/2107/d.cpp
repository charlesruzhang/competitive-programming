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
    vvi e(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    vi dept(n);
    vi leaf(n);
    vi paren(n, -1);
    int tot = 0;
    int maxd = 0;
    int maxx = -1, maxy = -1, maxz = -1;
    vi used(n);
    vector<tuple<int,int,int>> ans;
    function <void(int, int)> dfs = [&](int u, int p) {
        dept[u] = 1;
        leaf[u] = u;
        int fu = 0;
        int su = 0;
        int fl = u;
        int sl = u;
        for (int v : e[u]) {    
            if (p != v && !used[v]) {
                paren[v] = u;
                dfs(v, u);
                if (dept[u] < dept[v] + 1 || (dept[u] == dept[v] + 1 && leaf[u] < leaf[v])) {
                    dept[u] = dept[v] + 1;
                    leaf[u] = leaf[v];
                }
                if (dept[v] > fu || (dept[v] == fu && leaf[v] > fl)) {
                    su = fu;
                    sl = fl;
                    fu = dept[v];
                    fl = leaf[v];
                } else if (dept[v] > su || (dept[v] == su && leaf[v] > sl)) {
                    su = dept[v];
                    sl = leaf[v];
                }
            }
        }
        if (maxd < fu + su + 1 || (maxd == fu + su + 1 && (maxx < max(fl, sl) || (maxx == max(fl, sl) && maxy < min(fl, sl))))) {
            maxd = fu + su + 1;
            maxx = max(fl, sl);
            maxy = min(fl, sl);
            maxz = u;
        }
    };
    queue<int> g;
    g.push(0);
    while (!g.empty() && tot < n) {
        maxd = 0;
        maxx = -1;
        maxy = -1;
        maxz = -1;
        int r = g.front();
        g.pop();
        dfs(r, -1);
        int par = maxz;
        int cur = maxx;
        int tota = 0;
        if (!used[par]) {
            used[par] = 1;
            tota ++;
        }
        while (cur != par) {
            if (!used[cur]) {
                used[cur] = 1;
                tota ++;
            }
            cur = paren[cur];
        }
        cur = maxy;
        while (cur != par) {
            if (!used[cur]) {
                used[cur] = 1;
                tota ++;
            }
            cur = paren[cur];
        }
        tot += tota;
        ans.push_back({tota, maxx, maxy});
        cur = maxx;
        while (cur != par) {
            for (int v : e[cur]) {
                if (!used[v]) {
                    g.push(v);
                }
            }
            cur = paren[cur];
        }
        cur = maxy;
        while (cur != par) {
            for (int v : e[cur]) {
                if (!used[v]) {
                    g.push(v);
                }
            }
            cur = paren[cur];
        }
        for (int v: e[par]) {
            if (!used[v]) {
                g.push(v);
            }
        }
    }
    // for (int i = n-1; i >= 0; i--) {
    //     if (!used[i]) {
    //         ans.push_back({1, i, i});
    //     }
    // }
    sort(ans.begin(), ans.end(), greater<>());
    for (int i = 0; i < ans.size(); i++) {
        auto [x, y, z] = ans[i];
        cout << x << " " << y + 1 << " " << z + 1 << " ";
    }
    cout << endl;
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
