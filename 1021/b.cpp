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
const ll MOD = 1e9+7;
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
    int n, m, k;
    cin >> n >> m >> k;
    vi x(k+1), y(k+1);
    for (int i = 0; i <= k; i++) {
    	cin >> x[i] >> y[i];
    	x[i]--; y[i]--;
    }
    vvi e(n * m);
    for (int i = 0; i < k; i++) {
    	if (abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]) != 2) {
    		cout << 0 << endl;
    		return;
    	}
    	if (x[i] == x[i+1] || y[i] == y[i+1]) {
    		int xmed = (x[i] + x[i+1]) / 2;
    		int ymed = (y[i] + y[i+1]) / 2;
    		e[xmed * m + ymed].push_back(xmed * m + ymed);
    	} else {
    		e[x[i] * m + y[i+1]].push_back(x[i+1] * m + y[i]);
    		e[x[i+1] * m + y[i]].push_back(x[i] * m + y[i+1]);
    	}
    }
   	vi visited(n * m);
   	vi res(n * m);
   	mi ans = 1;
   	int tot = 0;
   	int tote = 0;
   	int f = 0;
    function <void(int)> dfs = [&] (int u) {
    	visited[u] = 1;
    	for (int v : e[u]) {
    		if (u == v) {
    			tote++;
    			f = 1;
    		}
    		tote++;
    		if (!visited[v]) {
    			tot++;
    			dfs(v);
    		}
    	}
    	res[u] = max(res[u], tot);
    };
   	for (int i = 0; i < n * m; i++) {
   		tot = 1;
   		tote = 0;
   		f = 0;
   		if (!visited[i] && !e[i].empty()) {
   			dfs(i);
   			tote /= 2;
   			if (tote > tot) {
   				cout << 0 << endl;
   				return;
   			} else if (tote == tot) {
   				if (f) continue;
   				else ans *= 2;
   			} else {
   				ans *= tot;
   			}
   		}
   	} 
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
