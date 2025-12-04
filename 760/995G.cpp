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
const ll MAXX = 1e9+7;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<pii> qrs;
    vi vec(n);
    for (int i = 0; i < q; i++) {
    	int z;
    	string s;
    	cin >> z >> s;
    	if (s == "+") {
    		qrs.push_back({z - 1, 1});
    		vec[z - 1]++;
    	} else {
    		qrs.push_back({z - 1, -1});
    	}
    }
    vvi e(n + 1, vi(n+1, 1e9));
    for (int i = 0; i < n; i++) {
    	e[i][n] = vec[i];
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (i == j) continue;
    		int minn = 0;
    		int cur = 0;
    		for (int x = 0; x < q; x++) {
    			if (qrs[x].first != i && qrs[x].first != j) continue;
    			auto [z, w] = qrs[x];
    			if (z == i && w == 1) {
    				cur--;
    			} else if (z == j && w == -1) {
    				cur++;
    			}
    			minn = min(minn, cur);
    		}
    		e[i][j] = 1 - minn;
    	}
    }
   	n++;
    vvi dist = e;
    for (int i = 0; i < n; i++) {
    	dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        } 
    }
    // for (int i = 0; i < n; i++) {
    // 	for (int j = 0; j < n; j++) {
    // 		cout << i << " " << j << " " << dist[i][j] << " " << e[i][j] << endl;
    // 	}
    // }
    vvi dp((1 << n), vi(n, MAXX));
    for (int k = 0; k < n; k ++) {
        dp[0][k] = 0;
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (i & (1 << k)) {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    int minans = MAXX;
    for (int i = 0; i < n; i++) {
        minans = min(minans, dp[(1 << n) - 1][i]);
    }
    cout << 1 + minans << endl;
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
