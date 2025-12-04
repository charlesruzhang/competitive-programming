#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pll = pair<ll, ll>;

void solve() {
	int n;
	cin >> n;
	vi c(n);
	vi C(n+1);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		C[c[i]]++;
	}
	vector<vector<pii>> e(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		e[u].push_back({v, i - 1});
		e[v].push_back({u, i - 1});
	}
	vl ans(n - 1);
	ll tot = 0;
	vector<map<int, int>> vm(n);
	function <void(int, int, int)> dfs = [&] (int u, int p, int id) {
		vm[u][c[u]] = 1;
		if (id != -1) ans[id] += C[c[u]] - 1;
		for (auto [v, idx] : e[u]) {
			if (v != p) dfs(v, u, idx);
		}
		for (auto [v, idx] : e[u]) {
			if (v == p) continue;
			if (id == -1) continue; 
			ans[id] += ans[idx];
			if (vm[u].size() < vm[v].size()) {
				swap(vm[u], vm[v]);
			}
			for (auto [col, cnt]: vm[v]) {
				auto it = vm[u].find(col);
				if (it == vm[u].end()) {
					vm[u][col] = cnt;
					continue;
				}
				int cnt2 = it -> second;
				ans[id] -= 2ll * cnt2 * cnt;
				it -> second += cnt;
			}
		}
	};
	dfs(0, -1, -1);
	for (int i = 0; i < n - 1; i++) {
		cout << ans[i] << endl;
	}
}

int main() {

	solve();
	return 0;
}