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
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	for (int j = 2; j * j <= x; j++) {
    		if (x % j == 0) {
    			s.insert(j);
    		}
    		while (x % j == 0) {
    			x /= j;
    		}
    	}
    	if (x > 1) {
    		s.insert(x);
    	}
    }
    vector<pii> p;
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	p.push_back({x, y});
    }
    ll ans = 0;
    auto it = s.begin();
    while (it != s.end()) {
    	Dinic D(n + 2, n, n + 1);
    	int u = *it;
    	vi cnt(n);
    	for (int i = 0; i < n; i++) {
    		int x = a[i];
    		while (x % u == 0) {
    			x /= u;
    			cnt[i]++;
    		}
    		if (cnt[i]) {
    			if (i % 2) {
    				D.add_edge(n, i, cnt[i]);
    			} else {
    				D.add_edge(i, n + 1, cnt[i]);
    			}
    		}
    	}
    	for (auto [x, y] : p) {
    		if (x % 2 == 0) swap(x, y);
    		if (cnt[x] && cnt[y]) D.add_edge(x, y, D.flow_inf);
    	}
    	ans += D.flow();
    	++it;
    }
    cout << ans << endl;
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
