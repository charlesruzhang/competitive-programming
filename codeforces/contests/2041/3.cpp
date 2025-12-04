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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	pii source;
	pii dest;
	// 12 = no op, 0 = left, 3 = right, 6 = up, 9 = down
	vvi e(12 * n * m + 1);
	vvi c(n, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ;j++) {
			if (s[i][j] == 'S') {
				source = {i, j};	
			}
			if (s[i][j] == 'T') {
				dest = {i, j};
			}
			if (s[i][j] == '#') {
				c[i][j] = 0;
			} else {
				c[i][j] = 1;
			}
		}
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i && c[i][j] && c[i-1][j]) {
				int tar = 9;
				for (int k = 0; k < 12; k++) {
					if (k != tar+2) {
						int f = (k == tar) ? tar+1 : ((k == tar + 1) ? tar+2 : tar);
						e[k * n * m + (i - 1) * m + j].push_back(f * n * m + i * m + j);
					}
				}
				tar = 6;
				for (int k = 0; k < 12; k++) {
					if (k != tar+2) {
						int f = (k == tar) ? tar+1 : ((k == tar + 1) ? tar+2 : tar);
						e[k * n * m + i * m + j].push_back(f * n * m + (i - 1) * m + j);
					}
				}
			}
			if (j && c[i][j] && c[i][j-1]) {
				int tar = 0;
				for (int k = 0; k < 12; k++) {
					if (k != tar+2) {
						int f = (k == tar) ? tar+1 : ((k == tar + 1) ? tar+2 : tar);
						e[k * n * m + i * m + j].push_back(f * n * m + i * m + j - 1);
					}
				}
				tar = 3;
				for (int k = 0; k < 12; k++) {
					if (k != tar+2) {
						int f = (k == tar) ? tar+1 : ((k == tar + 1) ? tar+2 : tar);
						e[k * n * m + i * m + j - 1].push_back(f * n * m + i * m + j);
					}
				}
			}
		}
	}
	auto [y, z] = source;
	int tot = 12 * n * m;
	e[12 * n * m].push_back(0 * n * m + y * m + z);
	e[12 * n * m].push_back(3 * n * m + y * m + z);
	e[12 * n * m].push_back(6 * n * m + y * m + z);
	e[12 * n * m].push_back(9 * n * m + y * m + z);
	vi dist(tot + 1, 1e9);
	dist[tot] = 0;
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({0, tot});
	vi visited(tot + 1);
	int ans = 1e9;
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();
		visited[u] = 1;
		if (u % (n * m) == dest.first * m + dest.second) {
			ans = min(ans, x);
		}
		for (int v : e[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				pq.push({dist[v], v});
			}
		}
	}
	if (ans == 1e9) {
		cout << -1 << endl;
	} else {
		cout << ans - 1 << endl;
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
