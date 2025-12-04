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
const int INF = 1e9+7;
const ll MAXX = 1e16;
void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vvi dist(n+1, vi(n+1, INF));
	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
		dist[n][i] = s[i].size();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && s[i][s[i].size()-1] == s[j][0]) {
				dist[i][j] = s[j].size();
			}
		}
	}
	for (int k = 0; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	n++;
	vvi dp((1 << n), vi(n, INF));
	dp[1 << (n-1)][n-1] = 0;
	for (int i = (1 << (n-1)); i < (1 << n); i++) {
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
	int minans = INF;
    for (int i = 0; i < n; i++) {
        minans = min(minans, dp[(1 << n) - 1][i]);
    }
    cout << minans << endl;
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
