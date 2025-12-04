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
const ll MOD = 1e9+7;
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
int maxM = 1e3+5;
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
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
    int n, i, j, x, y;
    cin >> n >> i >> j >> x >> y;
    if (x == n) {
    	if (i == 1) {
    		cout << 0 << endl;
    		return;
    	}
    	mi ans = ncr(n - y - 1, j - i - 1) * ncr(y - 1, n - j);
    	cout << (int) ans << endl;
    	return;
    }
    if (y == n) {
    	if (j == n) {
    		cout << 0 << endl;
    		return;
    	}
    	mi ans = ncr(n - x - 1, j - i - 1) * ncr(x - 1, i - 1);
    	cout << (int) ans << endl;
    	return;
    }
    mi ans = 0;
	int maxx = max(x, y);
	int minn = min(x, y);
    for (int z = i + 1; z < j; z++) {
    	if (x < y) ans += ncr(n - 1 - maxx, j - z - 1) * ncr(maxx - minn - 1, z - i - 1 - (n - 1 - maxx - (j - z - 1))) * ncr(minn - 1, i - 1);
    	else ans += ncr(n - 1 - maxx, z - i - 1) * ncr(maxx - minn - 1, j - z - 1 - (n - 1 - maxx - (z - i - 1))) * ncr(minn - 1, n - j);
    }
    if (x < y) {
    	for (int z = j + 1; z < n; z++) {
    		ans += ncr(n - 1 - maxx, z - j - 1) * ncr(maxx - minn - 1, j - i - 1) * ncr(minn - 1, i - 1);
    	}
    } else {
    	for (int z = 2; z < i; z++) {
    		ans += ncr(n - 1 - maxx, i - z - 1) * ncr(maxx - minn - 1, j - i - 1) * ncr(minn - 1, n - j);
    	}
    }
    cout << (int) ans << endl;
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
