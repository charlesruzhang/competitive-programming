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
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<char>> a(n, vector<char>(m));
    int x = 0;
    int y = 0;
    vi cd;
    vi b;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		a[i][j] = s[j];
    		if (s[j] == 'o') {
    			//cd.push_back(i * m + j);
    			b.push_back(i * m + j);
    		} else if (s[j] == 'S') {
    			x = i * m + j;
    		} else if (s[j] == 'G') {
    			y = i * m + j;
    		}
    	}
    }
    b.push_back(x);
    b.push_back(y);
    int sz = b.size();
    vvl D(sz);
    for (int i = 0; i < sz; i++) {
    	vl dist(n * m, MAXX);
    	queue<int> q;
    	q.push(b[i]);
    	dist[b[i]] = 0;
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		int i = u / m;
    		int j = u % m;
    		if (i && a[i-1][j] != '#' && dist[i * m + j - m] == MAXX) {
    			dist[i * m + j - m] = dist[u] + 1;
    			q.push(i * m + j - m);
    		}
			if (j && a[i][j-1] != '#' && dist[i * m + j - 1] == MAXX) {
    			dist[i * m + j - 1] = dist[u] + 1;
    			q.push(i * m + j - 1);
    		}
    		if (i != n - 1 && a[i+1][j] != '#' && dist[i * m + j + m] == MAXX) {
    			dist[i * m + j + m] = dist[u] + 1;
    			q.push(i * m + j + m);
    		}
    		if (j != m - 1 && a[i][j+1] != '#' && dist[i * m + j + 1] == MAXX) {
    			dist[i * m + j + 1] = dist[u] + 1;
    			q.push(i * m + j + 1);
    		}
    	}
    	D[i] = move(dist);
    }
    if (D[sz - 2][y] > t) {
    	cout << -1 << endl;
    	return;
    }
    //int b = cd.size();
    //for (int i = 0; i < ())
    int N = n;
    n = b.size();
    vvl dp((1 << n), vl(n, MAXX));
    dp[0][n - 2] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (i & (1 << k)) {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + D[k][b[j]]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
    	if (dp[i][n - 1] <= t) {
    		ans = max(ans, __builtin_popcount(i) - 2);
    	} 
    }
    cout << ans << endl;
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
