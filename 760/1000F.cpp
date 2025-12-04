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

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
int maxM = 1e6+5;
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
const int INF = 1E9 + 7;
template<typename T, typename F>
struct SegmentTree {
    int n;
    vector<T> tree;
    F combine;  
    T def;
    SegmentTree(int size, F comb, T default_value) : n(size), combine(comb) {
        def = default_value;
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
        if (l > end || r < start) return def;//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};

void comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
}
void solve() {
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n;
    cin >> n;
    auto cat = [&] (int n) {
    	return ncr(n, n / 2) * inv(n / 2 + 1);
    };
    mi ans = cat(2 * n);
    vector<mi> ca(2 * n + 1), ica(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
    	ca[i] = cat(i);
    	ica[i] = inv(ca[i]);
    }
    cout << (int) ca[2 * n] << " ";
    vector<pii> qrs(n);
    vi id(2 * n);
    for (int i = 0; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	qrs[i] = {u, v};
    	id[u] = id[v] = i;
    }

	SegmentTree<int, function<int(int, int)>> seg(n, [](int a, int b) { return  min(a, b); }, 2 * n);
	SegmentTree<int, function<int(int, int)>> seg2(2 * n + 1, [](int a, int b) { return  a + b; }, 0);
	
	seg2.update(2 * n, 2 * n + 2);
	vi seen(n);
	vi next(2 * n);
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (seen[id[i]]) {
			seg.update(id[i], 2 * n);
		} else {
			next[i] = seg.query(0, id[i] - 1);
			seg.update(id[i], i);
			seen[id[i]] = 1;
		}
	}
    for (int i = 0; i < n; i++) {
    	auto [u, v] = qrs[i];
    	int all = v - u + 1 - seg2.query(u, v);
    	int va = seg2.query(next[v], next[v]);
    	ans *= ica[va - 2];
    	ans *= ca[va - all - 2] * ca[all - 2];
    	seg2.update(v, all);
    	seg2.update(next[v], va - all);
    	cout << (int) ans << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
