#include <bits/stdc++.h>
using namespace std;

const int maxn = 222222;

int tt, n, a[maxn], b[maxn];
vector<int> ans;

struct edge {
	int u, v, nxt;
	bool vis;
};

void Hierholzer(vector<edge>& e, vector<int>& head, int u) {
    for (int& i = head[u]; ~i; ) {
		if (! e[i].vis) {
			int v = e[i].v;
			e[i].vis = e[i ^ 1].vis = 1;
			int id = i;
			i = e[i].nxt;
			Hierholzer(e, head, v);
			ans.push_back(id / 2 + 1);
		} else i = e[i].nxt;
	}
}

int main() {
	scanf("%d", &tt);
	
	while (tt--) {
		scanf("%d", &n);
		
		map<int, int> ida, idb;
		int ts = 0;
		vector<int> deg(2 * n + 5, 0);
		vector<int> head(2 * n + 5, -1);
		vector<edge> e;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			
			if (ida.find(a[i]) == ida.end()) ida[a[i]] = ++ts;
			if (idb.find(b[i]) == idb.end()) idb[b[i]] = ++ts;
			
			int u = ida[a[i]], v = idb[b[i]];
			
			deg[u]++, deg[v]++;
			
			e.push_back({u, v, head[u], 0}), head[u] = e.size() - 1;
			e.push_back({v, u, head[v], 0}), head[v] = e.size() - 1;
		}
		
		int cnt = 0, v = 1;
		
		for (int i = 1; i <= ts; i++) {
			if (deg[i] & 1) cnt++, v = i;
		}
		
		if (cnt > 2) {
			puts("no");
			continue;
		}
		
		ans.clear();
		
		Hierholzer(e, head, v);
		
		if (ans.size() == n) {
			puts("yes");
			for (int k : ans) printf("%d ", k);
			puts("");
		} else puts("no");
	}
}
