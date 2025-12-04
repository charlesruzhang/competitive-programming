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
    vi a(n);
    vvi e(n);
    vvi f(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	e[i].push_back(a[i] - 1);
    	f[a[i]-1].push_back(i);
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
        for (int v : e[u]) {
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
    //Tarjan end
    vi vis(n);
    vi val(n, -1);
    vi ans(n, 0);
    for (int i = 0; i < n; i++) {
    	int cur = i;
    	if (p[i] == i) continue;
    	while (!vis[cur]) {
    		vis[cur] = 1;
    		val[cur] = 0;
    		cur = p[cur];
    	}
    }
    function <void(int)> dfs2 = [&] (int u) {
    	ans[u] = 1;
    	for (int v : f[u]) {
    		if (val[v]) {
    			dfs2(v);
    			ans[u] += ans[v];
    		} 
    	}
    };
    for (int i = 0; i < n; i++) {
    	if (val[i] == 0) {
    		dfs2(i);
    		ans[i] = 0;
    	}
    }
    cout << 2 + *max_element(ans.begin(), ans.end()) << endl;
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
