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
    string s;
    cin >> s;
    vector<pii> vis(n, {-1, -1});
    vector<pii> vis2(n, {-1, -1});
    queue<array<int, 3>> q;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'S') {
    		q.push({0, i, i});
    		vis[i] = {0, i};
    	}
    }
    while (!q.empty()) {
    	auto [d, u, sc] = q.front();
    	q.pop();
    	for (int v: e[u]) {
    		if (vis[v].first == -1) {
    			vis[v] = {d + 1, sc};
    			q.push({d + 1, v, sc});
    		} else if (vis2[v].first == -1 && vis[v].second != sc) {
    			vis2[v] = {d + 1, sc};
    			q.push({d + 1, v, sc});
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	//cout << i << " " << vis[i].first << " " << vis2[i].first << endl;
    	if (s[i] == 'D') {
    		cout << vis[i].first + vis2[i].first << endl;
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
