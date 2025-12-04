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
    int n, m, l;
    cin >> n >> m >> l;
    vi a(l);
    for (int i = 0; i < l; i++) {
    	cin >> a[i];
    }
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 0, 0});
    vvi best(n, vi(2, 1e9));
    vvi visited(n, vi(2));
    visited[0][0] = 1;
    best[0][0] = 0;
    while (!pq.empty()) {
    	auto [x, y, z] = pq.top();
    	pq.pop();
    	for (int v : e[y]) {
    		if (!visited[v][1-z]) {
    			visited[v][1-z] = 1;
    			best[v][1-z] = x + 1;
    			pq.push({x + 1, v, 1 - z});
    		}
    	}
    }
    int minodd = 1e9+1;
    ll summ = 0;
    for (int i = 0; i < l; i++) {
    	if (a[i] % 2 == 1) {
    		minodd = min(minodd, a[i]);
    	}
    	summ += a[i];
    }
    vi tar(2);
    if (summ % 2 == 0) {
    	tar[0] = summ;
    	tar[1] = (minodd == 1e9 + 1) ? -1 : summ - minodd;
    } else {
    	tar[1] = summ;
    	tar[0] = summ - minodd;
    }
    vi ans(n);
    for (int i = 0; i < n; i++) {
    	if ((best[i][0] != 1e9 && best[i][0] <= tar[0]) || (best[i][1] != 1e9 && best[i][1] <= tar[1])) {
    		ans[i] = 1;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i];
    }
    cout << endl;
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
