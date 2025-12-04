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
const ll MAXX = 1e17;
const int INF = 1e9 + 7;
template<typename T, typename F>
struct SegmentTree {
    int n;
    vector<T> tree;
    F combine;  
    T def;
    SegmentTree(int size, F comb, T default_value) : n(size), combine(comb) {
        tree.assign(4 * n, default_value);
        def = default_value;
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
        if (l > end || r < start) return def;//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};


void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl pref(n + 2);
    ll F = 1e15;
    pref[0] = F;
    for (int i = 0; i < n; i++) {
    	pref[i + 1] = pref[i] + a[i];
    }
    pref[n + 1] = pref[n] + F;
    vl suff(n + 2);
    suff[n + 1] = F;
    for (int i = n - 1; i >= 0; i--) {
    	suff[i + 1] = suff[i + 2] + a[i];
    }
    suff[0] = suff[1] + F;
    using T = pll;
    SegmentTree<T, function<T(T, T)>> seg(n + 2, [](T a, T b) { 
    	return  min(a, b); }, T(MAXX, -1));
    SegmentTree<T, function<T(T, T)>> seg2(n + 2, [](T a, T b) { 
    	return  min(a, b); }, T(MAXX, -1));

    SegmentTree<T, function<T(T, T)>> seg3(n + 2, [](T a, T b) { 
    	return  max(a, b); }, T(-MAXX, -1));
    SegmentTree<T, function<T(T, T)>> seg4(n + 2, [](T a, T b) { 
    	return  max(a, b); }, T(-MAXX, -1));
	vector<pll> arr(n + 2);
	for (int i = 0; i <= n + 1; i++) {
		arr[i] = {pref[i], i};
	}
	seg.build(arr);
	seg3.build(arr);
	vector<pll> brr(n + 2);
	for (int i = 0; i <= n + 1; i++) {
		brr[i] = {suff[i], i};
	}
	seg2.build(brr);
	seg4.build(brr);
	int L = k, R = k;
	ll X = a[k - 1];
	int flag = 1;
	while (L > 0 && R <= n) {
		//cout << L << " " << R << " " << X << endl;
		int l = R + 1;
		int r = n + 1;
		int nxt = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			auto [tot, i] = seg3.query(R + 1, m);
			if (tot < pref[R]) {
				l = m + 1;
			} else {
				auto [tot2, j] = seg.query(R + 1, m);
				if (tot2 - pref[R] + X < 0) {
					r = m - 1;
				} else {
					X += pref[i] - pref[R];
					nxt = i;
					break;
				}
			}
		}
		if (nxt != -1) {
			R = nxt;
			continue;
		}

		l = L - 1;
		r = 0;
		while (l >= r) {
			int m = (l + r) / 2;
			//cout << l << " " << r << " " << m << endl;
			auto [tot, i] = seg4.query(m, L - 1);
			if (tot < suff[L]) {
				l = m - 1;
			} else {
				auto [tot2, j] = seg2.query(m, L - 1);
				if (tot2 - suff[L] + X < 0) {
					r = m + 1;
				} else {
					X += suff[i] - suff[L];
					nxt = i;
					break;
				}
			}
		}
		if (nxt != -1) {
			L = nxt;
			continue;
		}
		flag = 0;
		break;
	}
	//cout << L << " " << R << endl;
	cout << (flag ? "YES" : "NO") << endl;
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
