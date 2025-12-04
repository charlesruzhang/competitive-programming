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
const ll MAXX = 1e16;
const int MOD = 1e9+7;
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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    ll f1 = 2ll * (n - 2) + 2ll * (m - 2);
    ll f2 = n * 1ll * m - f1;
    ll all = 0; 
    for (int i = 0; i < k; i++) {
    	int x, y, c;
    	cin >> x >> y >> c;

    	if (((x == n || x == 1) && (y != 1 && y != m)) || ((y == m || y == 1) && (x != 1 && x != n))) {
    		f1--;
    		if (c) {
    			all++;
    		}
    	} else {
    		f2--;
    	}
    }
    if (f1 == 0 && all % 2 == 1) {
    	cout << 0 << endl;
    } else if (f1 == 0) {
    	cout << (int) powMod(mi(2), f2) << endl;
    } else {
    	cout << (int) powMod(mi(2), f2+f1-1) << endl;
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
