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
const int LOG = 20;
vi parent;
vi depth;
vvi up;

void preprocess(int n, vvi &adj, int root = 0) {
    parent.resize(n);
    depth.resize(n);
    up.assign(n, vector<int>(LOG, -1));

    function<void(int, int)> dfs = [&](int v, int p) {
        parent[v] = p;
        depth[v] = (p == -1) ? 0 : depth[p] + 1;
        up[v][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : adj[v]) {
            if (u != p) dfs(u, v);
        }
    };

    dfs(root, -1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if (diff & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}
vi primes;
vi pvec;
const int maxN = 2e5+1;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
                primes[j] = 0;
            }
        }
    }
    pvec.clear();
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
}

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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    preprocess(n, e);
    int d = 0;
    int timer = 0;
    vi seq(n), ord(n);
    function <void(int, int)> dfs = [&] (int u, int p) {
    	seq[timer] = u;
    	ord[u] = timer++;
    	for (int v : e[u]) {
    		if (v != p) {
    			dfs(v, u);
    		}
    	}
    };
    dfs(0,-1);
    mi ans = 0;
    vvi Pvec(2e5+1);
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	for (int j = 2; j * j <= x; j++) {
    		int cnt = 0;
    		while (x % j == 0) {
    			x /= j;
    			cnt++;
    		}
    		if (cnt) Pvec[j].push_back(i);
    	}
    	if (x > 1) {
    		Pvec[x].push_back(i);
    	}
    }		
    vi match(n);
    for (int i = 1; i <= 2e5; i++) {
    	if (!primes[i]) continue;
    	sort(Pvec[i].begin(), Pvec[i].end(), [&] (int u, int v) {
    		return ord[u] < ord[v];
    	});
    	vector<vector<pii>> f;
    	f.push_back({});
    	stack<int> st;
    	st.push(0);
    	int timer = 1;
    	vector<pii> V;
    	V.push_back({0, 0});
    	int sz = Pvec[i].size();
    	for (int j = 0; j < sz; j++) {
    		int x = lca(st.top(), Pvec[i][j]);
    		if (Pvec[i][j]) {
    			match[Pvec[i][j]] = timer++;
    			f.push_back({});
    			V.push_back({Pvec[i][j], 1});
    		} else {
    			V[0] = {0, 1};
    		}
    		while (depth[x] < depth[st.top()]) {
    			int y = st.top();
    			int Y = match[y];
    			st.pop();
    			if (depth[x] >= depth[st.top()]) {
    				if (depth[x] > depth[st.top()]) {
		    			st.push(x);
		    			match[x] = timer++;
		    			f.push_back({});
		    			V.push_back({x, 0});
		    		}
	    			int X = match[x];
	    			int d = abs(depth[y] - depth[x]);
	    			f[Y].push_back({X, d});
	    			f[X].push_back({Y, d});
    			} else {
    				int z = st.top();
    				int Z = match[z];
	    			int d = abs(depth[y] - depth[z]);
    				f[Z].push_back({Y, d});
    				f[Y].push_back({Z, d});
    			}
    		}
    		
    		if (Pvec[i][j]) st.push(Pvec[i][j]);
    	}
    	while (st.size() >= 2) {
    		int v = st.top();
    		st.pop();
    		int u = st.top();
    		int vv = match[v];
    		int uu = match[u];
	    	int d = abs(depth[v] - depth[u]);
    		f[vv].push_back({uu, d});
    		f[uu].push_back({vv, d});
    	}
    	int szz = f.size();
    	vector<array<mi,2>> dp1(szz); 
    	vector<array<mi,2>> dp2(szz);
    	function <void(int, int)> dfs2 = [&] (int u, int p) {
    		int w = V[u].second;
    		for (auto [v, W] : f[u]) {
    			if (v != p) {
    				dfs2(v, u);
    			}
    		}
    		if (w) {
    			dp1[u][0] = 1;
    		}
    		for (auto [v, W] : f[u]) {
    			if (v != p) {
    				auto [x, y] = dp1[v];
    				auto [x2, y2] = dp2[v];
    				y += W * x;
    				y2 += W * x2;

    				auto [X, Y] = dp1[u];
    				auto [X2, Y2] = dp2[u];
    				mi Z2 = X * x + x2;
    				mi W2 = X * y + Y * x + y2;

    				ans += X * y2 + Y * x2;
    				ans += X2 * y + Y2 * x;
    				dp1[u][0] += x;
    				dp1[u][1] += y;
    				dp2[u][0] += Z2;
    				dp2[u][1] += W2;
    			}
    		}
    	};
    	dfs2(0, -1);
    	for (auto [v, w] : V) {
    		match[v] = 0;
    	}
    }
    cout << (int) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
