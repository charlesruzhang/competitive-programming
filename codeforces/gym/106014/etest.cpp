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
    n = 10;
    std::mt19937 rng(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u = i; 
        std::uniform_int_distribution<int> r(0, u-1);
        int v = r(rng);
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi vv(n);
    vi leaf(n);
    vi children(n);
    vi parent(n);
    function <void(int, int, int)> dfs = [&] (int u, int p, int val) {
    	vv[u] = val;
    	int cnt = 0;
    	for (int v : e[u]) {
    		if (v != p) {
    			cnt++;
    		}
    	}
    	children[u] = cnt;
    	parent[u] = p;
    	for (int v : e[u]) {
    		if (v != p) {
    			int tar = val + 1;
    			if (cnt >= 2) tar = 1;
    			dfs(v, u, tar);
    		}
    	}
    	if (cnt == 0) {
    		leaf[u] = 1;
    	}
    };
    int root = -1;
    for (int i = 0; i < n; i++) {
    	if (e[i].size() == 1) {
    		root = i;
    	}
    }
    dfs(0, -1, -1);
    vi vis(n);
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 0; i < n; i++) {
    	if (leaf[i]) {
    		if (vv[i] != 1) pq.push({vv[i], i});
    	    else pq.push({0, i});
        }
    }
    vector<pii> ans;
    while (!pq.empty()) {
    	auto [x, u] = pq.top();
    	pq.pop();
    	if (vis[u]) continue;
    	if (x == 0) {
    		int p = parent[u];
    		if (vis[p]) {
    			//cout << -1 << endl;
    			return;
    		}
    		int flag = -1;
    		for (int v : e[p]) {
    			if (v != u && v != parent[p] && !vis[v]) {
    				if (flag == -1 && leaf[v]) {
    					flag = v;
    				} else if (leaf[v]) {
    					//cout << -1 << endl;
    					return;
    				}
    			}
    		} 
    		if (flag != -1) {
                vis[u] = 1;
                vis[p] = 1;
    			ans.push_back({u, flag});
    			vis[flag] = 1;
    			if (parent[p] != -1) children[parent[p]] -= 1;
    			if (parent[p] != -1 && children[parent[p]] == 0) {
    				leaf[parent[p]] = 1;
    				pq.push({vv[parent[p]], parent[p]});
    			}
    		} else {
                pq.push({1, u});
            }
        } else if (x == 1) {
            int p = parent[u];
            if (vis[p]) {
                //cout << -1 << endl;
                return;
            }
            vis[u] = 1;
            vis[p] = 1;
			int cur = p;
			while (parent[cur] != -1 && !vis[parent[cur]] && children[parent[cur]] == 1) {
				cur = parent[cur];
				vis[cur] = 1;
			}
			if (parent[cur] != -1) {
				children[parent[cur]]--;
			}
			ans.push_back({u, cur});
    	} else if (x >= 2) {
            vis[u] = 1;
    		int cur = u;
			while (parent[cur] != -1 && !vis[parent[cur]] && children[parent[cur]] == 1) {
				cur = parent[cur];
				vis[cur] = 1;
			}
			if (parent[cur] != -1) {
				children[parent[cur]]--;
			}
			ans.push_back({u, cur});
    	} else {
    		cout << -1 << endl;
            for (int i = 0; i < n; i++) {
                cout << parent[i] << " ";
            }
            cout << endl;
    		return;
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (!vis[i]) {
    		assert(false);
    	}
    }
    //cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        assert(ans[i].first != ans[i].second);
    	//cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 10000;
    while (t--) {
        solve();
    }
    return 0;
}
