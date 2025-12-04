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
struct Trie {
	int root = 0;
	vi left;
	vi right;
	vi val;
	int cnt = 0;
	int dir;
	int offset = 0;
	Trie (int d) {
		left.push_back(-1);
		right.push_back(-1);
		dir = d;
		if (!dir) val.push_back(-1);
		else val.push_back(1e9);
	}
	void add (int x) { // dir = 0 : record larger val
		int cur = root;
		for (int i = 30; i >= 0; i--) {
			if (x & (1 << i)) {
				if (left[cur] == -1) {
					left[cur] = ++cnt;
					left.push_back(-1);
					right.push_back(-1);
				}
				cur = left[cur];
			} else {
				if (right[cur] == -1) {
					right[cur] = ++cnt;
					left.push_back(-1);
					right.push_back(-1);
				}
				cur = right[cur];
			}
		}
	};
};
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
        if (l > end || r < start) return pii(-1, -1);//NEED TO INITIALIZE THIS!!!!!  
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
    using T = pii;
    SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) {
    	return max(a, b); 
    }, pii(-1, -1));
	
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = {a[i], i};
	}

	seg.build(arr);

	
	int res = 0;

	vi pref(n+1), suff(n+1);
	for (int i = 0; i < n; i++) {
		pref[i+1] = pref[i] ^ a[i];
	}
	for (int i = n - 1; i >= 0; i --) {
		suff[i] = suff[i+1] ^ a[i];
	}
	function <pair<Trie*, Trie*>(int, int)> f = [&] (int l, int r) {
		if (l > r) {
			Trie* L = new Trie(0);
			Trie* R = new Trie(1);
			return pair<Trie*, Trie*>(L, R);
		}
		if (l == r) {
			Trie* L = new Trie(0);
			Trie* R = new Trie(1);
			L -> add(a[l]);
			R -> add(a[l]);
			return pair<Trie*, Trie*>(L, R);
		}
		int maxx = seg.query(l, r).second;
		auto [LL, LR] = f(l, maxx - 1);
		auto [RL, RR] = f(maxx+1, r);
		if (maxx - l >= r - maxx) {
			for (int i = maxx; i <= r; i++) {
				int z = pref[i+1] ^ pref[maxx+1] ^ LR -> offset;
				res = max(res, pref[i+1] ^ pref[maxx+1]);
				int cur = LR -> root;
				int tot = 0;
				for (int i = 30; i >= 0; i--) {
					if (z & (1 << i)) {
						if (LR -> right[cur] != -1) {
							cur = LR -> right[cur];
						} else {
							tot += (1 << i);
							cur = LR -> left[cur];
						}
					} else {
						if (LR -> left[cur] != -1) {
							tot += (1 << i);
							cur = LR -> left[cur];
						} else {
							cur = LR -> right[cur];
						}
					}
				}
				res = max(res, tot ^ z);
			}
		} else {
			for (int i = maxx; i >= l; i--) {
				int z = suff[maxx] ^ suff[i] ^ RL -> offset;
				res = max(res, suff[maxx] ^ suff[i]);
				int cur = RL -> root;
				int tot = 0;
				for (int i = 30; i >= 0; i--) {
					if (z & (1 << i)) {
						if (RL -> right[cur] != -1) {
							cur = RL -> right[cur];
						} else {
							tot += (1 << i);
							cur = RL -> left[cur];
						}
					} else {
						if (RL -> left[cur] != -1) {
							tot += (1 << i);
							cur = RL -> left[cur];
						} else {
							cur = RL -> right[cur];
						}
					}
				}
				res = max(res, tot ^ z);
			}
		}
		if (maxx - l >= r - maxx) {
			int of = LL -> offset;
			for (int i = maxx; i <= r; i++) {
				int z = pref[i + 1] ^ pref[l] ^ of;
				LL -> add(z);
			}
			LR -> offset ^= suff[r + 1] ^ suff[maxx];
			of = LR -> offset;
			for (int i = maxx; i <= r; i++) {
				int z = suff[i] ^ suff[r + 1] ^ of;
				LR -> add(z);
			}
			return pair<Trie*, Trie*>(LL, LR);
		} else {
			RL -> offset ^= pref[maxx + 1] ^ pref[l];
			int of = RL -> offset;
			for (int i = l; i <= maxx; i++) {
				int z = pref[i + 1] ^ pref[l] ^ of;
				RL -> add(z);
			}
			of = RR -> offset;
			for (int i = l; i <= maxx; i++) {
				int z = suff[i] ^ suff[r + 1] ^ of;
				RR -> add(z);
			}
			return pair<Trie*, Trie*>(RL, RR);
		}

	};
	auto [L, R] = f(0, n - 1);

	cout << res << endl;
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
