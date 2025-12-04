// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	edges[u].push_back(v);
    	edges[v].push_back(u);
    }
    int timer = 0;
    vector<int> low(n, -1), tin(n, -1);
   	vector<bool> cut(n);

    function <void(int, int)> dfs = [&] (int u, int p) {
    	low[u] = tin[u] = timer++;
    	int children = 0;
    	for (int v : edges[u]) {
    		if (v != p) {
    			if (tin[v] != -1) {
    				low[u] = min(low[u], tin[v]);
    			} else {
    				dfs(v, u);
    				low[u] = min(low[u], low[v]);
    				if (p != -1 && low[v] >= tin[u]) {
    					cut[u] = 1;
    				}
    				++children;
    			}
    		}
    	}
    	if (p == -1 && children >= 2) {
    		cut[u] = 1;
    	}
    };
    int sz = 0;
    for (int i = 0; i < n; i++) {
    	if (tin[i] == -1) {
    		dfs(i, -1);
    	}
    	sz += cut[i];
    }
   	cout << sz << endl;
   	for (int i = 0; i < n; i++) {
   		if (cut[i]) {
   			cout << i + 1 << " ";
   		}
   	}
   	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
