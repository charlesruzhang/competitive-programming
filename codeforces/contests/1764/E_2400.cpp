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
        if (l > end || r < start) return pii(0, -1);//NEED TO INITIALIZE THIS!!!!!  
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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    }
    std::mt19937_64 rng(std::random_device{}());
    long long lo = 1;
    long long hi = std::numeric_limits<long long>::max();
    std::uniform_int_distribution<long long> dist(lo, hi);
    vl h(n+1);
    for (int i = 1; i <= n; i++) {
    	h[i] = dist(rng);
    }
    vl pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i + 1] = pref[i] ^ h[a[i].first];
    }
    vl perm(n + 1);
    for (int i = 1; i <= n; i++) {
    	perm[i] = perm[i-1] ^ h[i];
    }
    using T = pii;
    SegmentTree<T, function<T(T, T)>> seg(n, [](T x, T y) { return  max(x, y); }, pii(0, -1));
	seg.build(a);
	ll ans = 0;
	function <void(int, int)> find = [&] (int l, int r) {
		if (l > r) return;
		auto [maxx, idx] = seg.query(l, r);
		int s = max(l, idx - maxx + 1);
		int t = min(r - maxx + 1, idx);
		for (int i = s; i <= t; i++) {
			ans += ((pref[i + maxx] ^ pref[i]) == perm[maxx]);
		}
		find(l, idx - 1);
		find(idx + 1, r);
	};
	find(0, n-1);
	cout << ans << endl;
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
