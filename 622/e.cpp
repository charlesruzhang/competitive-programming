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
        if (l > end || r < start) return T(-1, 0);//NEED TO INITIALIZE THIS!!!!!  
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
	int q;
	cin >> q;

	using T = pii;
    SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { 
    	auto [x, y] = a;
    	auto [z, w] = b;
    	int f = min(x, z);
    	if (x == -1) return b;
    	if (z == -1) return a;
    	if (x == 1) {
    		return T(f, w);
    	}
    	return T(f, y);}, T(-1, 0));
	vector<SegmentTree<T, function<T(T, T)>>> vs(31, seg);
	for (int j = 0; j < 31; j++) {
		vector<pii> arr(n);
		for (int i = 0; i < n; i++) {
			arr[i].first = (a[i] & (1 << j)) ? 1 : 0;
			if (arr[i].first) arr[i].second = n + 1;
			else arr[i].second = i;
		}
		vs[j].build(arr);
	}
	while (q--) {
		int l, k;
		cin >> l >> k;
		l--;
		int ll = l;
		int r = n - 1;
		int flag = 0;
		int best = l - 1;
		for (int i = 30; i >= 0; i--) {
			int nnr = vs[i].query(ll, l - 1).second;
			if (l - 1 >= ll && nnr != n + 1) {
				l = nnr;
			}
			if (k & (1 << i)) {
				int nr = vs[i].query(l, r).second;
				r = min(r, nr - 1);
			} else {
				int nl = vs[i].query(l, r).second;
				l = max(l, min(r + 1, nl));
				best = max(best, l - 1);
			}
			if (l > r) {
				if (best >= ll) {
					cout << best + 1 << " ";
				} else {
					cout << -1 << " ";
				}
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << max(r, best) + 1 << " ";
		}
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
