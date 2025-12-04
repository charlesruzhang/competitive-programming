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
    vector<int> parent, size, val;
    DSU(int n) {
        parent.resize(n);
        val.resize(n);
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
            val[a] += val[b];
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    int ans = 0;
    DSU D(n * m);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j] == 0) continue;
    		D.val[i * m + j] = a[i][j];
    		if (i && a[i-1][j] != 0) {
    			D.unite(i * m + j, i * m + j - m);
    		}
    		if (j && a[i][j-1]) {
    			D.unite(i * m + j, i * m + j - 1);
    		}
    		ans = max(ans, D.val[D.find(i * m + j)]);
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
