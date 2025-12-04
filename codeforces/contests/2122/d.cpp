// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
void solve(int t) {
    int n, m;
    cin >> n >> m;
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    cout << endl;
    vector<vector<pii>> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i].resize(e[i].size(), {1e16, 0});
    }
    dist[0][0] = {0, 0};
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
    pq.push({0, 0, 0, 0});
    vvi vis(n);
    for (int i = 0; i < n; i++) {
        vis[i].resize(e[i].size(), 0);
    }
    while (!pq.empty()) {
    	auto [x, y, u, idx] = pq.top();
        cout << x << " " << y << " " << u << " " << idx << endl;
    	pq.pop();
        if (vis[u][idx]) continue;
        vis[u][idx] = 1;
        int i = idx + 1;
		if (dist[u][i % e[u].size()] > pii(x + 1, y + 1)) {
			dist[u][i % e[u].size()] = {x + 1, y + 1};
            pq.push({x + 1, y + 1, u, i % e[u].size()});
		}
    	int v = e[u][idx];
        if (dist[v][(x + 1) % e[v].size()] > pii(x + 1, y)) {
            dist[v][(x + 1) % e[v].size()] = {x + 1, y};
            pq.push({x + 1, y, v, (x + 1) % e[v].size()});
        }
    }
    pii ans = {1e16, 0};
    for (int i = 0; i < e[n-1].size(); i++) {
    	ans = min(ans, dist[n-1][i]);
    }
    cout << ans.first << " " << ans.second << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}
