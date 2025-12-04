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
    for (int i = 0; i < n-1; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	e[x].push_back(y);
    	e[y].push_back(x);
    }
    int cur = 0;
    vi depth(n);
    vi p(n, -1);
    function <void(int)> dfs = [&](int u) {
    	depth[u] = cur;
    	for (int v : e[u]) {
    		if (p[u] != v) {
    			p[v] = u;
    			cur++;
    			dfs(v);
    			cur--;
    		}
    	}
    };
    dfs(0);
    vvi d(n);
    for (int i = 0; i < n; i++) {
    	d[depth[i]].push_back(i);
    }
    vi suff(n+1);
    for (int i = n-1; i >= 0; i--) {
    	suff[i] = suff[i+1] + d[i].size();
    }
    vi count(n);
    for (int i = 0; i < n; i++) {
    	count[i] = e[i].size();
    }
    int ans = n -1;
    vi removed(n);
    int rem = 0;
    for (int i = 1; i < n; i++) {
    	for (int u : d[i-1]) {
    		int cur = u;
    		while (cur != 0 && count[cur] == 1) {
    			removed[cur] = 1;
    			count[p[cur]]--;
    			count[cur]--;
    			rem++;
    			cur = p[cur];
    		}
    	}
    	ans = min(ans, rem + suff[i+1]);
    }
    cout << ans << endl;
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
