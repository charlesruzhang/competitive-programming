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
    int h, w, k;
    cin >> h >> w >> k;
    DSU D(k + 4);
    map<pii, int> ma;
    for (int i = 0; i < k; i++) {
    	int x, y;
    	cin >> x >> y;
    	ma[{x - 1, y - 1}] = i;
    	if (x == 1) {
    		D.unite(i, k);
    	}
    	if (x == h) {
    		D.unite(i, k + 1);
    	}
    	if (y == 1) {
    		D.unite(i, k + 2);
    	}
    	if (y == w) {
    		D.unite(i, k + 3);
    	}
    }
    auto it = ma.begin();
    while (it != ma.end()) {
    	auto [x, y] = it -> first;
    	int z = it -> second;
    	auto it2 = ma.find({x, y - 1});
    	if (it2 != ma.end()) {
    		int z2 = it2 -> second;
    		D.unite(z, z2);
    	}
    	it2 = ma.find({x, y + 1});
    	if (it2 != ma.end()) {
    		int z2 = it2 -> second;
    		D.unite(z, z2);
    	}
    	it2 = ma.find({x + 1, y + 1});
    	if (it2 != ma.end()) {
    		int z2 = it2 -> second;
    		D.unite(z, z2);
    	}
    	it2 = ma.find({x + 1, y});
    	if (it2 != ma.end()) {
    		int z2 = it2 -> second;
    		D.unite(z, z2);
    	}
    	it2 = ma.find({x + 1, y - 1});
    	if (it2 != ma.end()) {
    		int z2 = it2 -> second;
    		D.unite(z, z2);
    	}
    	++it;
    }
    if (D.find(k) == D.find(k + 1) || D.find(k + 2) == D.find(k + 3) || D.find(k) == D.find(k + 2) || D.find(k + 1) == D.find(k + 3)) {
    	cout << "No" << endl;
    } else {
    	cout << "Yes" << endl;
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
