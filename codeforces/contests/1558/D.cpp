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
int maxM = 5e5+5;
vector<mi> fact(maxM);   
vector<mi> ifact(maxM);
void comp() {
	fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
}
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
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n, m;
    cin >> n >> m;
    vi x(m);
    vector<pii> y(m);
    for (int i = 0; i < m; i++) {
    	cin >> x[i] >> y[i].first;
    	y[i].second = -i;
    }
    set<int> used;
    using T = int;
    using F = pii;
    LazySegmentTree<T, F> seg(n, 0, F(0, 0),
	    [](T a, T b) { return a + b; },
	    [](T a, F b, int len) { 
	    	auto [b1, b2] = b;
	    	if (a == 0 && b1 == 0) {
	    		return a;
	    	}
	    	if (a == 0 && b1) {
	    		return b2 * len;
	    	} 
	    	return a + b2 * len;
	    },
	    [](F a, F b) { 
	    	if (a.first == 1) {
	    		return a;
	    	}
	    	if (b.first == 1) {
	    		return b;
	    	}
	    	return F(0, a.second + b.second);
	    }
	);
    sort(y.begin(), y.end(), greater<>());
    for (int i = 0; i < m; i++) {
    	int z = y[i].first + 1;
    	seg.update(0, -y[i].second, {0, 1});
    	seg.update(-y[i].second, -y[i].second, {1, z});
    	cout << y[i].first << " " << -y[i].second << " " << i << " " << z << endl;
    }
    set<int> s;
    for (int i = 0; i < m; i++) {
    	int z = seg.query(i, i);
    	s.insert(z);
    	cout << i << " " << z << endl;
    }
    cout << (int) ncr(2 * n - 1 - s.size(), n) << endl;
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
