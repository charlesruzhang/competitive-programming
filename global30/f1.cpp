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
int maxM = 3e4+5;
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
vi comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
}
void solve() {
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n;
    cin >> n;
    vi parent(n, -1);
    vvi children(n);
    for (int i = 1; i < n; i++) {
    	cin >> parent[i];
    	parent[i]--;
    	children[parent[i]].push_back(i);
    }
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi seq(n);
    int flag = 0;
    vvi F(n);
    vi c(n);
    function <void(int)> dfs = [&] (int u) {
    	int sz = seq[u].size();
    	for (int v : children[u]) {
    		//seq[v] = seq[u];
    		int x = a[v];
    		if (a[v] > sz) {
    			flag = 0;
    			return;
    		}
    		if (a[v] > 0) {
    			F[seq[u][a[v] - 1]].push_back(v);
    			c[v]++;
    		}
    		if (a[v] < sz - 1) {
    			F[v].push_back(seq[u][a[v] + 1]);
    			c[seq[u][a[v] + 1]]++;
    		}
    		for (int i = 0; i < a[v]; i++) {
    			seq[v].push_back(seq[u][i]);
    		}
    		seq[v].push_back(v);
    		for (int i = a[v]; i < seq[u].size(); i++) {
    			seq[v].push_back(seq[u][i]);
    		}
    		dfs(v);
    	}
    };
    dfs(0);
    if (!flag) {
    	cout << 0 << endl;
    	return;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
    	if (c[i] == 0) {
    		q.push(i);
    	}
    }
    vi ord(n);
    int timer = 0;
    while (!q.empty()) {
    	int u = q.front();
    	q.pop();
    	ord[u] = timer++;
    	for (int v : F[u]) {
    		c[v]--;
    		if (c[v] == 0) {
    			q.push(v);
    		}
    	}
    }
    assert(timer == n);
    vi parPoset(n, -1);
    vvi posetChild(n);
    for (int u = 0; u < n; u++) {
        for (int v : F[u]) {
            if (parPoset[v] == -1) {
                parPoset[v] = u;
            } else if (parPoset[v] != u) {
                // multiple different parents: then the simple product formula breaks,
                // and in valid tests this shouldn't happen.
                cout << 0 << '\n';
                return;
            }
        }
    }
    for (int v = 0; v < n; v++) {
        if (parPoset[v] != -1) {
            posetChild[parPoset[v]].push_back(v);
        }
    }

    // Now count linear extensions using the tree-structured poset.
    vector<int> sz(n, 0);
    vector<mi> dp(n);

    function<void(int)> dfsDP = [&](int u) {
        sz[u] = 1;
        mi ways = 1;
        for (int v : posetChild[u]) {
            dfsDP(v);
            ways *= dp[v];
            ways *= ifact[sz[v]]; // divide by sz[v]! (interleaving)
            sz[u] += sz[v];
        }
        ways *= fact[sz[u] - 1]; // permute all in this component except u itself's "slot"
        dp[u] = ways;
    };

    mi ans = fact[n]; // virtual root over all poset roots
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (parPoset[i] == -1) {
            dfsDP(i);
            ans *= dp[i];
            ans *= ifact[sz[i]]; // divide by size of this component, as per virtual root formula
        }
    }

    cout << ans.v << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
