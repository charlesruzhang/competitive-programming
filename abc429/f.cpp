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
    vector<vector<char>> vs(3, vector<char>(n));
    for (int i = 0; i < 3; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < n; j++) {
    		vs[i][j] = s[j];
    	}
    }
    using T = array<array<ll, 3>, 3>;
    vector<T> a(n);
    T D;
    for (int i = 0; i < 3; i++) {
    	D[i] = {INF, INF, INF};
    }
	SegmentTree<T, function<T(T, T)>> seg(n, [&D](T a, T b) { 
		T c = D;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					c[i][j] = min(c[i][j], a[i][k] + 1 + b[k][j]);
				}
			}
		}
		return c; }, D);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int flag = 1;
				for (int l = min(j, k); l <= max(j, k); l++) {
					if (vs[l][i] == '#') flag = 0;
				}
				a[i][j][k] = flag ? abs(j - k) : INF;
				//cout << i << " " << j << " " << k << " " << a[i][j][k] << endl;
			}
		}
	}
	seg.build(a);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int r, c;
		cin >> r >> c;
		r--; c--;
		vs[r][c] = (vs[r][c] == '.' ? '#' : '.');
		T b;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int flag = 1;
				for (int l = min(j, k); l <= max(j, k); l++) {
					if (vs[l][c] == '#') flag = 0;
				}
				b[j][k] = flag ? abs(j - k) : INF;
			}
		}
		seg.update(c, b);
		auto E = seg.query(0, n - 1);
		ll x = E[0][2];
		if (x < INF) cout << x << endl;
		else cout << -1 << endl;
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
