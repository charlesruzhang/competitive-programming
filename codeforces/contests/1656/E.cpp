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
    for (int i = 0; i < n -1; i++) {
    	int x,y;
    	cin >> x >> y;
    	x--; y--;
    	e[x].push_back(y);
    	e[y].push_back(x);
    }
    vi w(n);
    vi p(n, -1);
    function <void(int, int)> dfs = [&](int u, int val) {
    	int pp = e[u].size();
    	w[u] = pp * val;
    	for (int v : e[u]) {
    		if (p[u] != v) {
    			p[v] = u;
    			dfs(v, -val);
    		}
    	}
    };
    dfs(0, 1);
    for (int i = 0; i < n; i++) {
    	cout << w[i] << " ";
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
