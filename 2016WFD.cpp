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
    int n;
    cin >> n;
    vector<vector<string>> P(n, vector<string>(7));
    vvi D(11, vi(14));
    D[0] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1};
    D[1] = {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0};
    D[2] = {1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1};
    D[3] = {1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1};
    D[4] = {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0};
    D[5] = {1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    D[6] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    D[7] = {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0};
    D[8] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    D[9] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1};
    D[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vvi mask(7, vi(21, 0));
    mask[2][10] = 1;
    mask[4][10] = 1;
    vi T = {0, 5, 12, 17};
    for (int t : T) {
    	for (int j = 0; j < 7; j++) {
    		if (j % 3 == 0) {
    			mask[j][t + 1] = 1;
    			mask[j][t + 2] = 1;
    		} else {
    			mask[j][t] = 1;
    			mask[j][t + 3] = 1;
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 7; j++) {
    		cin >> P[i][j];
    	}
    }
    vvi ans(7, vi(21, 0));
    for (int i = 0; i < 1440; i++) {
    	vvi M(7, vi(21, 7));
    	for (int j = 0; j < n; j++) {
    		int cur = (i + j) % 1440;
    		int L = cur / 60;
    		int R = cur % 60;
    		vi a(4);
    		a[0] = (L / 10 == 0 ? 10 : L / 10);
    		a[1] = L % 10;
    		a[2] = R / 10;
    		a[3] = R % 10;

    		for (int k = 0; k < 4; k++) {
    			int t = T[k];
    			for (int l = 0; l < 7; l++) {
    				auto check = [&] (int u, int v) {
						if (P[j][l][u] == '.') {
    						if (D[a[k]][2 * l + v] == 1) {
    							M[l][u] &= 2;
    						} else {
    							M[l][u] &= 3;
    						}
    					} else {
    						if (D[a[k]][2 * l + v] == 1) {
    							M[l][u] &= 5;
    						} else {
    							M[l][u] &= 4;
    						}
    					}
    				};
    				if (l % 3 == 0) {
    					check(t + 1, 0);
    					check(t + 2, 1);
    				} else {
    					check(t, 0);
    					check(t + 3, 1);
    				}
    			}
    		}
    	}
    	int flag = 1;
    	for (int j = 0; j < 7; j++) {
    		for (int k = 0; k < 21; k++) {
    			if (mask[j][k] && !M[j][k]) {
    				flag = 0;
    				break;
    			}
    		}
    	}
    	if (flag == 0) continue;
    	// cout << i << endl;
    	// for (int j = 0; j < 7; j++) {
    	// 	for (int k = 0; k < 21; k++) {
    	// 		if (mask[j][k]) cout << M[j][k];
    	// 		else cout << 0;
    	// 	}
    	// 	cout << endl;
    	// }
    	for (int j = 0; j < 7; j++) {
    		for (int k = 0; k < 21; k++) {
    			ans[j][k] |= M[j][k];
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (P[i][2][10] == '.') {
    		ans[2][10] &= 2;
    	} else {
    		ans[2][10] &= 5;
    	}
    	if (P[i][4][10] == '.') {
    		ans[4][10] &= 2;
    	} else {
    		ans[4][10] &= 5;
    	}
    }
    for (int i = 0; i < 7; i++) {
    	for (int j = 0; j < 21; j++) {
    		if (mask[i][j]) {
    			if (ans[i][j] == 0) {
    				cout << "impossible" << endl;
    				return;
    			}
    		}
    	}
    }
    for (int i = 0; i < 7; i++) {
    	for (int j = 0; j < 21; j++) {
    		if (mask[i][j]) {
    			if (__builtin_popcount(ans[i][j]) >= 2) {
    				cout << '?';
    			} else if (ans[i][j] == 4) {
    				cout << 1;
    			} else if (ans[i][j] == 2) {
    				cout << 0;
    			} else if (ans[i][j] == 1) {
    				cout << 'W';
    			}
    		} else {
    			cout << '.';
    		}
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
