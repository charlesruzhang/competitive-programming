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
    vector<pii> a(n);
    vector<vector<pii>> e(2 * n);
    int INF = 1e9;
    map<int, int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (s.find(a[i].first) == s.end()) {
            s[a[i].first] = cnt++;
        }
        if (s.find(a[i].second + INF) == s.end()) {
            s[a[i].second+INF] = cnt++;
        }
        e[s[a[i].first]].push_back({s[a[i].second+INF], i});
        e[s[a[i].second+INF]].push_back({s[a[i].first], i});
    }   
    vi visited(n);
    vi ans;
    int odd_cnt = 0, start = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (e[i].size() % 2) {
            odd_cnt++;
            start = i;
        }
    }
    if (odd_cnt != 0 && odd_cnt != 2) {
        cout << "No" << endl;
        return;
    }
    vi vis(2 * n);
    function <void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto [v, w] : e[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };
    dfs(0);
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[i] && !e[i].empty()) {
            cout << "No" << endl;
            return;
        }
    }
    function <void(int)> dfs2 = [&](int u) {
        while (!e[u].empty()) {
            auto [x, y] = e[u].back();
            e[u].pop_back();
            if (visited[y]) continue;
            visited[y] = true;
            dfs2(x);
            ans.push_back(y);
        }
    };
    dfs2(start);
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
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
