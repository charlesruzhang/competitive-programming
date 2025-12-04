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
void solve() {
    int n, m;
    cin >> n >> m;
    vi p(m);
    for (int i = 0; i < m; i++) {
    	cin >> p[i];
    }
    int maxx = (1 << n) - 1;
    vi ma((1 << n), -1);
    for (int i = 0; i < m; i++) {
    	ma[maxx - p[i]] = maxx + 1 + i;
    }
    vi visited((1 << n) + m);
    function <void(int)> dfs = [&] (int u) {
    	visited[u] = 1;
    	if (u > maxx) {
    		if (!visited[p[u - maxx - 1]]) {
    			dfs(p[u-maxx-1]);
    		}
    	} else {
    		for (int i = 0; i < n; i++) {
    			int z = (u | (1 << i));
    			if (z != u && !visited[z]) {
    				dfs(z);
    			}
    		}
    		if (ma[u] != -1) {
    			dfs(ma[u]);
    		}
    	}
    };
    int ans = 0;
    for (int i = 0; i < m; i++) {
    	if (!visited[maxx + 1 + i]) {
    		ans++;
    		dfs(maxx + 1 + i);
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
