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
void solve() {
    int n, q;
    cin >> n >> q;
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vector<tuple<int, int,int>> qrs(q);
    for (int i = 0; i < q; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	x--; y--; z--;
    	qrs[i] = {x, y, z};
    }
    vi F = b;
    vi G(n);
    for (int i = q - 1; i >= 0; i--) {
    	auto [x, y, z] = qrs[i];
    	if (F[z] == -1) {
    		if (z != x && z != y) G[z] = 1;
    		else {
    			if (z == y && F[x] != -1) {
    				if (F[x] < G[z]) {
    					cout << -1 << endl;
    					return;
    				}
    			} else if (z == x && F[y] != -1) {
    				if (F[y] < G[z]) {
    					cout << -1 << endl;
    					return;
    				}
    			}
    		}
    		continue;
    	}
    	if (F[x] == -1 && F[y] == -1) {
    		if (G[x] > F[z] && G[y] > F[z]) {
    			cout << "-1" << endl;
    			return;
    		}
    		G[x] = max(G[x], F[z]);
    		G[y] = max(G[y], F[z]);
			F[z] = -1;
			G[z] = 1;
    	} else if (F[x] != -1 && F[y] != -1) {
    		if (min(F[x], F[y]) != F[z]) {
    			cout << -1 << endl;
    			return;
    		}
    		if (z == x || z == y) {
    			if (F[x] == F[y]) {
    				F[z] = -1;
    				G[z] = F[x];
    			}
    		} else {
    			F[z] = -1;
    			G[z] = 1;
    		}
    	} else if (F[x] == -1 && F[y] != -1) {
    		if (z == y) {
    			
    		}
    	}
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
