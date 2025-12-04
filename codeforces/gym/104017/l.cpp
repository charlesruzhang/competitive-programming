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
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    DSU D(21 * 360);
    vvi V(21, vi(360));

    vvi W(21, vi(360));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	if (s == "C") {
    		int r, t1, t2;
    		cin >> r >> t1 >> t2;
    		if (t2 < t1) t2 += 360;
    		for (int i = t1; i < t2; i++) {
    			V[r - 1][i % 360] = 1;
    		}
    	} else {
    		int r1, r2, t;
    		cin >> r1 >> r2 >> t;
    		for (int i = r1; i < r2; i++) {
    			W[i][t] = 1;
    		}
    	}
    }
    for (int i = 0; i < 21; i++) {
    	for (int j = 0; j < 360; j++) {
    		if (i != 20) {
    			if (!V[i][j]) {
    				D.unite(i * 360 + j, (i + 1) * 360 + j);
    			}
    		}
    		if (!W[i][j]) {
    			int p = (j == 0 ? 359 : j - 1);
    			D.unite(i * 360 + j, i * 360 + p);
    		}
    	}
    }
    if (D.find(0) == D.find(21 * 360 - 1)) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
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
