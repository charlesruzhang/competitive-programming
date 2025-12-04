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
        if (l > end || r < start) return INF;//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};


void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }

    using T = int;
    SegmentTree<T, function<T(T, T)>> seg1(n, [](T a, T b) {
    	return  min(a, b); }, INF);
    SegmentTree<T, function<T(T, T)>> seg2(n, [](T a, T b) {
    	return  min(a, b); }, INF);
    if (a > b) swap(a, b);
    vi dp(n, INF);
    dp[a] = 0;
    seg1.update(a, 0);
    seg2.update(a, 0);
    vvi L(n);
    vvi R(n);
    L[max(0, a - c[a])].push_back(a);
    R[min(n - 1, c[a] + a)].push_back(a);
    for (int z = 1; z <= a; z++) {
        if (a - z >= 0) {
            int i = a - z;
            dp[i] = min(dp[i], seg1.query(i + 1, i + c[i]) + 1);
            seg1.update(i, dp[i]);
            int l = max(0, i - c[i]);
            L[l].push_back(i);
            int r = min(n - 1, c[i] + i);
            if (r >= a + z) {
            	R[r].push_back(i);
            	seg2.update(i, dp[i]);
            }
            for (int x: L[i]) {
                seg1.update(x, INF);
            }
            L[i].clear();
        }

        if (a + z < n) {
            int i = a + z;
            dp[i] = min(dp[i], seg2.query(i - c[i], i - 1) + 1);
            seg2.update(i, dp[i]);
            int l = max(0, i - c[i]);
            if (l < a - z) {
            	L[l].push_back(i);
            	seg1.update(i, dp[i]);
            }
            int r = min(n - 1, c[i] + i);
            R[r].push_back(i);
            for (int x: R[i]) {
                seg2.update(x, INF);
            }
            R[i].clear();
        }
    }
    // for (int i = 0; i < n; i++) {
    // 	cout << i << " " << dp[i] << endl;
    // }

    for (int i = 0; i < n; i++) {
        dp[i] = min(dp[i], seg2.query(i - c[i], i - 1) + 1);
        seg2.update(i, dp[i]);
        int r = min(n - 1, c[i] + i);
        R[r].push_back(i);
        for (int x: R[i]) {
            seg2.update(x, INF);
        }
        R[i].clear();
	}
	// for (int i = 0; i < n; i++) {
    // 	cout << i << " " << dp[i] << endl;
    // }
    // cout << endl;
    for (int z = n - 1 - b; z >= 0; z--) {
        if (b + z < n) {
            int i = b + z;
            dp[i] = min(dp[i], seg1.query(i + 1, i + c[i]) + 1);
            dp[i] = min(dp[i], seg2.query(i + 1, i + c[i]) + 1);
            seg1.update(i, dp[i]);
            int l = max(0, i - c[i]);
            L[l].push_back(i);
            int r = min(n - 1, c[i] + i);
            if (r >= a + z) {
            	R[r].push_back(i);
            	seg2.update(i, dp[i]);
            }
            for (int x: L[i]) {
                seg1.update(x, INF);
            }
            L[i].clear();
        }
 
        if (b >= z && z != 0) {
            int i = b - z;
            dp[i] = min(dp[i], seg1.query(i + 1, i + c[i]) + 1);
            dp[i] = min(dp[i], seg2.query(i + 1, i + c[i]) + 1);
            seg2.update(i, dp[i]);
            int l = max(0, i - c[i]);
            if (l < a - z) {
            	L[l].push_back(i);
            	seg1.update(i, dp[i]);
            }
            int r = min(n - 1, c[i] + i);
            R[r].push_back(i);
            for (int x: R[i]) {
                seg2.update(x, INF);
            }
            R[i].clear();
        }
    }
    // for (int i = 0; i < n; i++) {
    // 	cout << i << " " << dp[i] << endl;
    // }
    cout << dp[b] << endl;
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
