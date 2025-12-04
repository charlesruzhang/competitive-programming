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
    vvi e(n), f(n);
    vector<pii> o(n);
    for (int i = 0; i < n; i++) {
    	o[i].second = i;
    }
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	o[u].first++;
    	o[v].first--;
    	e[u].push_back(v);
    	f[v].push_back(u);
    }
    set<pii, greater<>> s;
    for (int i = 0; i < n; i++) {
    	s.insert(o[i]);
    }
    vi ans;
    vi done(n);
    for (int i = 0; i < n; i++) {
    	auto it = s.begin();
    	auto [w, u] = *it;
    	for (int v : e[u]) {
    		if (done[v]) continue;
    		s.erase(s.find(o[v]));
    		o[v].first++;
    		s.insert(o[v]);
    	}
    	for (int v : f[u]) {
    		if (done[v]) continue;
    		s.erase(s.find(o[v]));
    		o[v].first--;
    		s.insert(o[v]);
    	}
    	it++;
    	s.erase(prev(it));
    	done[u] = 1;
    	ans.push_back(u+1);
    }
    for (int x : ans) {
    	cout << x << " ";
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
