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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    vi P(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
    	cin >> P[i];
    }
    vector<ll> pref(n+m);
    for (int i = 0; i < n + m - 1; i++) {
    	pref[i+1] = pref[i] + P[i];
    }
    ll l = 0;
    ll r = 1e18;
    auto check = [&] (ll mi) {
    	mi = -mi;
    	vvl b(n, vl(m));
    	vvi D(n, vi(m));
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			b[i][j] = a[i][j];
    			int f = 0;
    			if (i) {
    				if (D[i-1][j]) {
    					b[i][j] = max(b[i][j], b[i-1][j] + a[i][j]);
    					f = 1;
    				}
    			}
    			if (j) {
    				if (D[i][j-1]) {
    					b[i][j] = max(b[i][j], b[i][j-1] + a[i][j]);
    					f = 1;
    			    }
    			}
    			if (b[i][j] < mi + pref[i+j+1]) continue;
    			else {
    				if (i == 0 && j == 0) {
    					D[i][j] = 1;
    				} else if (f) {
    					D[i][j] = 1;
    				} else {
    					continue;
    				}
    			}
    		}
    	}
    	return D[n-1][m-1] == 1;
    };
    while (l < r) {
    	ll mi = (l + r) / 2;
    	if (check(mi)) {
    		r = mi;
    	} else {
    		l = mi + 1;
    	}
    }
    cout << l << endl;
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
