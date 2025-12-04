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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> e(n);
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	e[u].push_back({v, w});
    	e[v].push_back({u, w});
    }
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({0, 0});
    vl dist(n, MAXX);
    vi vis(n);
    dist[0] = 0;
    while (!pq.empty()) {
    	auto [val, u] = pq.top();
    	pq.pop();
    	if (vis[u]) continue;
    	vis[u] = 1;
    	for (auto [v, w] : e[u]) {
    		if (dist[v] > val + w) {
    			dist[v] = val + w;
    			pq.push({dist[v], v});
    		}
    	}
    }
    for (int i = 0; i < k; i++) {
    	vector<array<ll, 3>> vp;
    	for (int j = 0; j < n; j++) {
    		int c = - 2 * j;
    		ll d = dist[j] + 1ll * j * j;
    		while (vp.size()) {
    			auto [b, a, T1] = vp.back();
    			ll x = (d - b + (a - c - 1)) / (a - c);
    			if (T1 >= x) {
    				vp.pop_back();
    			} else {
    				break;
    			}
    		}
    		if (!vp.size()) vp.push_back({d, c, 0});
    		else {
    			auto [b, a, T1] = vp.back();
    			ll x = (d - b + (a - c - 1)) / (a - c);
    			vp.push_back({d, c, x});
    		}
    	}

    	priority_queue<pll, vector<pll>, greater<>> pq2;
    	for (int j = 0; j < n; j++) {
			int l = 0;
			int r = (int)vp.size() - 1;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				auto [TT, UU, val] = vp[mid];
				if (val > j) {
					r = mid - 1;
				} else {
					l = mid;
				}
			}
			auto [b, a, T1] = vp[l];
			// cout << b << " " << a << " " << j << " " << dist[j] << endl;
			// cout << "! " << b + a * j + 1ll * j * j << endl;
			if (dist[j] > b + a * j + 1ll * j * j) {
				dist[j] = b + a * j + 1ll * j * j;
				pq2.push({dist[j], j});
			}
		}
		vi vis2(n);
		while (!pq2.empty()) {
			auto [val, u] = pq2.top();
			pq2.pop();
			if (vis2[u]) continue;
			vis2[u] = 1;
			for (auto [v, w] : e[u]) {
				if (dist[v] > val + w) {
					dist[v] = val + w;
					pq2.push({dist[v], v});
				}
			}
		}
    }
    for (int i = 0; i < n; i++) {
    	cout << dist[i] << " ";
    }
    cout << endl;
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
