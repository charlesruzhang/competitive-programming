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
const int LOG = 19;
vi parent;
vi depth;
vvi up;

void preprocess(int n, vvi &adj, int root = 0) {
    parent.resize(n);
    depth.resize(n);
    up.assign(n, vector<int>(LOG, -1));

    function<void(int, int)> dfs = [&](int v, int p) {
        parent[v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        up[v][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : adj[v]) {
            if (u != p) dfs(u, v);
        }
    };

    dfs(root, -1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if (diff & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}

void solve() {
	int n;
	cin >> n;
	vi val(n);
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	vvi e(n);
	for (int i = 1; i < n; i++) {
		int u, v; 
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);	
	}
	preprocess(n, e);
	vi par(n);
	vvi orr(n, vi(30));
	function <void(int, int)> dfs2 = [&] (int u, int p) {
		par[u] = p;
		for (int i = 0; i < 30; i ++) {
			orr[u][i] += (val[u] & (1 << i)) ? 1 : 0;
		}
		for (int v : e[u]) {
			if (v != p) {
				for (int i = 0; i < 30; i++) {
					orr[v][i] += orr[u][i];	
				}
				dfs2(v, u);
			}
		}
	};
	dfs2(0, -1);

	int q; 
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		int u = lca(x, y);
		auto get = [&] (int u, int v, int i) {
			int z = (par[u] == -1) ? 0 : orr[par[u]][i];
			return (orr[v][i] != z);
		};

		auto get2 = [&] (int v, int d) {
			int cur = v;
			if (!d) return v;
			int z2 = 32 - __builtin_clz(d);
			for (int i = 0; i <= z2; i++) {
				if (d & (1 << i)) {
					cur = up[cur][i];
				}
			}
			return cur;
		};

		vi left(30, 7), right(30);
		for (int i = 0; i < 30; i++) {
			int l = 0;
			int r = depth[x] - depth[u];
			if (val[x] & (1 << i)) {
				left[i] = 0;
				continue;
			}

			int tu = depth[x] - depth[u];
			if (get(u, x, i) == 0) {
				r = depth[y] - depth[u];
				int cur = y;
				int tot = 0;
				int z = (r == 0) ? 0 : (32 - __builtin_clz(r));
				for (int j = z; j >= 0; j--) {
					if (r >= (1 << j)) {
						int tmp = up[cur][j];
						if (get(u, tmp, i) != 0) {
							cur = tmp;
							r -= (1 << j);
							tot |= (1 << j);
						}
					}
				}
				//cout << i << " , " << tot << endl;
				left[i] = tu + depth[y] - depth[u] - tot ;
			} else {
				r = depth[x] - depth[u];
				int cur = x;
				int tot = 0;
				int z = (r == 0) ? 0 : (32 - __builtin_clz(r));
				for (int j = z; j >= 0; j--) {
					if (r >= (1 << j)) {
						int tmp = up[cur][j];
						if (get(tmp, x, i) == 0) {
							cur = tmp;
							r -= (1 << j);
							tot |= (1 << j);
						}
					}
				}
				left[i] = tot + 1;
			}
		}
		for (int i = 0; i < 30; i++) {
			int l = 0;
			int r = depth[y] - depth[u];
			if (val[y] & (1 << i)) {
				right[i] = depth[y] - depth[u] + depth[x] - depth[u];
				continue;
			}
			
			int tu = depth[y] - depth[u];
			if (get(u, y, i) == 0) {
				r = depth[x] - depth[u];
				int cur = x;
				int tot = 0;
				if (get(u, x, i) == 0) {
					right[i] = -1;
					continue;
				}
				int z = (r == 0) ? 0 : (32 - __builtin_clz(r));
				for (int j = z; j >= 0; j--) {
					if (r >= (1 << j)) {
						int tmp = up[cur][j];
						if (get(u, tmp, i) != 0) {
							cur = tmp;
							r -= (1 << j);
							tot |= (1 << j);
						}
					}
				}
				right[i] = tot;
			} else {
				r = depth[y] - depth[u];
				int cur = y;
				int tot = 0;
				int z = (r == 0) ? 0 : (32 - __builtin_clz(r));
				for (int j = z; j >= 0; j--) {
					if (r >= (1 << j)) {
						int tmp = up[cur][j];
						if (get(tmp, y, i) == 0) {
							cur = tmp;
							r -= (1 << j);
							tot |= (1 << j);
						}
					}
				}
				right[i] = depth[y] - depth[u] + depth[x] - depth[u] - tot - 1;
			}
		}
		multiset<pii> se;
		int ans = 0;
		
		int cnt = 0;
		for (int i = 0; i < 30; i++) {
			if (left[i] <= right[i]) {
				//cout << i << " " << left[i] << " " << right[i] << endl;
				se.insert({left[i], 0});
				se.insert({right[i], 1});
				ans++;
				cnt++;
			}
		}
		auto it = se.begin();

		while (it != se.end()) {
			auto [tmp, tmp2] = *it;
			if (tmp2 == 1) {
				cnt--; 
			} else {
				cnt++;
			}
			ans = max(ans, cnt);
			++it;
		}
		cout << ans << " ";
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
