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
    int n;
    cin >> n;
  	int m1, m2;
  	cin >> m1 >> m2;
  	vvi e(n), f(n);
  	for (int i = 0; i < m1; i++) {
  		int u, v;
  		cin >> u >> v;
  		u--; v--;
  		e[u].push_back(v);
  		e[v].push_back(u);
  	}
  	for (int i = 0; i < m2; i++) {
  		int u, v;
  		cin >> u >> v;
  		u--; v--;
  		f[u].push_back(v);
  		f[v].push_back(u);
  	}
  	DSU D(n);
  	for (int i = 0; i < n; i++) {
  		for (int v : f[i]) {
  			D.unite(i,v);
  		}
  	}
  	DSU E(n);
  	int ans = 0;
  	for (int i = 0; i < n; i++) {
  		for (int v : e[i]) {
  			if (v > i) continue;
  			if (D.find(i) != D.find(v)) {
  				ans++;
  			} else {
  				E.unite(i, v);
  			}
  		}
  	}
  	//cout << "? " << ans << endl;
  	for (int i = 0; i < n; i++) {
  		if (E.find(i) != E.find(D.find(i))) {
  			E.unite(D.find(i), i);
  			ans++;
  		}
  	}
  	cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
