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

SegmentTree<int, function<int(int, int)>> seg(2e6+2, [](int a, int b) { return  max(a, b); }, 0);

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int prev = 0;
    set<int> S;
    S.insert(0);
    for (int i = 0; i < n; i++) {
    	seg.update(prev + 1, max(0, a[i] - prev - 1));
    	//cout << prev + 1 << " " << max(0, a[i] - prev - 1) << endl;
    	prev = a[i];
    	S.insert(a[i]);
    }
    seg.update(prev + 1, INF);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
    	string s;
    	cin >> s;
    	if (s == "+") {
    		int x;
    		cin >> x;
    		auto it = S.lower_bound(x);
    		if (it != S.end()) seg.update(x + 1, *it - x - 1);
    		else seg.update(x + 1, INF);
    		--it;
    		int l = *it;
    		seg.update(l + 1, x - l - 1);
    		S.insert(x);
    	} else if (s == "-") {
    		int x;
    		cin >> x;
    		seg.update(x + 1, 0);
    		S.erase(x);
    		auto it = S.lower_bound(x);
    		int r = (it == S.end()) ? INF : *it;
    		--it;
    		int l = *it;
    		seg.update(l + 1, r - l - 1);
    	} else {
    		int k;
    		cin >> k;
    		int l = 1;
    		int r = 2e6 + 1;
    		while (l < r) {
    			int mid = (l + r) / 2;
    			if (seg.query(l, mid) >= k) {
    				r = mid;
    			} else {
    				l = mid + 1;
    			}
    		}
    		cout << l << " ";
    	}
    }
    cout << endl;
    auto it = S.begin();
    while (it != S.end()) {
    	int z = *it;
    	seg.update(z + 1, 0);
    	++it;
    }
    seg.update(1, INF);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    seg.update(1, INF);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
