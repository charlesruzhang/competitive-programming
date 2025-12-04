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
const ll MAXX = 1e17;
const int INF = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vvl dist(n, vl(n, MAXX));
    for (int i = 0; i < n; i++) {
    	dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	a--; b--;
    	dist[a][b] = min(dist[a][b], (ll) c);
    	dist[b][a] = dist[a][b];
    }
    int K;
    cin >> K;
    int T;
    cin >> T;
    vi pp(K);
    vi mark(n);
    for (int i = 0; i < K; i++) {
    	cin >> pp[i];
    	pp[i]--;
    	mark[pp[i]] = 1;
    }
    for (int i = 0; i < K; i++) {
    	for (int j = 0; j < K; j++) {
    		dist[pp[i]][pp[j]] = min(dist[pp[i]][pp[j]], (ll) T);
    	}
    }
    vvl D = dist;
    for (int k = 0; k < n; k++) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    		}
    	}
    }
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		tot += (D[i][j] == MAXX) ? 0 : D[i][j];
    	}
    }

    int q;
    cin >> q;
    while (q--) {
    	int x;
    	cin >> x;
        auto func = [&] (int u, int v, int w) {
            ll prev = D[u][v];
            ll now = D[u][w] + D[w][v];
            if (prev <= now) return false;
            tot += 2 * now;
            tot -= 2 * ((prev == MAXX) ? 0 : prev);
            D[u][v] = D[v][u] = now;
            return true;
        };
    	if (x == 1) {
    		int u, v, t;
    		cin >> u >> v >> t;
    		u--; v--;
    		if (D[u][v] <= t) {
    			continue;
    		}
    		tot -= (D[u][v] - t) * 2;
            if (D[u][v] == MAXX) tot += 2 * MAXX;
    		D[u][v] = D[v][u] = t;
    		vi l, r;
    		for (int i = 0; i < n; i++) {
    			if (func(i, v, u)) {
    				l.push_back(i);
    			} else if (func(i, u, v)) {
    				r.push_back(i);
    			}
    		}
    		for (int i : l) {
    			for (int j : r) {
    				func(i, j, u);
    			}
    		}
    	} else if (x == 2) {
    		int u;
    		cin >> u;
    		u--;
            if (mark[u]) continue;
    		vi air, A, B, C;
    		for (int i = 0; i < n; i++) {
    			if (i == u) continue;
    			if (mark[i]) {
    				if (D[u][i] > T) {
    					tot -= 2 * (D[u][i] - T);
                        if (D[u][i] == MAXX) tot += 2 * MAXX;
    					D[u][i] = D[i][u] = T;
                        air.push_back(i);
    				}
    			} else {
    				A.push_back(i);
    			}
    		}
    		for (int j : A) {
    			int f = 0;
    			for (int i : air) {
    				if (func(j, u, i)) {
    					f = 1;
    				}
    			}
    			if (f) {
    				B.push_back(j);
    			} else {
    				C.push_back(j);
    			}
    		}
    		for (int i : B) {
    			for (int j : C) {
    				func(i, j, u);
    			}
    		}
    		mark[u] = 1;
    	} else {
    		cout << tot << endl;
    	}
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
