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
    vvi children(n);
    vi p(n, -1);
    for (int i = 1; i < n; i++) {
    	int x;
    	cin >> x;
    	x--;
    	p[i] = x;
    	children[x].push_back(i);
    }
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi mark(n);
    vl tot(n);
    int flag = 1;
    vl b = a;
    vector<pii> tar(n);
    function <void(int)> dfs = [&] (int u) {
    	for (int v: children[u]) {
    		dfs(v);
    		if (a[v] == 0) {
    			if (mark[u].size() < mark[v].size()) {
    				swap(mark[u], mark[v]);
    			}
    			for (int x : mark[v]) {
    				mark[u].push_back(x);
    			}
    		}
    		tot[u] += tot[v];
    	}
    	if (children[u].size() == 0) {
    		if (a[u] == 0) {
    			mark[u].push_back(u);
    		}
    	}
    	
    	if (a[u] && mark[u].size() >= 2) {
    		if (a[u] != mark[u].size() + tot[u]) {
    			flag = 0;
	    		return;
    		} else {
    			for (int v: mark[u]) {
    				b[v] = 1;
    			}
    		}
    	} else if (a[u] && mark[u].size() == 1) {
    		tar[u] = {a[u], mark[u][0]};
    		b[u] = 0;
    		b[mark[u][0]] = 1;
    	} else if (!u && mark[u].size() && !a[u]) {
    		flag = 0;
    		return;
    	}
    	if (a[u]) {
    		tot[u] = a[u];
    	}
    };
    dfs(0);
    if (!flag) {
    	cout << "impossible" << endl;
    	return;
    }
    function <void(int)> dfs3 = [&] (int u) {
    	ll tot = 0;
    	for (int v : children[u]) {
    		dfs3(v);
    		tot += b[v];
    	}
    	if (b[u]) {
    		if (children[u].size() && tot != b[u]) {
    			flag = 0;
    			return;
    		}
    	} else {
    		if (tar[u].first) {
    			ll real = tar[u].first;
    			ll diff = real - tot;
    			if (diff < 0) {
    				flag = 0;
    				return;
    			}
    			int cur = tar[u].second;
    			while (cur != u) {
    				b[cur] += diff;
    				cur = p[cur];
    			}
    			b[u] = real;
    		} else {
    			b[u] = tot;
    		}
    	}
    };
    dfs3(0);
    if (!flag) {
    	cout << "impossible" << endl;
    	return;
    }
    for (int i = 0; i < n; i++) {
    	cout << b[i] << endl;
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
