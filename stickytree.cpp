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
    vi parent(n, -1);
    function <void(int, int)> dfs = [&] (int u, int p) {
        parent[u] = p;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    		}
    	}
    };
    dfs(0, -1);
    int q;
    cin >> q;
    vi mark(n);
    for (int i = 0; i < q; i++) {
    	int sz;
    	cin >> sz;
    	vi a(sz);
    	set<int> S;
    	for (int j = 0; j < sz; j++) {
    		cin >> a[j];
    		a[j]--;
            mark[a[j]] = 1;
    		S.insert(a[j]);
    	}
    	if (sz == 1) {
    		cout << 0 << endl;
    		continue;
    	}
    	int flag = 0;
    	for (int j = 0; j < sz; j++) {
    		if (S.find(parent[a[j]]) != S.end()) {
    			cout << -1 << endl;
    			flag = 1;
    			break;
    		}
    	}
    	if (flag) {
            for (int j = 0; j < sz; j++) {
                mark[a[j]] = 0;
            }
            continue;
        }
    	vl dp(n, INF); // no black
    	vl dp2(n, INF); // black
    	function <void(int, int)> dfs = [&] (int u, int p) {
    		int w = mark[u];
    		int ans = 0;
    		ll tot = 0, tot2 = 0, maxx = 0;
    		for (int v : e[u]) {
    			if (v != p) {
    				dfs(v, u);
    				if (w) {
    					ans += min(dp[v], dp2[v] + 1);
    				} else {
    					tot += dp2[v];
    					tot2 += dp[v];
    					maxx = max(maxx, dp[v] - dp2[v]);
    				}	
    			}
    		}
    		if (e[u].size() == 1 && u != 0) {
    			if (w) {
    				dp2[u] = 0;
    			} else {
    				dp2[u] = dp[u] = 0;
    			}
    		} else if (w) {
    			dp[u] = INF;
    			dp2[u] = ans;
    		} else {
    			dp[u] = min(tot + 1, tot2);
    			dp2[u] = min(dp[u], tot2 - maxx);
    		}
    	};
    	dfs(0, -1);
    	cout << min(dp[0], dp2[0]) << endl;
    	for (int j = 0; j < sz; j++) {
    		mark[a[j]] = 0;
    	}
    }
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
