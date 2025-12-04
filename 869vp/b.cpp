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
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
     void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
    	if (e[i].size() >= 4) {
    		DSU D(n);
    		for (int j = 0; j < n; j++) {
    			if (j == i) continue;
    			for (int v : e[j]) {
    				if (v == i) continue;
    				D.unite(j, v);
    			}
    		}
    		map<int, int> ma;

    		for (int v : e[i]) {
    			auto it = ma.find(D.find(v));
    			if (it == ma.end()) {
    				ma[D.find(v)] = v;
    			} else {
    				cout << "YES" << endl;
    				set<int> s;
    				for (int w : e[i]) {
    					s.insert(w);
    				}
    				int idx = it -> second;
    				vi visited(n);
    				vi parent(n, -1);
    				visited[i] = 1;
    				int target = -1;
    				function <void(int)> dfs = [&](int u) {
    					visited[u] = 1;
    					for (int z: e[u]) {
    						if (!visited[z]) {
    							parent[z] = u;
    							if (s.find(z) != s.end()) {
    								target = z;
    								return;
    							}
    							if (target == -1) {
    								dfs(z);
    							} else {
    								return;
    							}
    						}
    					}
    				};
    				dfs(idx);
    				assert(target != -1);
    				int cur = target;
    				vector<pii> ans;
    				while (parent[cur] != -1) {
    					ans.push_back({cur, parent[cur]});
    					cur = parent[cur];
    				}
    				int cnt = 0;
    				for (int w : e[i]) {
    					if (w != target && w != idx) {
    						ans.push_back({i, w});
    						cnt++;
    					}
    					if (cnt == 2) break;
    				}
    				ans.push_back({i, target});
    				ans.push_back({i, idx});
    				cout << ans.size() << endl;
    				for (int w = 0; w < ans.size(); w++) {
    					auto [x, y] = ans[w];
    					cout << x +1 << " " << y+1 << endl;
    				}
    				return;
    			}
    		}
    	}
    }
    cout << "NO" << endl;
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
