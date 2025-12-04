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
        if (l > end || r < start) return T({-INF, 0, INF});//NEED TO INITIALIZE THIS!!!!!  
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
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	if (s[i] == '(') {
    		a[i] = 1;
    	} else {
    		a[i] = -1;
    	}
    }
    using T = array<int, 3>;
    SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { 
    	auto [a1, a2, a3] = a;
    	auto [b1, b2, b3] = b;
    	return T({max(a1 + b2, b1), a2 + b2, min(a3, a2 + b3)});
    }, T({-INF, 0, INF}));
    vector<T> b(n);
    for (int i = 0; i < n; i++) {
    	b[i] = {a[i], a[i], a[i]};
    }
	seg.build(b);
	set<int> s1;
	set<int, greater<>> s2;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			if (a[i] == 1) {
				s1.insert(i-1);
			} else {
				s2.insert(i-1);
			}
		}
	}
    while (q--) {
    	int x;
    	cin >> x;
    	x--;
    	if (n % 2 == 1) {
    		cout << "NO" << endl;
    		continue;
    	}
    	if (x && a[x] == a[x-1]) {
    		if (a[x] == 1) {
    			s1.erase(x-1);
    		} else {
    			s2.erase(x-1);
    		}
    	}
    	if (x != n - 1 && a[x] == a[x+1]) {
    		if (a[x] == 1) {
    			s1.erase(x);
    		} else {
    			s2.erase(x);
    		}
    	}
    	a[x] *= -1;
    	seg.update(x, {a[x], a[x], a[x]});
    	if (x && a[x] == a[x-1]) {
    		if (a[x] == 1) {
    			s1.insert(x-1);
    		} else {
    			s2.insert(x-1);
    		}
    	}
    	if (x != n - 1 && a[x] == a[x+1]) {
    		if (a[x] == 1) {
    			s1.insert(x);
    		} else {
    			s2.insert(x);
    		}
    	}
    	auto [z1, z2, z3] = seg.query(0, n - 1);
    	if (z3 < 0) {
			if (!s1.size()) {
    			cout << "NO" << endl;
    			continue;
    		} else {
    			auto [z1, z2, z3] = seg.query(0, *s1.begin());
    			if (z3 < 0) {
    				cout << "NO" << endl;
    				continue;
    			}
    		}
    	}
    	if (z1 > 0) {
    		if (!s2.size()) {
    			cout << "NO" << endl;
    			continue;
    		} else {
    			auto [z1, z2, z3] = seg.query(*s2.begin(), n - 1);
    			if (z1 > 0) {
    				cout << "NO" << endl;
    				continue;
    			}
    		}
    	}
    	cout << "YES" << endl;
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
