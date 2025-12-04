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
    vi c(n);
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }
    if (n == 1) {
    	int x = (c[0] == 0);
    	cout << x + 1 << endl;
    	return; 
    }
    int S = n / 2;
    int T = 0;
    int U = n / 2;
    unordered_map<int, int> M;
    unordered_map<int, int> M2;
    function <void(vi&)> dfs = [&] (vi& a) {
    	if (a.size() >= S) {
    		ll tot = 0;
    		for (int i = T; i < U; i++) {
    			if (a[i - T]) tot = (tot + c[i]) % m;
    		}
    		if (a[S - 1]) M2[tot]++;
    		else M[tot]++;
    		return;
    	}
    	a.push_back(1);
    	a.push_back(0);
    	dfs(a);
    	a.pop_back();
    	a.pop_back();
    	a.push_back(0);
    	dfs(a);
    	a.pop_back();
    };
    vi b;
    dfs(b);
    S = n - S;
    T = n / 2;
    U = n;
    unordered_map<int, int> N;
    unordered_map<int, int> N2;
	function <void(vi&)> dfs2 = [&] (vi& a) {
    	if (a.size() >= S) {
    		ll tot = 0;
    		for (int i = T; i < U; i++) {
    			if (a[i - T]) tot = (tot + c[i]) % m;
    		}
    		if (a[0]) N2[tot]++;
    		else N[tot]++;
    		return;
    	}
    	a.push_back(1);
    	a.push_back(0);
    	dfs2(a);
    	a.pop_back();
    	a.pop_back();
    	a.push_back(0);
    	dfs2(a);
    	a.pop_back();
    };

    b.clear();
    dfs2(b);
    ll tot = 0;
    for (auto [x, y] : M) {
    	int z = (m - x) % m;
    	auto it = N.find(z);
    	if (it != N.end()) {
    		tot += 1ll * it -> second * y;
    	}
    	it = N2.find(z);
    	if (it != N2.end()) {
    		tot += 1ll * it -> second * y;
    	}
    } 
    for (auto [x, y] : M2) {
    	int z = (m - x) % m;
    	auto it = N.find(z);
    	if (it != N.end()) {
    		tot += 1ll * it -> second * y;
    	}
    }
    cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
