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
class PersistentSegtree {
  private:
	struct Node {
		int sum = 0;
		int l = 0, r = 0;
	};

	const int n;
	vector<Node> tree;
	int timer = 1;

	Node join(int l, int r) { return Node{tree[l].sum + tree[r].sum, l, r}; }

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
		if (qr < tl || tr < ql) { return 0ll; }
		if (ql <= tl && tr <= qr) { return tree[v].sum; }

		int mid = (tl + tr) / 2;
		return range_sum(tree[v].l, ql, qr, tl, mid) +
		       range_sum(tree[v].r, ql, qr, mid + 1, tr);
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
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	x--;
    	a[x]++;
    }
    vector<PersistentSegtree> vP;
    vvi roots(18, vi(m + 1));
    for (int i = 0; i <= 17; i++) {
    	int sz = 2 << i;
    	vP.emplace_back(sz, 2 * sz + m * (i + 2));
    	vi arr(sz);
    	roots[i][0] = vP[i].build(arr);
    }
    for (int j = 0; j <= 17; j++) {
    	for (int i = 0; i < m; i++) {
    		if (a[i] == 0) {
    			roots[j][i+1] = roots[j][i];
    		} else {
    			int target = 2 << j;
    			int y = i % target;
    			int x = vP[j].range_sum(roots[j][i], y, y);
    			roots[j][i+1] = vP[j].set(roots[j][i], y, x + a[i]);
    			//cout << "Set: " << i << " " << j << " " << y << " " << x + a[i] << endl;
    		}
    	}
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int ans = 1;
    	for (int j = 0; j <= 17; j++) {
    		int L = 1 << j;
    		int R = (2 << j) - 1;
    		int T = 2 << j;
    		L = (L + l) & (T - 1);
    		R = (R + l) & (T - 1);
    		int tot = 0;
    		if (L > R) {
    			tot += vP[j].range_sum(roots[j][r+1], L, T - 1);
    			tot += vP[j].range_sum(roots[j][r+1], 0, R);
    			tot -= vP[j].range_sum(roots[j][l], L, T - 1);
    			tot -= vP[j].range_sum(roots[j][l], 0, R);
    		} else {
    			tot += vP[j].range_sum(roots[j][r+1], L, R);
    			tot -= vP[j].range_sum(roots[j][l], L, R);
    		}
    		//cout << i << " ^ " << j << " " << tot << endl;
    		if (tot % 2) {
    			ans = 0;
    			break;
    		}
    	}
    	cout << (ans ? 'B' : 'A');
    }
    cout << endl;
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
