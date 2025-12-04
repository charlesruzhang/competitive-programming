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
    vector<vector<pii>> e(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	e[u].push_back({v, w});
    }
    // Tarjan begin
    vi p(n, -1);
    int time = 0; 
    vi disc(n, -1), low(n, -1); 
    vector<bool> inStack(n); 
    stack<int> st;
    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = time++;
        st.push(u);
        inStack[u] = true;
        for (auto [v, w] : e[u]) {
            if (disc[v] == -1) { 
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (low[u] == disc[u]) {
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                p[v] = u;
                if (v == u) break;
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(i);
        }
    }
    vvi P(n);
    for (int i = 0; i < n; i++) {
    	P[p[i]].push_back(i);
    }
    vi vis(n);
    ll tot = 0;
    vl dist(n);
    function <void(int, int)> dfs2 = [&] (int u, int X) {
    	dist[u] = tot;
    	vis[u] = 1;
    	for (auto [v, w]: e[u]) {
    		if (p[v] == X && !vis[v]) {
    			tot += w;
    			dfs2(v, X);
    			tot -= w;
    		}
    	}
    };
    vl G(n);
    vi vis2(n);
    function <void(int, int)> dfs3 = [&] (int u, int X) {
    	vis2[u] = 1;
    	for (auto [v, w]: e[u]) {
    		if (p[v] == X) {
    			G[X] = gcd(G[X], abs(dist[v] - dist[u] - w));
    			//cout << X << " " << abs(dist[v] - dist[u] - w) << endl;
    		}
    		if (p[v] == X && !vis2[v]) {
    			dfs3(v, X);
    		}
    	}
    };
    for (int i = 0; i < n; i++) {
    	if (P[i].size()) {
    		dfs2(P[i][0], i);
    		dfs3(P[i][0], i);
    		//cout << i << " " << G[i] << endl;
    	}
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {	
    	int u, s, t;
    	cin >> u >> s >> t;
    	u--;
    	int px = p[u];
    	int g = gcd(G[px], t);
    	cout << (s % g == 0 ? "Yes" : "No") << endl;
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
