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
    vvi a(n);
    for (int i = 0; i < n; i++) {
    	int sz;
    	cin >> sz;
    	for (int j = 0; j < sz; j++) {
    		int x;
    		cin >> x;
    		a[i].push_back(x);
    	}
    	sort(a[i].begin(), a[i].end());
    }
    vvi V(n);
    for (int i = 0; i < m; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	V[l].push_back(r);
    }
    multiset<int> d;
    for (int i = 0; i < n; i++) {
    	for (int r : V[i]) {
    		d.insert(r);
    	}
    	int x = a[i].size();
    	if (d.size() < x) {
    		cout << "NO" << endl;
    		return;
    	}
    	for (int j = 0; j < x; j++) {
    		if (a[i][j] <= j) {
    			cout << "NO" << endl;
    			return;
    		}
    	}
    	for (int j = 0; j < x; j++) {
	    	auto it = d.end();
	    	--it;
    		d.erase(it);
    	}
    	while (d.size() && *d.begin() == i) {
    		d.erase(d.begin());
    	}
    }
    // d.clear();
    // for (int i = 0; i < n; i++) {
	// 	for (int r : V[i]) {
    // 		d.insert(r);
    // 	}
    // 	int x = a[i].size();
    // 	assert(d.size() >= x);
    	
    // 	for (int j = 0; j < x; j++) {
    // 		d.erase(d.begin());
    // 	}
    // 	while (d.size() && *d.begin() == i) {
    // 		d.erase(d.begin());
    // 	}
    // }
    cout << "YES" << endl;
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
