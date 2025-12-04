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
void solve() {
    int n, l, k;
    cin >> n >> l >> k;
	vector<pair<mi,mi>> ans(n, pair<mi, mi>(mi(0), mi(1)));

	vector<pair<mi,mi>> p(n, pair<mi, mi>(mi(0), mi(1)));
	p[n-1] = pair<mi,mi>(mi(1), mi(1));
    for (int i = l; i >= 1; i--) {
    	vector<pair<mi,mi>> props(n, pair<mi,mi>(mi((i + k)/ n), mi(i + k)));
    	for (int j = 0; j < (i + k) % n; j++) {
    		props[j].first+=1;
    	}

    	vector<pair<mi,mi>> q(n, pair<mi, mi>(mi(0), mi(1)));
    	for (int f = 0; f < n; f++) {
    		for (int g = 0; g < n; g++) {
    			mi xx = p[g].first * props[(f+n-g-1) % n].first;
    			mi yy = p[g].second * props[(f+n-g-1) % n].second;
    			mi aa = q[f].first;
    			mi bb = q[f].second;
    			q[f].first = aa * yy + bb * xx; 
    			q[f].second = bb * yy;
    		}
    	}
    	for (int j = 0; j < n; j++) {
    		mi aa = ans[j].first;
    		mi bb = ans[j].second;

    		ans[j].first = aa * q[j].second + bb * q[j].first;
    		ans[j].second = bb * q[j].second;
    	}
    	// for (int i = 0; i < n; i++) {
    	// 	cout << (int) (ans[i].first * inv(ans[i].second)) << " ";
    	// }
    	swap(q, p);
    }
    for (int i = 0; i < n; i++) {
    	cout << (int) (ans[i].first * inv(ans[i].second)) << " ";
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
