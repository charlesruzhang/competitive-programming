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
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u ,v; 
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    int x = n - 1;
    vector<int> f;
    for (int i = 1; i * i <= x; i++) {
    	if (x % i == 0) {
    		f.push_back(i);
    		if (i * i != x) f.push_back(x / i);
    	}
    }
    sort(f.begin(), f.end(), greater<>());
    vector<mi> ans(n+1);
    ans[1] = powMod(2, n - 1);
    vi done(n+1);
    done[1] = 1;
    mi xx = 0;
    vi val(n);
    for (auto d: f) {
    	if (done[d]) continue;
    	int flag = 1;
    	function <void(int, int)> dfs = [&] (int u, int p) {
    		val[u] = 0;
	    	for (int v : e[u]) {
	    		if (v != p) {
	    			dfs(v, u);
	    			val[u] += val[v];
	    		}
	    	}
	    	if (val[u] % d == 0) {
	    		val[u] = 1;
	    	} else if (p != -1 && val[u] % d == d - 1) {
	    		val[u] = 0;
	    	} else {
	    		flag = 0;
	    		return;
	    	}
	    };
	    dfs(0, -1);
	    if (flag) {
	    	ans[d] = 1;
	    	xx += 1;
	    	for (auto e : f) {
	    		if (d != e && d % e == 0) {
	    			done[e] = 1;
	    		}
	    	}
	    }
    }
    ans[1] -= xx;
    for (int i = 1; i <= n; i++) {
    	cout << (int) ans[i] << " ";
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
