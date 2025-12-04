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
void solve(int n, vector<pii>& a) {
    vector<pii> edges(n);
    vector<vector<pii>> e(2 * n);
    for (int i = 0; i < n; i++) {
    	int u, v;
    	u = a[i].first;
    	v = a[i].second;
    	u--; v--;
    	edges[i] = {u, v};
    	e[u].push_back({v, i});
    	e[v].push_back({u, i});
    }
    cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << endl;
	}
    vi vis(n);
    vi vis2(2 * n);
    priority_queue<array<int, 4>> pq;
    vi used(n);
    int d = 0;
    vector<vector<pii>> children(4 * n);
    vector<pii> parent(4 * n, {-1, -1});
    int timer = 2 * n;
    vi match(4 * n);
    for (int i = 0; i < 2 * n; i++) {
    	match[i] = i;
    }
    vi sz(4 * n);
    function <void(int)> dfs = [&] (int u) {
    	vis2[u] = 1;
    	for (auto [v, w]: e[u]) {
    		if (!vis[w]) {
    			vis[w] = 1;  
    			if (vis2[v]) {
    				match[timer] = v;
    				children[u].push_back({w, timer});
    				parent[timer] = {u, w};
    				pq.push({d, w, timer, u});
    				timer++;
    			} else {
    				children[u].push_back({w, v});
    				pq.push({d, w, v, u});
    				parent[v] = {u, w};
    				d++;
	    			dfs(v);
	    			sz[u] += sz[v] + 1;
	    			d--;
    			}  			
    		}
    	}
    };
    vvi ans(2);
    vector<vector<char>> G(2);
    vector<vector<char>> H(2);
    for (int i = 0; i < 2 * n; i++) {
    	if (!vis2[i]) {
    		dfs(i);
    		if (pq.size() == 1) {
    			//cout << -1 << endl;
    			return;
    		}
    		if (pq.size() % 2 == 1) {
    			auto [dis, w, v, u] = pq.top();
    			pq.pop();
    			used[w] = 1;
    			int cnt = 1;
    			vector<array<int, 2>> tmp;
    			tmp.push_back({v, u});
    			int type = 0;
    			for (auto [w2, v2] : children[u]) {
    				if (used[w2]) continue;
    				used[w2] = 1;
    				tmp.push_back({u, v2});
    				cnt++;
    				if (cnt == 3) {
    					type = 1;
    					break;
    				}
    			}
    			if (cnt == 2) {
    				type = 1;
    			}
    			if (cnt <= 2) {
    				used[parent[u].second] = 1;
    				tmp.push_back({u, parent[u].first});
    				cnt++;
    				u = parent[u].first;
    			}
    			if (cnt <= 2) {
    				for (auto [w2, v2] : children[u]) {
	    				if (used[w2]) continue;
	    				if (sz[v2] % 2 == 1) continue;
	    				used[w2] = 1;
	    				tmp.push_back({u, v2});
	    				cnt++;
    					type = 2;
    					break;
	    			}
	    			if (cnt <= 2) {
	    				assert(parent[u].first != -1);
	    				used[parent[u].second] = 1;
	    				tmp.push_back({u, parent[u].first});
	    				cnt++;
	    				type = 2;
	    				u = parent[u].first;
	    			}
    			}
    			// cout << type << endl;
    			// cout << tmp[0][0] << " " << tmp[0][1] << " " << tmp[1][1] << " " << tmp[2][1] << endl;
    			assert(cnt == 3);
    			if (type == 1) {
    				ans[0].push_back(tmp[0][0]);
    				ans[0].push_back(tmp[0][1]);
    				ans[0].push_back(tmp[1][1]);
    				ans[1].push_back(tmp[0][1]);
    				ans[1].push_back(tmp[2][1]);
    				ans[1].push_back(tmp[0][1]);
    			} else {
    				ans[0].push_back(tmp[0][0]);
    				ans[0].push_back(tmp[0][1]);
    				ans[0].push_back(tmp[1][1]);
    				ans[1].push_back(tmp[0][1]);
    				ans[1].push_back(tmp[1][1]);
    				ans[1].push_back(tmp[2][1]);
    			}
    			G[0].push_back({'U'});
    			G[0].push_back({'L'});
    			G[0].push_back({'R'});
    			G[1].push_back({'D'});
    			G[1].push_back({'L'});
    			G[1].push_back({'R'});

    			H[0].push_back({'L'});
    			H[0].push_back({'R'});
    			H[0].push_back({'U'});
    			H[1].push_back({'L'});
    			H[1].push_back({'R'});
    			H[1].push_back({'D'});
    			// cout << ans[0].size() << endl;
    			// for (int z = 0; z < 2; i++) {
    			// 	for (int zz = 0; zz < ans[0].size(); zz++) {
    			// 		cout << ans[z][zz] << " ";
    			// 	}
    			// 	cout << endl;
    			// }
    		}
    		while (!pq.empty()) {
    			auto [dis, w, v, u] = pq.top();
    			pq.pop();
    			if (used[w]) continue;
    			used[w] = 1;
    			int X = -1;
    			for (auto [w2, v2] : children[u]) {
    				if (used[w2]) continue;
    				used[w2] = 1;
    				X = v2;
    				break;
    			}
    			if (X == -1) {
    				X = parent[u].first;
    				used[parent[u].second] = 1;
    			}
    			ans[0].push_back(v);
    			ans[0].push_back(u);
    			ans[1].push_back(u);
    			ans[1].push_back(X);

    			G[0].push_back({'L'});
    			G[0].push_back({'R'});
    			G[1].push_back({'L'});
    			G[1].push_back({'R'});

    			H[0].push_back({'U'});
    			H[0].push_back({'U'});
    			H[1].push_back({'D'});
    			H[1].push_back({'D'});
    		}
    	}
    }
    if (ans[0].size() != n) {
    	// cout << n << endl;
    	// for (int i = 0; i < n; i++) {
    	// 	auto [u, v] = a[i];
    	// 	cout << u << " " << v << endl;
    	// }
    }
    assert(ans[0].size() == n);
    // cout << 2 << " " << n << endl;
    // for (int i = 0; i < 2; i++) {
    // 	for (int j = 0; j < n; j++) {
    // 		cout << match[ans[i][j]] + 1 << " ";
    // 	}
    // 	cout << endl;
    // }

    // for (int i = 0; i < 2; i++) {
    // 	for (int j = 0; j < n; j++) {
    // 		cout << G[i][j];
    // 	}
    // 	cout << endl;
    // }

    // for (int i = 0; i < 2; i++) {
    // 	for (int j = 0; j < n; j++) {
    // 		cout << H[i][j];
    // 	}
    // 	cout << endl;
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1000;
   	mt19937 rng(5);
    while (t--) {
    	int n = 6;
    	auto R = uniform_int_distribution<int>(1, 6);
    	vector<pii> a;
    	for (int i = 0; i < n; i++) {
    		int u = R(rng);
    		int v = R(rng);
    		a.push_back({u, v});
    	}
        solve(n, a);
    }
    return 0;
}
