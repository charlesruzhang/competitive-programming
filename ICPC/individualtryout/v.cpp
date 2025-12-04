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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    using T = ll;
    using F = ll;
    LazySegmentTree<T, F> seg(n, 0ll, 0ll,
	    [](T a, T b) { return a + b; },
	    [](T a, F b, int len) { return a + b * len; },
	    [](F a, F b) { return a + b;}
	);
	stack<int> st;
	vi L(n), R(n);
    for (int i = 0; i < n; i++) {
    	while (st.size() && a[st.top()] < a[i]) {
    		st.pop();
    	}
    	L[i] = (st.size() ? st.top() + 1 : 0);
    	st.push(i);
    }
    stack<int> st2;
    for (int i = n - 1; i >= 0; i--) {
    	while (st2.size() && a[st2.top()] < a[i]) {
    		st2.pop();
    	}
    	R[i] = (st2.size() ? st2.top() - 1 : n - 1);
    	st2.push(i);
    }
    vector<vector<array<int, 2>>> va(n);
    vector<vector<array<int, 2>>> vb(n);
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	va[l].push_back({r, i});
    	vb[r].push_back({l, i});
    }
    vector<ll> ans(q);
    for (int i = 0; i < n; i++) {
    	for (auto [r, idx]: va[i]) {
    		ans[idx] -= seg.query(i, r);
    	}
    	seg.update(L[i], R[i], 1);
    	for (auto [l, idx]: vb[i]) {
    		ans[idx] += seg.query(l, i);
    		ans[idx] -= i - l + 1;
    	}
    }
 	for (ll x : ans) {
 		cout << x << endl;
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
