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
    int n, st, en;
    cin >> n >> st >> en;
    st--; en--;
    vvi e(n);
    for (int i = 0; i < n - 1; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	e[x].push_back(y);
    	e[y].push_back(x);
    }
    vi dist(n);
    int cur = 0;
    vi p(n, -1);
    function <void(int)> dfs = [&](int u) {
    	dist[u] = cur;
    	for (int v : e[u]) {
    		if (p[u] != v) {
    			p[v] = u;
    			cur++;
    			dfs(v);
    			cur--;
    		}
    	}
    };
    dfs(st);
    vi arr(dist[en] + 1);
    cur = en;
    map<int, int> ma;
    for (int i = dist[en]; i >= 0; i--) {
    	arr[i] = cur;
    	ma[cur] = 1;
    	cur = p[cur];
    }
    ma[cur] = 1;
    vi ans(n);
    int idx = 0;
    function <void(int)> dfs2 = [&](int u) {
    	for (int v : e[u]) {
    		if (ma[v] != 1 && p[u] != v) {
    			dfs2(v);
    		}
    	}
    	ans[idx] = u + 1;
    	idx++;
    };
    for (int i : arr) {
    	dfs2(i);
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
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
