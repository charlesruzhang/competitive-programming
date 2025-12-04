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
    T def;
    SegmentTree(int size, F comb, T default_value) : n(size), combine(comb) {
        tree.assign(4 * n, default_value);
        def = default_value;
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
        if (l > end || r < start) return def;//NEED TO INITIALIZE THIS!!!!!  
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
    vi p(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    }
    if (n == 1) {
    	cout << 0 << endl;
    	return;
    }
    SegmentTree<int, function<int(int, int)>> seg2(n, [](int a, int b) { return  min(a, b); }, INF);
    SegmentTree<int, function<int(int, int)>> seg3(n, [](int a, int b) { return  max(a, b); }, -1);
    SegmentTree<int, function<int(int, int)>> seg(n + 1, [](int a, int b) { return  min(a, b); }, INF);
    vi dp(n + 1);
    seg2.build(p);
    seg3.build(p);
    vi idx(n+1);
    for (int i = 0; i < n; i++) {
    	idx[p[i]] = i;
    }
    seg.update(p[n-1], n - 1);
    for (int i = n - 2; i >= 0; i--) {
    	if (p[i] < p[i+1]) {
    		int x = seg.query(1, p[i] - 1);
    		x = min(x, n);
    		int y = idx[seg3.query(i, x - 1)];
    		dp[i] = dp[y] + 1;
    	} else {
    		int x = seg.query(p[i] + 1, n);
    		x = min(x, n);
    		int y = idx[seg2.query(i, x - 1)];
    		dp[i] = dp[y] + 1;
    	}
    	seg.update(p[i], i);
    }
    cout << dp[0] << endl;
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
