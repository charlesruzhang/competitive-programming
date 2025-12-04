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
    int n, k;
    cin >> n >> k;
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    int l = 1;
    int r = n / 2;
    function <bool(int)> check = [&] (int m ) {
    	int tot = 0;
    	vi val(n);
    	function <void(int, int)> dfs = [&] (int u, int p) {
    		int va = 1;
    		for (int v : e[u]) {
    			if (v != p) {
    				dfs(v, u);
    				va += val[v];
    			}
    		}
    		if (va >= m) {
    			tot ++;
    			val[u] = 0;
    		} else {
    			val[u] = va;
    		}
    	};
    	dfs(0, -1);
    	tot--;
    	return tot >= k;
    };
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	if (check(m)) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    cout << l << endl;
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
