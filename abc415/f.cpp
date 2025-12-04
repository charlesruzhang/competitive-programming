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
	string s;
	cin >> s;
	vector<char> sc(n);
	for (int i = 0; i < n; i++) {
		sc[i] = s[i];
	}
	using T = array<ll, 4>;
	using F = ll;
	ll inf = 1e16;
	auto Merge = [](T a, T b) { 
        	auto [a1, a2, a3, x] = a;
        	auto [b1, b2, b3, y] = b;
        	ll c1 = max(a1, b1);
        	ll c3 = min(a3, b3);
        	ll c2;
        	ll z = max(x, y);
        	if (a1 < b1) {
        		c2 = min(a2, b2);
        	} else {
        		c2 = a2;
        	}
        	z = max(z, b1 - a3);
        	return T({c1, c2, c3, z}); 
        };
    auto Apply = [](T a, F b, int len) { 
        	auto [a1, a2, a3, x] = a;
        	return T({a1 + b, a2 + b, a3 + b, x});};
    auto Compose = [](F a, F b) { return a + b;};
    vector<LazySegmentTree<T,ll>> vseg;
	vseg.reserve(26);
    for (int i = 0; i < 26; i++) {
    	vseg.emplace_back(n+1, T({-inf, inf, inf, 0}), 0ll, Merge, Apply, Compose);
    	vl pref(n+1);
    	for (int j = 0; j < n; j++) {
    		pref[j+1] = pref[j] + ((s[j] - 'a' == i) ? 1 : -1e9);
    	}
    	vector<array<ll, 4>> mm(n+1);
    	for (int j = 0; j <= n; j++) {
    		mm[j] = {pref[j], pref[j], pref[j], 0};
    	}
    	vseg[i].build(mm);
    }
    while (q--) {
    	int xx;
    	cin >> xx;
    	if (xx == 1) {
    		int idx;
    		char c;
    		cin >> idx >> c;
    		idx--;
    		int old = sc[idx] - 'a';
    		vseg[old].update(idx + 1, n, -1000000001);
    		sc[idx] = c;
    		int now = sc[idx] - 'a';
    		vseg[now].update(idx + 1, n, 1000000001);
    	} else {
    		int l, r;
    		cin >> l >> r;
    		ll ans = 0;
    		for (int i = 0; i < 26; i++) {
    			auto [x, y, z, w] = vseg[i].query(l, r);
    			//cout << i << " " << x << " " << y << endl;
    			ans = max(w, ans);
    		}
    		cout << ans << endl;
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
