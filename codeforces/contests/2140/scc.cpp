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
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
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
    vector<set<int>> f(n);
    for (int u = 0; u < n; u++) {
    	for (int v : e[u]) {
    		if (p[u] != p[v]) {
    			cout << "No" << endl;
    			cout << v + 1 << " " << u + 1 << endl;
    			return;
    		}
    	}
    }
    for (int i = 1; i < n; i++) {
    	if (p[i] != p[i-1]) {
    		cout << "NO" << endl;
    		cout << p[i-1] + 1 << " " << p[i] + 1 << endl;
    		return;
    	}
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
