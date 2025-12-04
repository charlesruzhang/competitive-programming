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
    vector<mi> p(n), q(n);
    for (int i = 0; i < n; i++) {
    	int pr, qr;
    	cin >> pr >> qr;
    	p[i] = pr * inv(qr);
    	q[i] = 1 - p[i];
    }
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    mi ans = 0;
    vector<mi> all(n, 1);
    vector<mi> inver(n, 0);
    for (int i = 0; i < n; i++)  {
    	for (int v : e[i]) {
    		all[i] *= p[v];
    	}
    	inver[i] = inv(p[i]);
    }
    vector<mi> tot(n, 0);
    vector<mi> tot2(n, 0);
    for (int i = 0; i < n; i++) {
    	for (int v : e[i]) {
    		tot[i] += all[i] * inver[v] * q[v];
    	}
    }
    int root = 0;
    mi prev = tot[root] * q[root];
    vi parent(n, -1);
    function <void(int)> dfs = [&](int u) {
    	int x = parent[u];
    	mi z = (parent[u] == -1) ? 0 : tot[x] * q[x]; 
    	mi ppv = prev - tot[u] * q[u] - z;
    	mi p1 = (parent[u] == -1) ? 0 : all[x] * inver[u] * q[x];
    	mi p2 = (parent[u] == -1) ? 0 : (tot[x] - all[x] * inver[u] * q[u]) * q[x];
    	for (int v : e[u]) {
    		if (v != parent[u]) {
    			parent[v] = u;
    			mi avu = all[v] * inver[u];
    			//cout << u << " " << v << " " << (int) (all[u] * all[v] * inver[u] * inver[v]* (1 - p[u]) * (1 - p[v])) << endl;
    			ans += avu * all[u] * inver[v] * q[u] * q[v];
    			ans += ppv * tot[v] * q[v];
    			ans += q[u] * p1 * (avu * q[v]);
    			ans += inver[u] * p2 * (tot[v] - avu * q[u]) * q[v];
    			p1 += avu * q[v];
    			p2 += (tot[v] - avu * q[u]) * q[v]; 
    			prev += tot[v] * q[v];
    		}
    	}
    	//cout << (int) ans << " " << u << endl;
    	for (int v : e[u]) {
    		if (v != parent[u]) {
    			dfs(v);
    		}
    	}
    };
    dfs(root);
    cout << (int) ans << endl;
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
