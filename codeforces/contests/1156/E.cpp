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
    vector<pii> p(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i].first;
    	p[i].second = i;
    }
    using T = pii;
	SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { return  max(a, b); }, pii(0, 0));
	seg.build(p);
	ll ans = 0;
	function <set<int>(int, int)> f = [&] (int l, int r) {
		if (l > r) {
			return set<int>();
		}
		auto [x, idx] = seg.query(l, r);
		auto s1 = f(l, idx - 1);
		auto s2 = f(idx + 1, r);
		if (s1.size() > s2.size()) {
			swap(s1, s2);
		}
		auto it = s1.begin();
		while (it != s1.end()) {
			int y = *it;
			if (s2.find(x - y) != s2.end()) {
				ans++;
			}
			++it;
		}
		it = s1.begin();
		while (it != s1.end()) {
			s2.insert(*it);
			++it;
		}
		s2.insert(x);
		return s2;
	};
	f(0, n - 1);
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
