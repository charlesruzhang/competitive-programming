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
constexpr ll INF = 1e9;
class PersistentSegtree {
  private:
	struct Node {
		ll sum = 0;
		int l = 0, r = 0;
	};

	const int n;
	vector<Node> tree;
	int timer = 1;

	Node join(int l, int r) { return Node{min(tree[l].sum, tree[r].sum), l, r}; }

	int build(int tl, int tr, const vector<int> &arr) {
		if (tl == tr) {
			tree[timer] = {arr[tl], 0, 0};
			return timer++;
		}

		int mid = (tl + tr) / 2;
		tree[timer] = join(build(tl, mid, arr), build(mid + 1, tr, arr));

		return timer++;
	}

	int set(int v, int pos, int val, int tl, int tr) {
		if (tl == tr) {
			tree[timer] = {val, 0, 0};
			return timer++;
		}

		int mid = (tl + tr) / 2;
		if (pos <= mid) {
			tree[timer] = join(set(tree[v].l, pos, val, tl, mid), tree[v].r);
		} else {
			tree[timer] = join(tree[v].l, set(tree[v].r, pos, val, mid + 1, tr));
		}

		return timer++;
	}

	ll range_sum(int v, int ql, int qr, int tl, int tr) {
		if (qr < tl || tr < ql) { return INF; }
		if (ql <= tl && tr <= qr) { return tree[v].sum; }

		int mid = (tl + tr) / 2;
		return min(range_sum(tree[v].l, ql, qr, tl, mid),  
			range_sum(tree[v].r, ql, qr, mid + 1, tr));
	}

  public:
	PersistentSegtree(int n, int MX_NODES) : n(n), tree(MX_NODES) {}

	int build(const vector<int> &arr) { return build(0, n - 1, arr); }

	int set(int root, int pos, int val) { return set(root, pos, val, 0, n - 1); }

	ll range_sum(int root, int l, int r) { return range_sum(root, l, r, 0, n - 1); }

	int add_copy(int root) {
		tree[timer] = tree[root];
		return timer++;
	}
};

template<typename T, typename F>
struct SegmentTree {
    int n;
    vector<T> tree;
    F combine;  
    int X;
    SegmentTree(int size, F comb, T default_value) : n(size), combine(comb) {
        X = default_value;
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
        if (l > end || r < start) return X;//NEED TO INITIALIZE THIS!!!!!  
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
    stack<pii> st1;
    vi l(n), gl(n, INF);

    vi arr2(n+1, -1);
    SegmentTree<int, function<int(int, int)>> s1(n+1, [](int a, int b) { return  max(a, b); }, -1);
	s1.build(arr2);

    vector<array<int, 3>> q1;
    for (int i = 0; i < n; i++) {
    	while (!st1.empty() && st1.top().first > p[i]) {
    		st1.pop();
    	}
    	if (st1.empty()) {
    		l[i] = -1;
    	} else {
    		l[i] = st1.top().second;
    	}
    	st1.push({p[i], i});

    	if (l[i] != -1) q1.push_back({l[i], p[i], i});
    }

    sort(q1.begin(), q1.end());
	int j = 0;
	for (int i = 0; i < n; i++) {
		s1.update(p[i], i);
		while (j < q1.size() && q1[j][0] == i) {
			gl[q1[j][2]] = s1.query(q1[j][1], n);
			++j;
		}
	}
    stack<pii> stless;
    
    int q;
    cin >> q;
    vector<array<int, 3>> qrs(q);
    for (int i = 0; i < q; i ++) {
		int u, v;
		cin >> u >> v;
		u--; v--;

		qrs[i] = {v, u, i};
	}
	sort(qrs.begin(), qrs.end());

	vi arr(n, 1e9);
    SegmentTree<int, function<int(int, int)>> s2(n, [](int a, int b) { return  min(a, b); }, INF);
    s2.build(arr);
    j = 0;
    vi ans(q);
    for (int i = 0; i < n; i++) {
    	while (!stless.empty() && stless.top().first > p[i]) {
    		int x = stless.top().second;
    		s2.update(x, 1e9);
    		stless.pop();
    	}
    	stless.push({p[i], i});
    	s2.update(l[i], gl[i]);

    	while (j < q && qrs[j][0] == i) {
			auto [v, u, id] = qrs[j];
			if (s2.query(u, v) < u) {
				ans[id] = 1;
			}
			++j;
		}
    }
    for (int i = 0; i < q; i++) {
    	if (ans[i]) cout << "YES" << endl;
    	else cout << "NO" << endl;
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
