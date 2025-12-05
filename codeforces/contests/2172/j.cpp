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
template <typename T, typename F>
struct LazySegmentTree {
    int n;
    std::vector<T> tree;
    std::vector<F> lazy;
    T identity;
    F lazy_identity;
    std::function<T(T, T)> merge;
    std::function<T(T, F, int)> apply;
    std::function<F(F, F)> compose;
 
    LazySegmentTree(int size, T id, F lazy_id,
                    std::function<T(T, T)> merge_fn,
                    std::function<T(T, F, int)> apply_fn,
                    std::function<F(F, F)> compose_fn)
        : identity(id), lazy_identity(lazy_id), merge(merge_fn),
          apply(apply_fn), compose(compose_fn) {
        n = 1;
        while (n < size) n *= 2;
        tree.assign(2 * n, identity);
        lazy.assign(2 * n, lazy_identity);
    }
 
    void push(int node, int node_lo, int node_hi) {
        if (lazy[node] != lazy_identity) {
            tree[node] = apply(tree[node], lazy[node], node_hi - node_lo + 1);
            if (node_lo != node_hi) {
                lazy[2 * node] = compose(lazy[2 * node], lazy[node]);
                lazy[2 * node + 1] = compose(lazy[2 * node + 1], lazy[node]);
            }
            lazy[node] = lazy_identity;
        }
    }
 
    void update(int lo, int hi, F val, int node, int node_lo, int node_hi) {
        push(node, node_lo, node_hi);
        if (hi < node_lo || node_hi < lo) return;
        if (lo <= node_lo && node_hi <= hi) {
            lazy[node] = compose(lazy[node], val);
            push(node, node_lo, node_hi);
            return;
        }
        int mid = (node_lo + node_hi) / 2;
        update(lo, hi, val, 2 * node, node_lo, mid);
        update(lo, hi, val, 2 * node + 1, mid + 1, node_hi);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
 
    T query(int lo, int hi, int node, int node_lo, int node_hi) {
        push(node, node_lo, node_hi);
        if (hi < node_lo || node_hi < lo) return identity;
        if (lo <= node_lo && node_hi <= hi) return tree[node];
        int mid = (node_lo + node_hi) / 2;
        return merge(query(lo, hi, 2 * node, node_lo, mid),
                     query(lo, hi, 2 * node + 1, mid + 1, node_hi));
    }
 
    void update(int lo, int hi, F val) {
        update(lo, hi, val, 1, 0, n - 1);
    }
 
    T query(int lo, int hi) {
        return query(lo, hi, 1, 0, n - 1);
    }
 
    void build(const std::vector<T>& arr, int node, int node_lo, int node_hi) {
        if (node_lo == node_hi) {
            if (node_lo < arr.size()) tree[node] = arr[node_lo];
            return;
        }
        int mid = (node_lo + node_hi) / 2;
        build(arr, 2 * node, node_lo, mid);
        build(arr, 2 * node + 1, mid + 1, node_hi);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
 
    void build(const std::vector<T>& arr) {
        build(arr, 1, 0, n - 1);
    }
};

class DSU {
public:
    vector<int> parent, size, l, r, cnt;
    DSU(int n) {
        parent.resize(n);
        l.resize(n);
        r.resize(n);
        size.resize(n, 1);
        cnt.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            l[i] = r[i] = i; 
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
            l[a] = min(l[a], l[b]);
            r[a] = max(r[a], r[b]);
            cnt[a] += cnt[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    vvi W(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	W[a[i]].push_back(i);
    }
    vvi V(n+1);
    for (int i = 0; i < n - 1; i++) {
    	cin >> b[i];
    	V[b[i]].push_back(i);
    }
    DSU D(n);
    using T = int;
    using F = int;
    LazySegmentTree<T, F> seg(n, 0, 0,
	    [](T a, T b) { return a + b; },
	    [](T a, F b, int len) { return a + b * len; },
	    [](F a, F b) { return a + b;}
	);
	vi v(n, n);
	seg.build(v);
	for (int i = 0; i <= n; i++) {
		for (int u : V[i]) {
			int x = D.find(u);
			int y = D.find(u + 1);
			int c1 = D.cnt[x];
			int rx = D.r[x];
			seg.update(rx - c1 + 1, rx, -(n - i));
			int c2 = D.cnt[y];
			int ry = D.r[y];
			seg.update(ry - c2 + 1, ry, -(n - i));
			D.unite(x, y);

			int c = D.cnt[D.find(x)];
			int r = D.r[D.find(x)];
			seg.update(r - c + 1, r, (n - i));
		}

		for (int v : W[i]) {
			int x = D.find(v);
			D.cnt[x]--;
			int c = D.cnt[x];
			int r = D.r[x];
			seg.update(r - c, r - c, - (n - i));
		}
	}
	for (int i = 0; i < n; i++) {
		cout << seg.query(i, i) << " ";
	}
	cout << endl;
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
