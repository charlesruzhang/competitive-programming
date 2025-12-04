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
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vl val(n);
    vl minn = a;
    vl maxx = a;
    val[0] = a[0];
    minn[0] = maxx[0] = a[0];
    function <void(int, int)> dfs = [&] (int u, int p) {
    	for (int v : e[u]) {
    		if (v != p) {
    			val[v] = a[v] - val[u];
    			minn[v] = min(minn[v], a[v] - maxx[u]);
    			maxx[v] = max(maxx[v], a[v] - minn[u]);
    			dfs(v, u);
    		}
    	}
    };
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
    	cout << maxx[i] << " ";
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
