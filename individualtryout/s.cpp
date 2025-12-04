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
   	vector<pii> e(m);
   	vvi conn(n, vi(n));
   	vi x(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	x[u]++;
    	x[v]++;
    	e.push_back({u, v});
    	conn[u][v] = conn[v][u] = 1;
    }
    for (auto [u, v] : e) {
    	int flag = 1;
    	for (int i = 0; i < n; i++) {
    		int t = x[i];
    		if (i != u && i != v) {
    			if (conn[i][u]) t--;
    			if (conn[i][v]) t--;
    			if (t % 2 == 0) {
    				flag = 0;
    				break;
    			}
    		}
    	}
    	if (flag) {
    		cout << 'Y' << endl;
    		return;
    	}
    }
    cout << "N" << endl;
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
