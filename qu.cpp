#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

using iii = tuple<int, int, int>;
using ii = tuple<int, int>;
using ll = long long;

int find(vector<int>& dsu, int idx) {
	if(dsu[idx] < 0) return idx;
	int root = find(dsu, dsu[idx]);
	dsu[idx] = root;

	return root;
}

void join(vector<int>& dsu, int i, int j) {
	int r1 = min(find(dsu, i), find(dsu, j));
	int r2 = max(find(dsu, i), find(dsu, j));

	if(r1 == r2) return;
	dsu[r1] += dsu[r2];
	dsu[r2] = r1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<iii> edges(m);
	vector<ii> ans;
	ll sum = 0;

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {w, --u, --v};
	}
	sort(edges.begin(), edges.end());
	vector<int> arr(n, -1);

	for(auto & e: edges) {
		if(arr[0] == -n) break;
		int w = get<0>(e);
		int u = get<1>(e);
		int v = get<2>(e);

		if(find(arr, u) == find(arr, v)) continue;
		sum += w;
		join(arr, u, v);
		ans.push_back({u, v});
	}

	cout << sum << '\n';
	for(auto e: ans) {
		cout << get<0>(e) + 1 << " " << get<1>(e) + 1 << '\n';
	}

	return 0;
}
