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
    int n;
    cin >> n;
    vvi a(n, vi(6));
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 6; j++) {
    		cin >> a[i][j];
    		vec.push_back({a[i][j], i});
    	}
    }
    sort(vec.begin(), vec.end());
    int idx = 0;
    vi cnt(n);
    int tot = 0;
    mi ans = 0;
    mi C = 0;
    mi pC = 0;
    int first = 1;
    mi i6 = inv(6);
    while (idx < n * 6) {
    	while (idx < n * 6 && vec[idx].first == vec[idx+1].first) {
    		int z = vec[idx].second;
    		cnt[z]++;
    		if (cnt[z] == 1) tot++;
    		if (!first) {
    			C *= inv(cnt[z] - 1) * (cnt[z]);
    		}
    		idx++;
    	}
    	int z = vec[idx].second;
    	cnt[z]++;
    	if (cnt[z] == 1) tot++;
    	if (!first) {
			C *= inv(cnt[z] - 1) * (cnt[z]);
		}
    	if (tot == n && first) {
    		mi cur = 1;
    		for (int i = 0; i < n; i++) {
    			cur *= cnt[i] * i6;
    		}
    		first = 0;
    		C = cur;

    	}
		ans += (C - pC) * vec[idx].first;
    	pC = C;
    	idx++;
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
