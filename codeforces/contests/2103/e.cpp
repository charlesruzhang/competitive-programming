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
        if (l > end || r < start) return {0, -1};//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    set<int> v;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	v.insert(a[i]);
    }
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
    	if (a[i] > a[i+1]) {
    		flag = 1;
    		break;
    	}
    }
    if (!flag) {
    	cout << 0 << endl;
    	return;
    }
    int idx = -1;
    int match = -1;
    flag = 0;
    for (int i = 0; i < n; i++) {
    	if (v.find(k - a[i]) != v.end()) {
    		for (int j = 0; j < n; j++) {
    			if (i != j && a[j] == k - a[i]) {
    				idx = i;
    				match = j;
    				flag = 1;
    			}
    		}
    		if (flag) break;
    	}
    }
    if (idx == -1) {
    	cout << -1 << endl;
    	return;
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
    	if (i == idx || i == match) continue;
    	if (a[i] <= k / 2) {
    		counter ++;
    	}
    }
    // want to move idx/match to counter/counter+1;
    vector<tuple<int,int,int>> ans(3 * n);
    int tota = 0;
    function <void(int, int, int)> help = [&](int x, int y, int val) {
    	if (x == y) return;
    	ans[tota++] = {x + 1, y + 1, val};
    	a[x] -= val;
    	a[y] += val;
    };
    function <void(int, int)> swap1 = [&](int x, int y) {
    	if (x == match) {
    		swap(idx, match);
    	} else if (y == idx) {
    		swap(idx, match);
    	}
    	int l = a[idx];
    	int r = a[match];
    	int val1 = a[x];
    	int val2 = a[y];
    	help(idx, match, l - val1);
    	r = a[match];
    	help(match, x, r - val2);
    };
    function <void(int, int)> swap2 = [&](int x, int y) {
    	int l = a[idx];
    	int r = a[match];
    	int val1 = a[x];
    	int val2 = a[y];
    	help(idx, match, l - val1);
    	r = a[match];
    	help(match, x, val2 - val1);
    	r = a[match];
    	help(match, y, val1 - val2);
    };
    swap1(counter, counter + 1);
    idx = counter;
    match = counter + 1;
    using T = pii;
    vector<pii> vec(n);
    for (int i = 0; i < n; i++) {
    	vec[i] = {a[i], i};
    }
    SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { return T(max(a.first, b.first), ((a.first >= b.first) ? a.second : b.second)); }, T(0, -1));
	seg.build(vec);
    for (int i = n - 1; i >= 0; i--) {
    	if (i == counter || i == counter + 1) continue;
    	auto [x, idx] = seg.query(0, min(counter-1, i));
    	auto [y, idx2] = seg.query(counter + 2, i);
    	int tar = idx2;
    	if (x >= y) {
    		tar = idx;
    	}
    	if (tar == i) continue;
    	swap2(tar, i);
    	seg.update(tar, {a[tar], tar});
    }
    help(counter, counter+1, a[counter] - k / 2);
    cout << tota << endl;
    for (int i = 0; i < tota; i++) {
    	auto [x, y, val] = ans[i];
    	cout << x << " " << y << " " << val << endl;
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
