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
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
     void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
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

void solve() {
    mt19937 rng(31415929);
    int n, k, s, q;
    cin >> n >> k >> s >> q;
    int E = sqrt(n);
    vvi e(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    preprocess(n, e);
    vector<set<int>> vs(n);
    vector<pii> c(k+1);
    vvi cc(k+1);
    for (int i = 0; i < s; i++) {
        int v, x;
        cin >> v >> x;
        v--;
        vs[v].insert(x);
        c[x].first++;
        cc[x].push_back(v);
    }
    for (int i = 0; i <= k; i++) {
        c[i].second = i;
    }
    sort(c.begin(), c.end(), greater<>());
    int B = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i].first >= 1) {
            B++;
        } else {
            break;
        }
    }
    B = min(B, 550);
    vi ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = vs[i].size();
    }
    vector<DSU> D(B, n);
    vi mark(n);
    for (int i = 0; i < B; i++) {
        int C = c[i].second;
        for (int u : cc[C]) {
            mark[u] = 1;
        }
        function <void(int, int)> dfs = [&] (int u, int p) {
            if (mark[u]) vs[u].erase(C);
            if (p != -1 && mark[u] && mark[p]) {
                D[i].unite(u, p);
            }
            for (int v : e[u]) {
                if (v != p) {
                    dfs(v, u);
                }
            }
        };
        dfs(0, -1);
        for (int u : cc[C]) {
            mark[u] = 0;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int x = lca(l, r);
        int dist = depth[l] + depth[r] - 2 * depth[x] + 1;
        if (dist > E) {
            int A = 0;
            for (int j = 0; j < B; j++) {
                if (D[j].find(l) == D[j].find(r)) {
                    A++;
                }
            }
            cout << A << " ";
        } else {
            if (l == r) {
                cout << ans[l] << " ";
                continue;
            }
            int A = 0;
            for (int j = 0; j < B; j++) {
                if (D[j].find(l) == D[j].find(r)) {
                    A++;
                }
            }
            int cur = l;
            vi w;
            w.push_back(x);
            while (cur != x) {
                w.push_back(cur);
                cur = parent[cur];
            }
            cur = r;
            while (cur != x) {
                w.push_back(cur);
                cur = parent[cur];
            }
            shuffle(w.begin(), w.end(), rng);
            set<int> s = vs[w[0]];
            for (int z = 1; z < w.size(); z++) {
                if (vs[w[z]].size() >= s.size()) {
                    auto it2 = s.begin();
                    while (it2 != s.end()) {
                        auto it = vs[w[z]].find(*it2);
                        ++it2;
                        if (it == vs[w[z]].end()) {
                            s.erase(prev(it2));
                        }
                    }
                } else {
                    auto it2 = vs[w[z]].begin();
                    set<int> t;
                    while (it2 != vs[w[z]].end()) {
                        auto it = s.find(*it2);
                        if (it != s.end()) {
                            t.insert(*it2);
                        }
                        ++it2;
                    }
                    swap(s, t);
                }
            }
            A += s.size();
            cout << A << " ";
        }
    }
    cout << '\n';
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
