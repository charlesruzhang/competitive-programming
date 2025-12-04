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
        if (lazy[node].first.v != 1 || lazy[node].second.v != 0) {
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
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    int mx = 0;
    set<pii> v, w;
    int id = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] > mx) {
    		mx = a[i];
    		v.insert({a[i], id++});
    	}
    }
    v.insert({INF, id++});
    mx = 0;
    id = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (a[i] > mx) {
    		mx = a[i];
    		w.insert({a[i], id++});
    	}
    }
    w.insert({INF, id++});
    vector<mi> dp(n, 1);
    vector<mi> dp2(n, 1);
    int y = w.size();
    int x = v.size();
    vi e;
	for (int j = 0; j < n; j++) {
        if (a[j] == maxx) {
            e.push_back(j);
        }
	} 

    using T = mi;
    using F = pair<mi, mi>;
    LazySegmentTree<T, F> seg(v.size(), mi(0), F(1, 0),
        [](T a, T b) { return a + b; },
        [](T a, F b, int len) { return a * b.first + b.second; },
        [](F a, F b) { 
            auto [a1, a2] = a;
            auto [b1, b2] = b;
            return F(a1 * b1, a1 * b2 + a2);
        }
    );
	for (int j = 0; j < n; j++) {
		auto it = v.lower_bound({a[j], 0});
        auto [z1, z2] = *it;
        seg.update(z2, v.size() - 1, F(2, 0));
        if (z1 == a[j]) {
            if (z2) {
                dp[j] = seg.query(z2 - 1, z2 - 1);
            }
            seg.update(z2, z2, F(1, dp[j]));
        }
	}
    LazySegmentTree<T, F> seg2(w.size(), mi(0), F(1, 0),
        [](T a, T b) { return a + b; },
        [](T a, F b, int len) { return a * b.first + b.second; },
        [](F a, F b) { 
            auto [a1, a2] = a;
            auto [b1, b2] = b;
            return F(a1 * b1, a1 * b2 + a2);
        }
    );
    for (int j = n - 1; j >= 0; j--) {
        auto it = w.lower_bound({a[j], 0});
        auto [z1, z2] = *it;
        seg2.update(z2, w.size() - 1, F(2, 0));
        if (z1 == a[j]) {
            if (z2) dp2[j] = seg2.query(z2 - 1, z2 - 1);
            seg2.update(z2, z2, F(1, dp2[j]));
        }
    }
    mi ans = 0;
    mi tmp = 0;
    mi i2 = inv(2);
    for (int i = 0; i < n; i++) {
        tmp *= 2;
        if (a[i] == maxx) {
            ans += dp[i] * dp2[i];
            ans += i2 * tmp * dp2[i];
            tmp += dp[i];
        }
    }
    cout << (int) ans << endl;
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
