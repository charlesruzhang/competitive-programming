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
    if (n == 2) {
    	cout << "YES" << endl;
    	cout << "1 2" << endl;
    	return;
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
    	if (e[i].size() > 1) {
    		root = i;
    		break;
    	}
    }
    int d = 0;
    vi depth(n, -1);
    vi leaf(n);
    vi C(n);
    int flag = 1;
    function <void(int, int)> dfs = [&] (int u, int p) {
    	depth[u] = d;
    	int cnt = 0;
    	for (int v : e[u]) {
    		if (v != p) {
    			d++; dfs(v, u); d--;
    			if (!leaf[v]) {
    				cnt++;
    			}
    		}
    	}
    	if ((u == root && cnt > 2) || (u != root && cnt > 1)) {
    		flag = 0;
    		return;
    	}
    	C[u] = cnt;
    	if (e[u].size() == 1 && u != root) {
    		leaf[u] = 1;
    	}
    };
    dfs(root, -1);
    if (!flag) {
    	cout << "No" << endl;
    	return;
    }
    vi ans;
    vi used(n);
    stack<int> st;
    int VIP = -1;
    function <void(int, int, int)> dfs2 = [&] (int u, int p, int c) {
    	int V = -1;
    	for (int v: e[u]) {
    		if (v != p) {
    			if (!leaf[v]) {
    				assert(V == -1);
    				V = v;
    			}
    		}
    	}
    	if (depth[u] % 2 != c) {
    		for (int v: e[u]) {
    			if (v != p) {
    				if (leaf[v]) {
    					ans.push_back(v);
    				}
    			}
    		}
    		if (V != -1) {
    			ans.push_back(V);
    			dfs2(V, u, c);
    		}
    	} else {
			for (int v: e[u]) {
    			if (v != p) {
    				if (leaf[v]) {
    					st.push(v);
    				}
    			}
    		}
    		if (V != -1) {
    			st.push(V);
    			dfs2(V, u, c);
    		}
    	}
    };
    function <void()> dfs3 = [&] () {
    	ans.push_back(root);
    	vi V;
    	for (int v : e[root]) {
    		if (!leaf[v]) {
    			V.push_back(v);
    		}
    	}
    	assert(V.size() <= 2);
    	if (V.size() == 2) {
    		st.push(V[1]);
    		VIP = V[1];
    	}
    	for (int v: e[root]) {
    		if (leaf[v]) {
    			st.push(v);
    		}
    	}
    	if (V.size() >= 1) {
    		st.push(V[0]);
    		dfs2(V[0], root, 0);
    	}
    	while (st.size()) {
    		int x = st.top();
    		st.pop();
    		ans.push_back(x);
    	}
    	if (VIP != -1) {
    		dfs2(VIP, root, 1);
    	}
    	while (st.size()) {
    		int x = st.top();
    		st.pop();
    		ans.push_back(x);
    	}
    };
    dfs3();
    assert(ans.size() == n);
    cout << "YES" << endl;
    for (int x : ans) {
    	cout << x + 1 << " ";
    }
    cout << endl;
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
