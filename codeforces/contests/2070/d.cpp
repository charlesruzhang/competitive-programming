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

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
void solve() {
    int n; 
    cin >> n;
    vi p(n);
    vvi child(n);
    for (int i = 1; i < n; i++) {
    	int x;
    	cin >> x;
    	p[i] = x - 1;
    	child[x-1].push_back(i);
    }
    int cur = 0;
    vi d(n, 0);
    function<void(int)> dfs = [&] (int u) {
    	d[u] = cur;
    	for (int v : child[u]) {
    		cur++;
    		dfs(v);
    		cur--;
    	}
    };
    dfs(0);
    vvi dd(n);
    for (int i = 0; i < n; i++) {
    	dd[d[i]].push_back(i);
    }
    vector<mi> ans(n, mi(0));

    mi summ(0);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
    	mi nsumm(0);
    	for (int v : dd[i]) {
    		if (i == 1) {
    			ans[v] = mi(1);
    			nsumm += 1; 
    			continue;
    		}
    		ans[v] = summ - ans[p[v]];
    		nsumm += ans[v];
    	}
    	summ = nsumm;
    }
    mi rs(0);
    for (int i = 0; i < n; i++) {
    	rs += ans[i];
    }
    cout << (int) rs << endl;
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
