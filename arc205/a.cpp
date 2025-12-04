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
void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
    	cin >> vs[i];
    }
    vvi b(n, vi(n));
    vvi pref(n+1, vi(n+1));
    for (int i = 0; i < n - 1; i++) {
    	for (int j = 0; j < n - 1; j++) {
    		b[i][j] = 1;
    		for (int x = 0; x < 2; x++) {
    			for (int y = 0; y < 2; y++) {
    				if (vs[i+x][j+y] == '#') {
    					b[i][j] = 0;
    				}
    			}
    		}
    		pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + b[i][j];
    	}
    }
    while (q--) {
    	int u, d, l, r;
    	cin >> u >> d >> l >> r;
    	u--; d--; l--; r--;
    	cout << pref[d][r] - pref[d][l] - pref[u][r] + pref[u][l] << endl;
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
