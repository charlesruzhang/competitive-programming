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
    for (int i = 1; i < n; i ++) {
    	int u, v; 
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    
    vi parent(n, -1);
    vvi children(n);
    function <void(int, int) > dfs = [&] (int u, int p) {
    	parent[u] = p;
    	for (int v : e[u]) {
    		if (v != p) {
    			children[u].push_back(v);
    			dfs(v, u);
    		}
    	}
    };
    dfs(0, -1);
	int leaf = 0;
    vi vec;
    for (int i = 0; i < n; i++) {
    	if (children[i].size() == 0) {
    		leaf++;
    		vec.push_back(i);
    	}
    }
    //cout << "? " << leaf << endl;
    if (leaf >= 3) {
    	cout << 0 << endl;
    	return;
    }
    if (leaf == 1) {
    	cout << (int) powMod(2, n) << endl;
    	return;
    }
    int x = vec[0];
    int y = vec[1];
    int tot = 0;
    while (1) {
    	if (x == y) {
    		cout <<  (int) (powMod(2, n - tot) * 2)<< endl;
    		return;
    	} else if (children[x].size() > 1) {
    		cout << (int) (powMod(2, n - tot - 1) * 3 )<< endl;
    		return;
    	} else if (children[y].size() > 1) {
    		cout << (int) (powMod(2, n - tot - 1) * 3) << endl;
    		return;
    	}
    	tot+=2;
    	x = parent[x];
    	y = parent[y];
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
