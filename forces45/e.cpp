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
template<typename T, typename F>
struct SegmentTree {
    int n;
    vector<T> tree;
    F combine;  

    SegmentTree(int size, F comb, T default_value) : n(size), combine(comb) {
        tree.assign(4 * n, default_value);
    }

    void build(const vector<T> &arr, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int idx, T value, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(idx, value, 2 * node, start, mid);
            else
                update(idx, value, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    T query(int l, int r, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (l > end || r < start) return T();//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};


void solve() {
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    using T = array<ll, 4>;
    SegmentTree<T, function<T(T, T)>> seg1(n, [](T a, T b) { 
    	auto [a1, a2, a3, a4] = a;
    	auto [b1, b2, b3, b4] = b;
    	return  T({max(max(a1, b1), a3 + b2), max(a2, a4 + b2), max(b3, a3 + b4), a4 + b4}); }, T({0, 0, 0, 0}));
	SegmentTree<T, function<T(T, T)>> seg2(n, [](T a, T b) { 
		auto [a1, a2, a3, a4] = a;
    	auto [b1, b2, b3, b4] = b;
    	return  T({max(max(a1, b1), a3 + b2), max(a2, a4 + b2), max(b3, a3 + b4), a4 + b4}); }, T({0, 0, 0, 0}));
	
	vector<T> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = {max(0ll, a[i]), max(0ll, a[i]), max(0ll, a[i]), a[i]};
	}
	seg2.build(b);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		seg2.update(i, T({0, 0, 0, 0}));
		ll x = seg1.query(0, n - 1)[0] + seg2.query(0, n - 1)[0];
		ans = max(ans, x);
		seg1.update(i, T({max(0ll, a[i]), max(0ll, a[i]), max(0ll, a[i]), a[i]}));
	}
	cout << ans << endl;
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
