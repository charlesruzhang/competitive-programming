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
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	a[i] -= i;
    	a[i] += n;
    }
    multiset<int, greater<>> s;
    vi cnt(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
    	s.insert(0);
    }
    vi val(n);
    for (int i = 0; i < n; i++) {
    	s.erase(s.find(cnt[a[i]]));
    	cnt[a[i]]++;
    	s.insert(cnt[a[i]]);
    	if (i >= k) {
    		s.erase(s.find(cnt[a[i-k]]));
    		cnt[a[i-k]]--;
    		s.insert(cnt[a[i-k]]);
    	}
    	auto it = s.begin();
    	val[i] = *it;
    }
    vi next(n);
    stack<pii> st;
    st.push({1e9, n});
    for (int i = n - 1; i >= 0; i--) {
    	while (st.top().first <= val[i]) {
    		st.pop();
    	}
    	auto [v, idx] = st.top();
    	next[i] = idx;
    	st.push({val[i], i});
    }
    vl dp(n+1);
    for (int i = n - 1; i >= 0; i--) {
    	int j = next[i];
    	dp[i] = dp[j] + 1ll * (j - i) * val[i]; 
    	//cout << i << " " << next[i] << " " << " " << val[i] <<" "<< dp[i] << endl;
    }
    using T = pii;
	SegmentTree<T, function<T(T, T)>> seg(n, [](T a, T b) { 
		if (a.first >= b.first) {
			return a;
		} else {
			return b;
		}
	}, T(-1, -1));
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = {val[i], i};
	}
	seg.build(arr);
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int maxx = seg.query(l + k - 1, r).second;
    	int naxx = next[maxx];
    	ll ans = dp[l + k - 1] - dp[naxx] - 1ll * (naxx - r - 1) * val[maxx];
    	ll ret = 1ll * (r - (l + k - 1) + 1) * k - ans;
    	cout << ret << endl;
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
