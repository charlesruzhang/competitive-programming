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
int maxM = 2e5+5;
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

    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vi a(m1), b(m2);
    for (int i = 0; i < m1; i ++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m2; i ++) {
    	cin >> b[i];
    }
    if (a.back() != b[0] || a[0] != 1 || b.back() != n ) {
    	cout << 0 << endl;
    	return;
    }
    int mid = b[0] - 1;
    mi ans = ncr(n - 1, mid);
    int cur = mid;
    for (int i = m1 - 2; i >= 0; i--) {
    	ans *= ncr(cur - 1, a[i+1] - a[i] - 1) * fact[a[i+1] - a[i] - 1];
    	cur = a[i] - 1;
    } 
    cur = n - b[0];
    for (int i = 1; i < m2; i++) {
    	ans *= ncr(cur - 1, b[i] - b[i-1] - 1) * fact[b[i] - b[i-1] - 1];
    	cur = n - b[i];
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
