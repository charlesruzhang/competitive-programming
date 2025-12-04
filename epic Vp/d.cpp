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
void solve() {
    int n, q;
    cin >> n >> q;
    vi par(n);
    par[0] = n;
    vvi children(n);
    for (int i = 1; i < n; i++) {
    	int x;
    	cin >> x;
    	x--;
    	par[i] = x;
    	children[x].push_back(i);
    }
    vi p(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    	p[i]--;
    }
    vi vec(n+1);
    for (int i = 0; i < n; i++) {
    	vec[p[i]] = i;
    }
    vec[n] = -1;
    vi sz(n);
    function<void(int)> dfs = [&] (int u) {
    	int tot = 1;
    	for (int v : children[u]) {
    		dfs(v);
    		tot += sz[v];
    	}
    	sz[u] = tot;
    };

    dfs(0);
    vector<set<pii>> vs(n+1);
    for (int i = 0; i < n; i++) {
    	vs[par[i]].insert({vec[i], i});
    }

    vi Z(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	auto it = vs[i].begin();
    	int prev = 1;
    	int pidx = i;
    	while (it != vs[i].end()) {
    		auto [x, y] = *it;
    		if (vec[pidx] + prev != x) {
    			Z[y] = 1;
    			cnt++;
    		}
    		prev = sz[y];
    		pidx = y;
    		++it;
    	}
    }
    for (int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	int a = p[x];
    	int b = p[y];

    	auto g = [&] (int a) {
			auto it = vs[par[a]].find({vec[a], a});
			int prev, pidx;
			if (it == vs[par[a]].begin()) {
				prev = 1;
				pidx = par[a];
			} else {
				--it;
				auto [x, y] = *it;
				prev = sz[y];
				pidx = y;
				++it;
			}

			++it;

			if (it != vs[par[a]].end()) {
				auto [x, y] = *it;
				int pp = Z[y];
				if (vec[pidx] + prev != x) {
	    			Z[y] = 1;
	    		} else {
	    			Z[y] = 0;
	    		}
	    		cnt += Z[y] - pp;
			}

			vs[par[a]].erase({vec[a], a});

    	};

    	g(a);
		g(b);
		swap(p[x], p[y]);
		swap(vec[a], vec[b]);

		auto f = [&](int a) {
			vs[par[a]].insert({vec[a], a});
			auto it = vs[par[a]].find({vec[a], a});
			int prev, pidx;
			if (it == vs[par[a]].begin()) {
				prev = 1;
				pidx = par[a];
			} else {
				--it;
				auto [x, y] = *it;
				prev = sz[y];
				pidx = y;
				++it;
			}
			int pp = Z[a];
			if (vec[pidx] + prev != vec[a]) {
				Z[a] = 1;
			} else {
				Z[a] = 0;
			}
			cnt += Z[a] - pp;
			++it;
			if (it != vs[par[a]].end()) {
				auto [x, y] = *it;
				int pp = Z[y];
				if (vec[a] + sz[a] != x) {
	    			Z[y] = 1;
	    		} else {
	    			Z[y] = 0;
	    		}
	    		cnt += Z[y] - pp;
			}

			auto it2 = vs[a].begin();
			if (it2 != vs[a].end()) {
				auto [x, y] = *it2;
				int pp = Z[y];
				if (vec[a] + 1 != x) {
					Z[y] = 1;
				} else {
					Z[y] = 0;
				}
				cnt += Z[y] - pp;
			}
		};

		f(a);
		f(b);
		if (cnt) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
    }
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
