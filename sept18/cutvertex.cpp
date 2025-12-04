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
	vector<int> visited(n);
	vector<int> cut(n);
	vector<int> low(n, -1), tin(n, -1);
	int timer = 0;
	function <void(int, int)> dfs = [&] (int u, int p) {
		low[u] = tin[u] = timer++;
		int child = 0;
		for (int v : edges[u]) {
			if (v != p) {
				if (tin[v] != -1) {
					low[u] = min(low[u], tin[v]);
				} else {
					dfs(v, u);
					low[u] = min(low[u], low[v]);
					if (low[v] >= tin[u] && p != -1) {
						cut[u] = 1;
					}
					child++;
				}
			}
		}
		if (p == -1 && child >= 2) {
			cut[u] = 1;
		}
	};
	int sz = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
