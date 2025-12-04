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
    vi minn;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        minn.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
            minn[i] = 2e9 + 2;
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
            minn[a] = min(minn[a], minn[b]);
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e;
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--; 
    	e.push_back({w, u, v});
    }
    DSU D(n);
    ll ans = 1e16;
    sort(e.begin(), e.end());
    for (int i = 0; i < m; i++) {
    	auto [w, u, v] = e[i];
    	D.unite(u, v);
    	D.minn[D.find(u)] = min(D.minn[D.find(u)], w);
    	if (D.find(0) == D.find(n-1)) {
    		ans = min(ans, (ll) D.minn[D.find(0)] + w);
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
