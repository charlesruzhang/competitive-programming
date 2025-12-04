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
    int n, t;
    cin >> n >> t;
    vector<vector<pii>> e(n);
    for (int i = 0; i < t; i++) {
    	int x;
    	cin >> x;
    	for (int j = 0; j < x; j++) {
    		int u, v;
    		cin >> u >> v;
    		u--; v--;
    		e[u].push_back({v, i});
    		e[v].push_back({u, i});
    	}
    }
    vector<vector<pii>> Z(t);
    for (auto [x, y] : e[0]) {
    	Z[y].push_back({0, x});
    }
    int k;
    cin >> k;
    vi visited(n);
    visited[0] = 1;
    for (int i = 0; i < k; i++) {
    	int z;
    	cin >> z;
    	z--;
    	vi vec;
    	for (auto [u, v] : Z[z]) {
    		if (!visited[u]) {
    			vec.push_back(u);
    			visited[u] = 1;
    		}
    		if (!visited[v]) {
    			vec.push_back(v);
    			visited[v] = 1;
    		}
    	}
    	int sz = Z[z].size();
    	for (int i = 0; i < sz; i++) {
    		Z[z].pop_back();
    	}
    	for (int v : vec) {
    		for (auto [x, y] : e[v]) {
    			Z[y].push_back({v, x});
    		}
    	}
    	if (visited[n-1]) {
    		cout << i + 1 << endl;
    		return;
    	}
    }
    cout << -1 << endl;
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
