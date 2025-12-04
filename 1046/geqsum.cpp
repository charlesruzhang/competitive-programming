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
        if (l > end || r < start) return T(-INF, -1);//NEED TO INITIALIZE THIS!!!!!  
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
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	using T = pii;
    SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { return  max(a, b); }, T(-INF, -1));
	vector<T> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = {a[i], i};
	}
	seg.build(b);
	vl pref(n+1);
	for (int i = 0; i < n; i++) {
		pref[i+1] = pref[i] + a[i];
	}
	using U = array<ll, 3>;
	function <U(int, int)> f = [&] (int l, int r) {
		if (l > r) {
			return U({1, 0, 0});
		}
		if (l == r) return U({1, min(0, a[l]), max(a[l], 0)});
		auto [maxx, idx] = seg.query(l, r);
		auto [f1, mn1, mx1] = f(l, idx - 1);
		if (!f1) return U({0, -1, -1});

		auto [f2, mn2, mx2] = f(idx + 1, r);
		if (!f2) return U({0, -1, -1});

		ll mn = min(mn1, pref[idx+1] - pref[l] + mn2);
		ll mx = max(mx1, pref[idx+1] - pref[l] + mx2);
		if (pref[idx+1] - pref[l] + mx2 - mn1 > maxx) {
			return U({0, -1, -1});
		}
		return U({1, mn, mx});
	};
	if (f(0, n-1)[0]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
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
