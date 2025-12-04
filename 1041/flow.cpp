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
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
vi primes;
vi pvec;
const int maxN = 2e5;
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
void solve() {
    int n, k;
    cin >> n >> k;
    sieve();
    vi p(n), c(n), lv(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i] >> c[i] >> lv[i];
    }
    int l = 1;
    int r = n;
    
    auto check = [&] (int m) {
    	Dinic D(n + 2, n, n + 1);
    	int tot = 0;
	    int maxx = 0;
	    int idx = -1;
    	for (int i = 0; i < n; i++) {
	    	if (c[i] == 1 && lv[i] <= m) {
	    		if (maxx < p[i]) {
	    			maxx = p[i];
	    			idx = i;
	    		}
	    	}
	    }
    	for (int i = 0; i < n; i++) {
    		if (lv[i] > m) continue;
    		if (c[i] == 1 && i != idx) continue;
    		tot += p[i];
    		if (c[i] % 2) D.add_edge(n, i, p[i]);
    		else D.add_edge(i, n + 1, p[i]);
    	}
    	for (int i = 0; i < n; i++) {
    		if (lv[i] > m) continue;
    		for (int j = i + 1; j < n; j++) {
    			if (lv[j] > m) continue;
    			if (primes[c[i] + c[j]]) {
    				int x = i;
    				int y = j;
    				if (c[x] % 2 == 0) {
    					swap(x, y);
    				}
    				D.add_edge(x, y, D.flow_inf);
    			}
    		}
    	}
    	ll ans = D.flow();
    	return ans <= tot - k;
    };
    if (!check(r)) {
    	cout << -1 << endl;
    	return;
    }
    while (l < r) {
    	int m = (l + r) / 2;
    	if (check(m)) {
    		r = m;
    	} else {
    		l = m + 1;
    	}
    }
    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
