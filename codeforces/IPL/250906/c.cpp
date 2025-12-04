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
    vi x(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i];
    }
    vi mark(n);
    priority_queue<pii, vector<pii>, greater<>> pq;
    int cur = x[0];
    pq.push({0, 0});
    mark[0] = 1;
    while (!pq.empty()) {
    	auto [w, u] = pq.top();
    	pq.pop();
    	if (w >= cur) {
    		break;
    	} else {
    		cur += w;
    	}
    	for (int v : e[u]) {
    		if (!mark[v]) {
    			mark[v] = 1;
    			pq.push({x[v], v});
    		}
    	}
    }
    cout << cur << endl;
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
