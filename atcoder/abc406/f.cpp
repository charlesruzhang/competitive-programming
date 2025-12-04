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
	vvi e(n);
	vector<pii> a(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
		a[i] = {u, v};
	}
	vi parent(n, -1);
	vi nex(n+1);
	nex[n] = n;
	vi dfn;
	function <void(int, int)> dfs = [&] (int u, int next) {
		dfn.push_back(u);
		nex[u] = next;
		vi vec;
		for (int v : e[u]) {
			if (v != parent[u]) {
				vec.push_back(v);
				parent[v] = u;
			}
		};
		vec.push_back(next);
		int idx = 1;
		for (int v : e[u]) {
			if (v != parent[u]) {
				dfs(v, vec[idx]);
				idx++;				
			}
		}
	};
	dfs(0, n);
	vi seq(n + 1);
	for (int i = 0; i < n; i++) {
		seq[dfn[i]] = i;
	}
	seq[n] = n;
	SegmentTree<int, function<int(int, int)>> seg(n, [](int a, int b) { return  a + b; }, 0);
	vi arr(n, 1);
	seg.build(arr);
	int q;
	cin >> q;
	while (q--) {
		int z;
		cin >> z;
		if (z == 1) {
			int x, w;
			cin >> x >> w;
			x--;
			seg.update(seq[x], seg.query(seq[x], seq[x]) + w);
		} else {
			int y;
			cin >> y;
			auto [u, v] = a[y];
			if (parent[u] == v) {
				swap(u, v);
			}
			int tot = seg.query(0, n - 1);
			int side = seg.query(seq[v], seq[nex[v]] - 1);
			int zzz = tot - side;
			//cout << tot << "  " << side << " " << v << " " << seq[v] << " " << nex[v] << endl;
			cout << abs(side - zzz) << endl; 
		}
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
