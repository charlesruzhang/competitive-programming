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
const ll MAXX = 1e16;template <typename T, typename F>
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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int q;
    cin >> q;
    vector<array<int, 4>> qrs(2 * q);
    for (int i = 0; i < q; i++) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--; r--;
    	qrs[2 * i] = {l, i, x, 0};
    	qrs[2 * i + 1] = {r + 1, i, -x, -1};
    }
    sort(qrs.begin(), qrs.end());
    int idx = 0;
    vi valid(q + 1, 1);

    using T = int;
    using F = int;
    LazySegmentTree<T, F> seg(q + 1, 0, 1,
        [](T a, T b) { return a + b; },
        [](T a, F b, int len) { return b; },
        [](F a, F b) { return min(a, b);}
    );
    
    seg.build(valid);
    map<ll, ll> ma;
    ma[-1] = 0;
    ma[q] = 0;
    vi mark(q);
    for (int i = 0; i < n; i++) {
    	set<pair<ll, ll>> vec;
    	ll tot = 0;
    	set<int> Z;
    	vector<pair<ll, ll>> nv;
    	while (idx < 2 * q && qrs[idx][0] == i) {
    		auto [z, jj, x, forced] = qrs[idx];
    		int zz = seg.query(jj + 1, jj + 1);
    		idx++;
    		if (vec.empty() && zz) {
    			auto jt = ma.lower_bound(jj);
    			--jt;
    			vec.insert({tot + jt -> second, jj-1});
    		}
    		tot += x;
    		auto jt = ma.lower_bound(jj+1);
    		--jt;
    		ll tot2 = tot + jt -> second;
    		nv.push_back({tot2, jj});
    		if (!zz) continue;
    		if (!forced) vec.insert({tot2, jj});
    		Z.insert(jj);
    	}
    	if (vec.empty()) {
    		auto jt = ma.lower_bound(q);
    		--jt;
    		vec.insert({tot + jt -> second, q-1});
    	}
    	auto kt = ma.find(q);
    	--kt;
    	Z.insert(-1);
    	Z.insert(q);
    	auto jt = vec.begin();
    	ll tmp = (*jt).second;
    	ll minn = (*jt).first;
    	//cout << "! " << tmp << endl;
    	seg.update(0, tmp, 0);
    	for (auto [val, idx]: nv) {
    		ma[idx] = val;
    	}
    	for (auto jt = vec.begin(); jt != vec.end(); ++jt) {
    		auto [fi, se] = *jt;
    		auto it = Z.find(se);
    		int next = *(++it);
    		if (fi > minn) {
    		 	 //cout << i << " " << fi << endl;
    		 	 //cout << se << " " << next - 1 << endl;
    			seg.update(se + 1, next, 0);
    		}
    	}
    }
    int id = -2;
    for (int i = -1; i < q; i++) {
    	int zz = seg.query(i+1, i+1);
    	if (zz) {
    		id = i;
    		break;
    	}
    }
    //cout << id << endl;
    vl ans(n);
    ll cum = 0;
    idx = 0;
    for (int i = 0; i < n; i++) {
    	while (idx < 2 * q && qrs[idx][0] == i) {
    		auto [z, jj, x, forced] = qrs[idx];
    		idx++;
    		if (jj > id) continue;
    		cum += x;
    	}
    	ans[i] = a[i] + cum;
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
