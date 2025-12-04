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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
        b[i]--;
    }

    vector<vector<array<int, 3>>> e(2 * n);

    for (int i = 0; i < n; i++) {
        e[a[i]].push_back({b[i], i, 0});
        e[b[i]].push_back({a[i], i, 1});
    }

    vi color(2 * n, -1);
    vi c(n, -1);
    

    vi visited(2 * n);
    int last = -1;
    function <void(int)> dfs2 = [&] (int u) {
        if (visited[u]) return;
        last = u;
        visited[u] = 1;
        for (auto [v, idx, dir] : e[u]) {
            dfs2(v);
        }
    };

    function <void(int)> dfs = [&] (int u) {
        if (color[u] != -1) return;
        color[u] = 1;
        for (auto [v, idx, dir] : e[u]) {
            if (c[idx] == -1) {
                c[idx] = dir;
            }
            dfs(v);
        }
    };

    for (int i = 0; i < 2 * n; i++) {
        if (color[i] == -1) {
            dfs2(i);
            dfs(last);
        }
    }

    array<set<int>, 2> arr;
    vvi ans(2);
    for (int i = 0; i < n; i++) {
    	if (c[i]) {
    		arr[0].insert(b[i]);
    		arr[1].insert(a[i]);
    		ans[0].push_back(b[i]);
    		ans[1].push_back(a[i]);
    	} else {
    		arr[0].insert(a[i]);
    		arr[1].insert(b[i]);
    		ans[0].push_back(a[i]);
    		ans[1].push_back(b[i]);
    	}
    }
    cout << arr[0].size() + arr[1].size() << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[0][i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[1][i] + 1 << " ";
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
