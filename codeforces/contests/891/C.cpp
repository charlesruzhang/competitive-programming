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
            if (size[b] > size[a]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges;
    
    vector<vector<pii>> W(5e5+1);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	W[w].push_back({u, v});
    	edges.push_back({w, u, v});
    }
    int q;
    cin >> q;
    vi ans(q, 1);
    DSU D(n);
    vector<vector<pair<int, vi>>> Q(5e5 + 1);
    for (int i = 0; i < q; i++) {
    	int sz;
    	cin >> sz;
    	vector<pii> vec;
    	for (int j = 0; j < sz; j++) {
    		int x;
    		cin >> x;
    		x--;
    		vec.push_back({edges[x][0], x});
    	}
    	sort(vec.begin(), vec.end());
    	int j = 0;
    	while (j < sz) {
    		vi tmp;
    		int target = vec[j].first;
    		tmp.push_back(vec[j].second);
    		j++;
    		while (j < sz && vec[j].first == target) {
    			tmp.push_back(vec[j].second);
    			j++;
    		}
    		Q[target].emplace_back(i, tmp);
    	}
    }
    for (int i = 1; i <= 5e5; i++) {
    	for (auto& [qidx, tmp]: Q[i]) {
    		vector<pii> ma;
    		for (int x : tmp) {
    			auto [w, u, v] = edges[x];
    			ma.push_back({D.find(u), D.find(v)});
    		}
    		for (auto [u, v] : ma) {
    			if (D.find(u) == D.find(v)) {
    				ans[qidx] = 0;
    			} else {
    				D.unite(u, v);
    			}
    		}
    		for (auto [u, v]: ma) {
    			D.parent[u] = u;
    			D.parent[v] = v;
    		}
    	}
    	for (auto [u, v] : W[i]) {
    		D.unite(u, v);
    	}
    }
    for (int i = 0; i < q; i++) {
    	cout << (ans[i] ? "YES" : "NO") << endl;
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
