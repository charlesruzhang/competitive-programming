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
const int MOD = 1e9+7;
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
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

vi primes;
vi pvec;
const int maxN = 2e5+1;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
                primes[j] = 0;
            }
        }
    }
    pvec.clear();
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
}

class PersistentSegtree {
  private:
	struct Node {
		mi prod = 1;
		int l = 0, r = 0;
	};

	const int n;
	vector<Node> tree;
	int timer = 1;

	Node join(int l, int r) { return Node{tree[l].prod * tree[r].prod, l, r}; }

	int build(int tl, int tr, const vector<mi> &arr) {
		if (tl == tr) {
			tree[timer] = {arr[tl], 0, 0};
			return timer++;
		}

		int mid = (tl + tr) / 2;
		tree[timer] = join(build(tl, mid, arr), build(mid + 1, tr, arr));

		return timer++;
	}

	int set(int v, int pos, mi val, int tl, int tr) {
		if (tl == tr) {
			tree[timer] = {val, 0, 0};
			return timer++;
		}

		int mid = (tl + tr) / 2;
		if (pos <= mid) {
			tree[timer] = join(set(tree[v].l, pos, val, tl, mid), tree[v].r);
		} else {
			tree[timer] = join(tree[v].l, set(tree[v].r, pos, val, mid + 1, tr));
		}

		return timer++;
	}

	mi range_sum(int v, int ql, int qr, int tl, int tr) {
		if (qr < tl || tr < ql) { return mi(1); }
		if (ql <= tl && tr <= qr) { return tree[v].prod; }

		int mid = (tl + tr) / 2;
		return range_sum(tree[v].l, ql, qr, tl, mid) *
			range_sum(tree[v].r, ql, qr, mid + 1, tr);
	}

  public:
	PersistentSegtree(int n, int MX_NODES) : n(n), tree(MX_NODES) {}

	int build(const vector<mi> &arr) { return build(0, n - 1, arr); }

	int set(int root, int pos, mi val) { return set(root, pos, val, 0, n - 1); }

	mi range_sum(int root, int l, int r) { return range_sum(root, l, r, 0, n - 1); }

	int add_copy(int root) {
		tree[timer] = tree[root];
		return timer++;
	}
};

void solve() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int p = 0;
	for (int i = 0; i < pvec.size(); i++) {
		if (pvec[i] * pvec[i] >= maxN) {
			p = i;
			break;
		}
	}
	vi b = a;
	vvi facts(n, vi(p));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			while (b[i] % pvec[j] == 0) {
				b[i] /= pvec[j];
				facts[i][j]++;
			}
		}
	}
	PersistentSegtree seg(n+1, 350 * n);
	vector<mi> arr(n+1, 1);
	int root = seg.build(arr);
	vi prev(maxN, 0);
	vvi prev2(p, vi(20));
	vi roots(n+1);
	roots[0] = root;
	for (int i = 0; i < n; i++) {
		roots[i+1] = roots[i];
		if (b[i] != 1) {
			int pr = prev[b[i]];
			roots[i+1] = seg.set(roots[i+1], pr, seg.range_sum(roots[i+1], pr, pr) * b[i]);
			prev[b[i]] = i + 1;
		}
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < facts[i][j]; k++) {
				int pr = prev2[j][k];
				roots[i+1] = seg.set(roots[i+1], pr, seg.range_sum(roots[i+1], pr, pr) * pvec[j]);
				prev2[j][k] = i + 1;
			}
		}
		//cout << b[i] << " " << roots[i+1] << " " << i << " " << (int) seg.range_sum(roots[i+1], 0, n) << endl;
	}
	int q;
	cin >> q;
	int last = 0;
	while (q--) {
		int x, y;
		cin >> x >> y;
		int l = (last + x) % n;
		int r = (last + y) % n;
		if (l > r) swap(l, r);
		//cout << l << " " << r << endl;
		mi ans = 1;
		ans *= seg.range_sum(roots[r+1], 0, l);
		ans *= inv(seg.range_sum(roots[l], 0, l));
		cout << (int) ans << endl;
		last = (int) ans;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
