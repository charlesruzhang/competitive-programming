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
const int INF = 1e9+7;
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
        if (l > end || r < start) return pii(0, INF);//NEED TO INITIALIZE THIS!!!!!  
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
    vi arr(n);
    int maxx = 0;
    int maxi = -1;
    int mini = -1;
    int minn = 1e9 + 7;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	if (arr[i] > maxx) {
    		maxx = arr[i];
    		maxi = i;
    	}
    	if (arr[i] < minn) {
    		minn = arr[i];
    		mini = i;
    	}
    }
    //cout << maxx << " " << maxi << " " << mini << " " << minn << endl;
    SegmentTree<pii, function<pii(pii, pii)>> seg(arr.size(), [](pii a, pii b) { return pii(max(a.first, b.first), min(a.second, b.second)); }, pii(0, INF));
    vector<pii> x(n);
    for (int i = 0; i < n; i++) {
    	x[i] = {arr[i], arr[i]};
    }
	seg.build(x);
	if (maxx == minn) {
		cout << 0 << endl;
		return;
	}
	int l = maxi - 1;
	int r = maxi + 1;
	int ans = maxx - minn;
	int diff = ans;
	int ans1 = max(seg.query(0, maxi-1).first, seg.query(maxi+1, n-1).first);
	ans = min(ans, ans1 - minn);
	while (l >= 0 || r < n) {
		int left = (l >= 0) ? (arr[l]) : -1;
		int right = (r < n) ? (arr[r]) : -1;
		if (left >= right) {
			l--;
		} else {
			r++;
		}

		if (l < 0 && r >= n) break;
		ans1 = max(seg.query(0, l).first, seg.query(r, n-1).first);
		int ans2 = seg.query(l+1, r-1).second;
		ans = min(ans, diff - min(maxx - ans1, ans2 - minn));
	}
	l = mini - 1;
	r = mini + 1;
	ans1 = min(seg.query(0, l).second, seg.query(r, n-1).second);
	//cout << "? " << ans1 << endl;
	ans = min(ans, maxx - ans1);
	while (l >= 0 || r < n) {
		int left = (l >= 0) ? (arr[l]) : INF;
		int right = (r < n) ? (arr[r]) : INF;
		if (left <= right) {
			l--;
		} else {
			r++;
		}
		if (l < 0 && r >= n) break;
		ans1 = min(seg.query(0, l).second, seg.query(r, n-1).second);
		
		int ans2 = seg.query(l+1, r-1).first;
		//cout << ans2 << " " << ans1 << " " << max(maxx - ans2, ans1 - minn) << " ? ?" << endl;
		ans = min(ans, diff - min(maxx - ans2, ans1 - minn));
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
