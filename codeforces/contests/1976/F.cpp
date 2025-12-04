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
    int n;
    cin >> n;
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi ans(n-1);
    vi depth(n);
    vi height(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	int maxx = -1;
    	int c = -1;
    	for (int v : e[u]) {
    		if (v != p) {
    			depth[v] = depth[u] + 1;
    			dfs(v, u);
    			if (height[v] > maxx) {
    				maxx = height[v];
    				c = v;
    			}
    		}
    	}
    	height[u] = 1 + maxx;
    };
    dfs(0, -1);

    vi V(n);
    function <void(int, int, int)> dfs2 = [&] (int u, int p, int P) {
    	int done = 0;
    	for (int v: e[u]) {
    		if (v != p) {
    			if (!done && height[u] == height[v] + 1) {
    				done = 1;
    				if (P == -1) {
    					P = u;
    				}
    				V[v] = P;
    				dfs2(v, u, P);
    			} else {
    				V[v] = v;
    				dfs2(v, u, -1);
    			}
    		}
    	}
    };
    dfs2(0, -1, -1);
    vector<pii> v;
    for (int i = 1; i < n; i++) {
    	if (e[i].size() == 1) {
    		v.push_back({depth[i] - depth[V[i]] + 1, i});
    	}
    }

    sort(v.begin(), v.end());
    int tot = n;

    for (int i = 0; i < n - 1; i++) {
    	if (v.size() < 2) {
    		break;
    	}
    	if (i == 0) {
    		auto [val, x] = v.back();
    		v.pop_back();
    		tot -= val;
    		ans[i] = tot;
    	} else {
    		auto [val, x] = v.back();
    		v.pop_back();
    		auto [val2, y] = v.back();
    		v.pop_back();
    		tot -= val + val2;
    		ans[i] = tot;
    	}
    }
    for (int x : ans) {
    	cout << x << " ";
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
