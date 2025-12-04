#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

struct DSU {
	vi parent, size;
	DSU (int n) {
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a != b) {
			if (size[a] < size[b]) swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	DSU D(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		D.unite(u, v);
	}
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		maxx = max(maxx, D.size[D.find(i)]);
	}
	cout << maxx << endl;
}


int main() {
	solve();
	return 0;
}