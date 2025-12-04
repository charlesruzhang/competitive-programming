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
struct Node {
	ll sum = 0;
	int l = 0, r = 0;
	int val = -1;
};
struct PersistentSegtree {

	const int n;
	vector<Node> tree;
	int timer = 1;

	Node join(int l, int r) { return Node{tree[l].sum + tree[r].sum, l, r, tree[l].val}; }

	int build(int tl, int tr, const vector<int> &arr) {
		if (tl == tr) {
			tree[timer] = {0, 0, 0, arr[tl]};
			return timer++;
		}

		int mid = (tl + tr) / 2;
		tree[timer] = join(build(tl, mid, arr), build(mid + 1, tr, arr));

		return timer++;
	}

	int set(int v, int pos, int val, int p, int tl, int tr) {
		if (tl == tr) {
			tree[timer] = {val, 0, 0, p};
			return timer++;
		}

		int mid = (tl + tr) / 2;
		if (pos <= mid) {
			tree[timer] = join(set(tree[v].l, pos, val, p, tl, mid), tree[v].r);
		} else {
			tree[timer] = join(tree[v].l, set(tree[v].r, pos, val, p, mid + 1, tr));
		}

		return timer++;
	}

	ll range_sum(int v, int ql, int qr, int tl, int tr) {
		if (qr < tl || tr < ql) { return 0ll; }
		if (ql <= tl && tr <= qr) { return tree[v].sum; }

		int mid = (tl + tr) / 2;
		return range_sum(tree[v].l, ql, qr, tl, mid) +
		       range_sum(tree[v].r, ql, qr, mid + 1, tr);
	}

	PersistentSegtree(int n, int MX_NODES) : n(n), tree(MX_NODES) {}

	int build(const vector<int> &arr) { return build(0, n - 1, arr); }

	int set(int root, int pos, int val, int p) { return set(root, pos, val, p, 0, n - 1); }

	ll range_sum(int root, int l, int r) { return range_sum(root, l, r, 0, n - 1); }

	int add_copy(int root) {
		tree[timer] = tree[root];
		return timer++;
	}
};
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n+1);
    set<int> S;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	S.insert(a[i]);	
    }
    int counter = 1;
    map<int, int> ma2;
    vi c(n+1);
    for (int x : S) {
    	c[counter] = x;
    	ma2[x] = counter++;
    }
    vi b(n);
    vvi C(n+1);
    for (int i = 0; i < n; i++) {
    	b[i] = ma2[a[i]];
    	C[b[i]].push_back(i);
    }
    vi tmp(n+1);
    PersistentSegtree seg(n + 1, 40 * n);
    vi roots(n+1);
    roots[0] = seg.build(tmp);
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cnt[b[i]]++;
    	roots[i+1] = seg.set(roots[i], b[i], cnt[b[i]], b[i]);
    }
    function <int(Node, Node, int)> getK = [&] (Node r1, Node r2, int k) {
    	if (k <= r2.sum && r1.l == 0 && r2.l == 0) return r2.val;
    	Node l1 = seg.tree[r1.l];
    	Node l2 = seg.tree[r2.l];
    	if (l2.sum - l1.sum > k) {
    		return getK(l1, l2, k);
    	} else {
    		return getK(seg.tree[r1.r], seg.tree[r2.r], k - (l2.sum - l1.sum));
    	}
    };
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	Node r2 = seg.tree[roots[r]];
    	Node r1 = seg.tree[roots[l-1]];
    	int sz = (r - l + 1);
    	map<int, int> ma;
    	vector<int> ss;
    	ss.push_back(sz / 3);
    	ss.push_back(2 * sz / 3);
    	for (int k : ss) {
    		int z2 = getK(r1, r2, k);
    		ma[z2]++;
    	}
    	vi ans;
    	for (auto [x, y] : ma) {
    		auto it1 = lower_bound(C[x].begin(), C[x].end(), r);
    		int idx1 = it1 - C[x].begin();
    		auto it2 = lower_bound(C[x].begin(), C[x].end(), l-1);
    		int idx2 = it2 - C[x].begin();
    		if (idx1 - idx2 > sz / 3) {
    			ans.push_back(c[x]);
    		}
    	}
    	sort(ans.begin(), ans.end());
    	if (!ans.size()) {
    		cout << -1 << endl;
    		continue;
    	}
    	for (int x : ans) {
    		cout << x << " ";
    	}
    	cout << endl;
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
