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
class DSU {
public:
    vector<int> parent, size;
    vector<set<int>> vs;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        vs.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            vs[i].insert(i); 
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
            for (int x : vs[b]) {
            	vs[a].insert(x);
            }
            size[a] += size[b];
        }
    }
};
void solve() {
    int n, m, c, q;
    cin >> n >> m >> c >> q;
    vector<map<int, int>> vm(n);
    vector<set<int>> vs(n);
    DSU D(n);
    for (int i = 0; i < m; i++) {
    	int u, v, z;
    	cin >> u >> v >> z;
    	u--; v--;
    	auto it = vm[u].find(z);
    	if (it != vm[u].end()) {
    		D.unite(v, it -> second);
    	}

    	it = vm[v].find(z);
    	if (it != vm[v].end()) {
    		D.unite(u, it -> second);
    	}
    	vm[u][z] = v;
    	vm[v][z] = u;
    	vs[u].insert(v);
    	vs[v].insert(u);
    }
    for (int i = 0; i < q; i++) {
    	string s;
    	cin >> s;
    	if (s == "?") {
    		int x, y;
    		cin >> x >> y;
    		x--; y--;
    		int flag = 0;
    		//cout << (D.find(x) == D.find(y) ? "Yes" : "No") << endl;
    		if (D.find(x) != D.find(y)) {
    			auto first = &(D.vs[D.find(x)]);
    			auto second = &vs[y];
    			if (first -> size() > second -> size()) {
    				swap(first, second);
    			}
    			auto it = first -> begin();
    			while (it != first -> end()) {
    				int u = *it;
    				if (second -> find(u) != second -> end()) {
    					flag = 1;
    					break;
    				}
    				++it;
    			}
    		} else {
    			flag = 1;
    		}
    		cout << (flag ? "Yes" : "No") << endl;
    	} else {
    		int u, v, z;
	    	cin >> u >> v >> z;
	    	u--; v--;
	    	auto it = vm[u].find(z);
	    	if (it != vm[u].end()) {
	    		D.unite(v, it -> second);
	    	}

	    	it = vm[v].find(z);
	    	if (it != vm[v].end()) {
	    		D.unite(u, it -> second);
	    	}
	    	vm[u][z] = v;
	    	vm[v][z] = u;
    		vs[u].insert(v);
    		vs[v].insert(u);
    	}
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
