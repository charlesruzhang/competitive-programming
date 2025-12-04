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
    int n;
    cin >> n;
    vl a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
    	v[i] = {b[i], i};
    }
    sort(v.begin(), v.end());
    ll prev = -1;
    vi tmp;
    set<int> s;
    s.insert(-1);
    s.insert(n);
    using T = tuple<ll, ll>;
    using F = pair<ll, ll>;
    LazySegmentTree<T, F> seg(n, {0, -1}, {1, 0},
        [](T a, T b) { 
        	auto [a1, a2] = a;
        	auto [b1, b2] = b;
        	if (a2 < 0) return b;
        	if (b2 < 0) return a;
        	assert(a2 >= 2 && b2 >= 2);
        	ll x = a1;
        	int cx = 0;
        	while (x > 1) {
        		x = (x - 1) / a2 + 1;
        		cx++;
        	}
        	ll y = b1;
        	int cy = 0;
        	while (y > 1) {
        		y = (y - 1) / b2 + 1;
        		cy++;
        	}
        	return (cx > cy) ? a : b;
        },
        [](T a, F b, int len) { 
        	auto [a1, a2] = a;
        	auto [b1, b2] = b;
        	ll z = (a1 - 1) / b1 + 1;
        	return T(z, max(a2, b2));
        },
        [](F a, F b) { 
        	auto [a1, a2] = a;
        	auto [b1, b2] = b;
        	return F(a1 * b1, max(a2, b2));
        }
    ); 
    vector<tuple<ll, ll>> vs(n);
    for (int i = 0; i < n; i++) {
    	vs[i] = {a[i], 2};
    }
    seg.build(vs);
    int ans = 0;
    ll best = 1e9;
    for (int i = 0; i < n; i++) {
    	if (v[i].first != prev) {
    		while (tmp.size()) {
    			int z = tmp.back();
    			tmp.pop_back();
    			s.insert(z);
    		}
    	}
    	int idx = v[i].second;
    	int l, r;
    	auto it = s.lower_bound(idx);
    	r = *it - 1;
    	--it;
    	l = *it + 1;
    	auto [f1, f2] = seg.query(idx, idx);
    	//cout << "? " << f1 << " " << f2 << endl;
    	ll val = f1;
    	ll edit = 1;
    	while (val > 1) {
    		val = (val - 1) / b[idx] + 1;
    		edit *= b[idx];
    		ans++;
    	}
    	seg.update(l, r, {edit, v[i].first});
    	auto [g1, g2] = seg.query(0, n - 1);
    	ll g3 = 0;
    	ll G = g1;
    	while (G > 1) {
    		G = (G - 1) / g2 + 1;
    		g3++;
    	}
    	//cout << "! " << g1 << " " << g2 << " " << g3 << " " << ans << endl;
    	best = min(best, ans + g3);
    	tmp.push_back(idx);
    	prev = v[i].first;
    	//cout << v[i].first << " " << idx << " " << ans << " " << l << " " << r << endl;
    }
    cout << best << endl;
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
