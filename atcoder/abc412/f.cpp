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
void solve() {
    int n, c;
    cin >> n >> c;
    vector<pii> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    	tot += a[i].first;
    }
    a[c-1].first++;
    tot++;
    mi itot = inv(tot - 1);
    sort(a.begin(), a.end(), greater<>());
    mi pref = 0;
    vector<mi> E(n);
    mi rem = tot;
    mi ans;
    for (int i = 0; i < n; i++) {
    	rem -= a[i].first;
    	//cout << i << " " << (int) rem << " " << (int) pref << " " << (int) itot << endl;
    	E[i] = (pref + 1) * inv(mi(1) - rem * itot);
    	//cout << i << " " << (int) E[i] << endl;
    	pref += mi(a[i].first) * itot * E[i];
    	if (a[i].second == c - 1) {
    		ans = E[i];
    	}
    }
    cout << (int) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
