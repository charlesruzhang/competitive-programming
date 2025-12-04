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
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int p;
    	cin >> p;
    	p--;
    	e[i].push_back(p);
    	e[p].push_back(i);
    }
    vi deg(n);
    vi tot(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	tot[u] = 1;
    	priority_queue<pii> pq;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    			pq.push({deg[v], v});
    			tot[u] += tot[v];
    		}
    	}
    	if (!pq.empty()) {
    		auto [tmp, v] = pq.top();
    		deg[u] = max(((tot[u] & 1) ? (0) : (1)), tmp - (tot[u] - 1 - tot[v])) + 1;
    		//cout << u << "?" << deg[u] << endl;
    	} else{
    		deg[u] = 1;
    	}
    	while (pq.size() >= 2) {
    		auto [x, i] = pq.top();
    		pq.pop();
    		auto [y, j] = pq.top();
    		pq.pop();
    		if (x > 1) pq.push({x-1, i});
    		if (y > 1) pq.push({y-1, j});
    	}
    	deg[u] = min(deg[u], ((pq.empty()) ? 1 : (pq.top().first + 1)));
    	//cout << u << " " << deg[u] << endl;
    };
    dfs(0, -1);
    assert((n - deg[0]) % 2 == 0);
    cout << ((n - deg[0]) / 2) << endl;
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
