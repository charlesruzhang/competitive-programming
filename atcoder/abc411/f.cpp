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
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
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
    vector<set<int>> e(n);
    vector<pii> f;
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].insert(v);
    	e[v].insert(u);
    	f.push_back({u, v});
    }
    DSU D(n);
    int q;
    cin >> q;
    int cur = m;
    while (q--) {
    	int x;
    	cin >> x;
    	auto [u, v] = f[x-1];
    	if (D.find(u) == D.find(v)) {
    		cout << cur << endl;
    		continue;
    	}
    	int pu = D.find(u);
    	int pv = D.find(v);
    	D.unite(u, v);
    	int puv = D.find(v);
    	int tar;
    	if (puv == pv) {
    		tar = pu;
    	} else {
    		tar = pv;
    	}
    	auto it = e[tar].begin();
    	while (it != e[tar].end()) {
    		int z = *it;
    		e[z].erase(tar);
    		if (z == puv) {
    			++it;
    			continue;
    		}
    		if (e[z].find(puv) != e[z].end()) {
    			cur --;
    		} else {
    			e[z].insert(puv);
    			e[puv].insert(z);
    		}
    		++it;
    	}
    	cur--;
    	cout << cur << endl;
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
