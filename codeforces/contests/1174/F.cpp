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
int qd(int u) {
	cout << "d " << u + 1 << endl;
	int res;
	cin >> res;
	return res;
}
int qs(int u) {
	cout << "s " << u + 1 << endl;
	int res; 
	cin >> res;
	return res;
}
const int LOG = 20;
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
	mt19937 rng(31415929);
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
    preprocess(n, e);
    int cur = 0;
    int D = qd(0);
    if (D == 0) {
    	cout << "! " << 1 << endl;
    	return;
    }
    vi A;
    for (int i = 0; i < n; i++) {
		if (depth[i] == D) {
			A.push_back(i);
		}
	}
	shuffle(A.begin(), A.end(), rng);
    while (1) {
    	int x = qs(cur);
    	cur = x - 1;
    	for (int z : A) {
    		if (lca(cur, z) == cur) {
    			cur = z;
    			break;
    		}
    	}
    	int y = qd(cur);
    	if (y == 0) {
    		cout << "! " << cur + 1 << endl;
    		return;
    	}
    	assert(y % 2 == 0);
    	for (int i = 0; i < y / 2; i++) {
    		cur = up[cur][0];
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
