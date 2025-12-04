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
const int MOD = 998244353;
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
int LOG = 22;
void solve() {
	int n, k;
	cin >> n >> k;
	vi b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	vector<mi> kk(LOG+1);
	kk[0] = mi(1);
	for (int i = 1; i <= LOG; i++) {
		kk[i] = kk[i-1] * (k + i - 1) / i;
	}   
	vvi layer(LOG+1);
	for (int i = 1; i <= n; i++) {
		int dig = __builtin_ctz(i & -i);
		layer[dig].push_back(i);
	}
	vi val(n+1);
	for (int i = LOG; i >= 0; i--) {
		for (int x : layer[i]) {
			if (x + (x & -x) > n) {
				val[x] = 0;
			} else {
				val[x] = val[x + (x & -x)] + 1;
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << val[i] << "? " << endl;
	// }
	// for (int i = 1; i <= LOG; i++) {
	// 	cout << (int) kk[i] << "! " << endl;
	// }
	vector<mi> ans(n+1);
	for (int i = 0; i <= LOG; i++) {
		for (int x : layer[i]) {
			ans[x] = mi(b[x]);
			for (int j = x - (x & -x) + 1; j < x; j++) {
				int y = val[j] - val[x];
				ans[x] -= kk[y] * ans[j]; 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (int) ans[i] << " ";
	}
	cout << endl;
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
