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
const int INF = 1e9;
void solve() {
    int n, m;
    cin >> n >> m;
    vvi f(n, vi(n, INF));
    for (int i = 0; i < n; i++) {
    	f[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	x--; y--;
    	f[x][y] = min(f[x][y], z);
    }
    vvi g = f;
    for (int k = 0; k < n; k ++ ){
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n;j ++) {
    			g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    		}
    	}
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int k; cin >> k;
    	vi a(n);
    	for (int j = 0; j < n; j++) {
    		cin >> a[j];
    	}
    	for (int j = 0; j < n; j++) {
    		int z = a[j];
    		for (int l = 0; l < n; l++) { 
    			z = min(z, f[j][l] + a[l]);
    		}
    		int flag = 0;
    		for (int l = 0; l < n; l++) {
    			if (g[j][l] + a[l] - k < z && g[j][l] < f[j][l]) {
    				flag = 1;
    			}
    		}
    		cout << flag;
    	}
    	cout << endl;
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
