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
        if (l > end || r < start) return T(INF, -1, INF, -1);//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};
struct X {
	int x, y, z, w;
	X(int xx, int yy, int zz, int ww) {
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}
	X() {

	}
};

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    }
    if (n == 1) {
    	cout << 1 << endl;
    	return;
    }
    using T = X;
	SegmentTree<T, function<T(T, T)>> seg(n, [](T aa, T bb) { 
		auto [x, y, z, w] = aa;
		auto [x2, y2, z2, w2] = bb;
		return T(min(x, x2), max(y, y2), min(z, z2), max(w, w2)); 
	}, T(INF, -1, INF, -1));
	vector<T> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = T(a[i].first, a[i].first, a[i].second, a[i].second);
	}
	seg.build(arr);
	ll ans = 1e18;
	for (int i = 0; i < n; i++) {
		auto [x, y, z, w] = seg.query(0, i - 1);
		auto [x2, y2, z2, w2] = seg.query(i + 1, n - 1);
		//cout << i << "! " << x << " " << y << " " << z << " " << w << endl;
		//cout << i << "? " << x2 << " " << y2 << " " << z2 << " " << w2 << endl;
		ll tot = 1ll * (max(y2, y) - min(x2, x) + 1) * (max(w2, w) - min(z2, z) + 1);
		
		//ll tot2 = 1ll * (max(y2, y) - min(x2, x) + 1) * (max(w2, w) - min(z2, z) + 1);
		if (tot == n - 1) {
			tot += min((max(w2, w) - min(z2, z) + 1), (max(y2, y) - min(x2, x) + 1 ));
		}
		//cout << tot << endl;
		ans = min(tot, ans);
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
