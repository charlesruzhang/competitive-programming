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
	int n, q;
	cin >> n >> q;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	using T = array<int, 4>;
	SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { 
		auto [a1, a2, a3, a4] = a;
		auto [b1, b2, b3, b4] = b;
		vector<pii> v;
		int done1 = 1, done2 = 1;
		if (b2 != -1) {
			if (b1 == a1) {
				a2 += b2;
			} else if (b1 == a3) {
				a4 += b2;
			} else if (a2 == 0) {
				a1 = b1;
				a2 = b2;
			} else if (a4 == 0) {
				a3 = b1;
				a4 = b2;
			} else {
				int minn = min(b2, min(a2, a4));
				a2 -= minn;
				a4 -= minn;
				b2 -= minn;
				if (b2 > 0) {
					if (a2 == 0) {
						a2 = b2;
						a1 = b1;
					} else if (a4 == 0) {
						a4 = b2;
						a3 = b1;
					}
				}
			}
		}
		if (b4 != -1) {
			if (b3 == a1) {
				a2 += b4;
			} else if (b3 == a3) {
				a4 += b4;
			} else if (a2 == 0) {
				a1 = b3;
				a2 = b4;
			} else if (a4 == 0) {
				a3 = b3;
				a4 = b4;
			} else {
				int minn = min(b4, min(a2, a4));
				a2 -= minn;
				a4 -= minn;
				b4 -= minn;
				if (b4 > 0) {
					if (a2 == 0) {
						a2 = b4;
						a1 = b3;
					} else if (a4 == 0) {
						a4 = b4;
						a3 = b3;
					}
				}
			}
		}
		return T({a1, a2, a3, a4}); }, T({-1, 0, -1, 0}));
	vector<T> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = {a[i], 1, -1, 0};
	}
	map<int, set<pii>> vm;
	for (int i = 0; i < n; i++) {
		vm[a[i]].insert({i, vm[a[i]].size() + 1});
	}
	seg.build(arr);
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		auto [x, y, z, w] = seg.query(u, v);
		vi ans;
		if (y) {
			auto& ref = vm[x];
			int first = 0;
			int second = 0;
			auto it = ref.lower_bound({v + 1, -1});
			if (it != ref.begin()) {
				--it;
				first = it -> second;
			}
			auto it2 = ref.lower_bound({u, -1});
			if (it2 != ref.begin()) {
				--it2;
				second = it2 -> second;
			}
			int tot = first - second;
			if (tot >= (v - u + 1) / 3 + 1) {
				ans.push_back(x);
			}
		}
		if (w) {
			auto& ref = vm[z];
			int first = 0;
			int second = 0;
			auto it = ref.lower_bound({v + 1, -1});
			if (it != ref.begin()) {
				--it;
				first = it -> second;
			}
			auto it2 = ref.lower_bound({u, -1});
			if (it2 != ref.begin()) {
				--it2;
				second = it2 -> second;
			}
			int tot = first - second;
			if (tot >= (v - u + 1) / 3 + 1) {
				ans.push_back(z);
			}
		}
		sort(ans.begin(), ans.end());
		if (ans.size() == 0) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
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
