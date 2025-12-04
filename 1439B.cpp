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
    vvi e(n);
    vi in(n, 1);
    set<pii> s;
    vi deg(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    	deg[u]++; deg[v]++;
    }
    for (int i = 0; i < n; i++) {
    	sort(e[i].begin(), e[i].end());
    }
    for (int i = 0; i < n; i++) {
    	s.insert({deg[i], i});
    }
    int flag = 1;
    if (1ll * k * (k - 1) / 2 > m) {
    	flag = 0;
    }
    vi red(n);
    while (s.size() && s.begin()->first < k) {
    	auto it = s.begin();
    	auto [x, u] = *it;
    	in[u] = 0;

    	if (x == k - 1 && flag) {
    		vi V;
    		int flag2 = 1;
    		for (int v : e[u]) {
    			if (in[v]) {
    				V.push_back(v);
    			}
    		}
    		if (k >= 100) {
    			for (int v: V) {
	    			for (int vv: V) {
	    				if (vv != v) red[vv] = 1;
	    			}
	    			for (int vv: e[v]) {
	    				if (red[vv] == 1) {
	    					red[vv] = 0;
	    				}
	    			}
	    			for (int vv: V) {
	    				if (red[vv] == 1) {
	    					flag2 = 0;
	    					red[vv] = 0;
	    				}
	    			}
	     		}
    		} else {
    			for (int v : V) {
    				for (int vv: V) {
    					if (v == vv) continue;
    					auto it = lower_bound(e[vv].begin(), e[vv].end(), v);
    					if (*it != v) {
    						flag2 = 0;
    						break;
    					} 
    				}
    				if (!flag2) break;
    			}
    		}
    		
     		if (flag2) {
     			cout << 2 << endl;
     			for (int v: V) {
     				cout << v + 1 << " ";
     			}
     			cout << u + 1 << endl;
     			return;
     		}
    	}

    	for (int v: e[u]) {
    		if (in[v]) {
    			s.erase(s.find({deg[v]--, v}));
    			s.insert({deg[v], v});
    		}
    	}
    	s.erase(it);
    }
    if (s.size() && s.begin()->first >= k) {
    	cout << 1 << " " << s.size() << endl;
    	for (auto [x, u]: s) {
    		cout << u + 1 << " ";
    	}
    	cout << endl;
    	return;
    }
    cout << -1 << endl;
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
