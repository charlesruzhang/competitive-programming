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

void solve() {
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    using T = int;
    using F = int;
    
    vector<int> p(n);
    vi X(n+1);
    for (int i = 0; i < n; i++) {
    	p[i] = max(a[i] - x, 0) + max(b[i] - y, 0);
    	X[min(p[i], n)]++;
    }
    vector<int> Y(n+1);
    for (int i = 0; i <= n; i++) {
    	Y[i] = (i ? Y[i-1] + X[i-1] : 0);
    }
    for (int i = 0; i <= n; i++) {
    	Y[i] -= i;
    }
    LazySegmentTree<T, F> seg(n + 1, INF, 0,
	    [](T a, T b) { 
	    	return min(a, b); },
	    [](T a, F b, int len) { 
	    	return a + b; },
	    [](F a, F b) { return a + b;}
	);
	function<int(int, int, int, int, int)> FF = [&] (int node, int lo, int hi, int ql, int qr) {
	    seg.push(node, lo, hi);              
	    if (qr < lo || hi < ql || seg.tree[node] >= 0) return n + 1;
	    if (lo == hi) return lo;                    
	    int mid = (lo + hi) / 2;
	    int left = FF(2 * node, lo, mid, ql, qr);
	    if (left <= n) return left;
	    return FF(2 * node + 1, mid+1, hi, ql, qr);
	};
	seg.build(Y);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
    	int k, na, nb;
    	cin >> k >> na >> nb;
    	k--;
    	seg.update(p[k] + 1, n, -1);
    	p[k] = max(na - x, 0) + max(nb - y, 0);
    	seg.update(p[k] + 1, n, 1);

    	// cout << "!!" << endl;
    	// for (int j = 0; j <= n; j++) {
    	// 	auto [u, v] = seg.query(j, j);
    	// 	cout << u << " " << v << " " << endl;
    	// }
    	int z = seg.query(0, n);
    	if (z < 0) {
    		int v = FF(1, 0, seg.n - 1, 0, n);
    		cout << v - 1 << endl;
    	} else {
    		cout << n << endl;
    	}
    }
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
