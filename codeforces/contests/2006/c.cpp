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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (n == 1) {
    	cout << 1 << endl;
    	return;
    }
    SegmentTree<int, function<int(int, int)>> seg(n - 1, [](int a, int b) { return gcd(a, b); }, 0);
	vi b(n - 1);
	for (int i = 0; i < n - 1; i++) {
		b[i] = abs(a[i] - a[i+1]);
		//cout << b[i] << " ";
	}
	// cout << endl;
	//  cout << "^^^^^^^^^^^^^^" << endl;
	seg.build(b);
	auto f = [&](int x) {
		if ((x & (x - 1)) == 0) return true;
		return false;
	};
	ll ans = n;
	int cons = 0;
	int prev = 0;
	for (int i = 0; i < n - 1; i++) {
		if (b[i] == 0) {
			ans += prev + 1;
			prev++;
			continue;
		}
		if (!f(seg.query(0, i))) {
			prev = 0;
			continue;
		}
		int cur = i;
		int g = 0;
		for (int j = 19; j >= 0; j--) {
			if (cur < 0) break;
			if ((1 << j) > cur + 1) continue;
			int h = gcd(g, seg.query(cur - (1 << j) + 1, cur));
			if (f(h)) {
				continue;
			} else {
				g = h;
				cur -= (1 << j);
				//cout << "? " << i << " " << j << endl;
			}
		}
		ans += cur + 1;
		prev = cur + 1;
		//cout << i << " " << cur + 1 << endl;
	}
	cout << ans << endl;
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
