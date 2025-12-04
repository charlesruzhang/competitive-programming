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
    vvi e(n);
    vector<pii> edges;
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    	edges.push_back({u, v});
    }
    vi color(n);
    int s = -1;
    int t = -1;
    function <void(int, int)> dfs = [&] (int u, int p) {
    	color[u] = color[p] ^ 1;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    		}
    	}
    };
    for (int i = 0; i < n; i++) {
    	if (e[i].size() == 2) {
    		color[i] = 0;
    		for (int u : e[i]) {
    			dfs(u, i);	
    			color[i] = 1;
    		}
    		s = i;
    		break;
    	}
    }
    if (s == -1) {
    	cout << "NO" << endl;
    	return;
    } else {
    	cout << "YES" << endl;
    	for (auto [u, v] : edges) {
			if (color[u] && color[v]) {
				assert(u == s || v == s);
				if (v == s) swap(u, v);
				cout << v + 1 << " " << u + 1 << endl;
			} else if (color[u]) {
				cout << u + 1 << " " << v + 1 << endl;
			} else {
				cout << v + 1 << " " << u + 1 << endl;	
			}
    	}
    }
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
