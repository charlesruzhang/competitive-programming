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
    int h, w;
    cin >> h >> w;
    vvl a(h, vl(w));
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		cin >> a[i][j];
    	}
    }
    ll maxx = 0;
    for (int i = 0; i < (1 << (h * w)); i++) {
    	DSU D(h * w);
    	int X = 0;
    	int Y = 0;
    	for (int j = 0; j < h; j++) {
    		for (int k = 0; k < w; k++) {
    			int y = j * w + k;
    			int z = y - 1;
    			int x = y - w;
    			if (!((1 << y) & i)) continue;
    			if (k && (1 << z) & i) {
    				D.unite(y, z);
    			}
    			if (j && (1 << x) & i) {
    				D.unite(y, x);
    			}
    			if ((j + k) % 2 == 1) {
    				X++;
    			} else {
    				Y++;
    			}
    		}
    	}
    	if (X != Y) continue;
    	int flag = 1;
    	for (int j = 0; j < h * w; j++) {
    		if (((1 << j) & i) && D.size[D.find(j)] % 2 == 1) {
    			flag = 0;
    			break;
    		}
    	}
    	if (!flag) continue;
    	ll tot = 0;
    	for (int j = 0; j < h; j++) {
    		for (int k = 0; k < w; k++) {
    			int y = j * w + k;
    			if (!((1 << y) & i)) {
    				tot ^= a[j][k];
    			}
    		}
    	}
    	maxx = max(maxx, tot);
    }
    cout << maxx << endl;
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
