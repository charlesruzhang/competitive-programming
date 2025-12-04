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
const int INF = 1e9 + 7;

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
	int maxM = 1e4+5;
    vector<mi> fact(maxM);
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    vector<mi> ifact(maxM);
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<mi>> S(n + m + 1, vector<mi>(k+1));
    for (int i = 0; i <= k; i++) {
    	S[i][i] = 1;
    }
    for (int i = 0; i < n + m; i++) {
    	for (int j = 1; j <= min(i, k); j++) {
    		S[i+1][j] = j * S[i][j] + S[i][j-1];
    	}
    }
    vector<mi> ans(n + m);
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		int x = n - i + 1;
    		int y = m - j + 1;
    		mi cnt = ncr(n, i) * ncr(m, j);
    		ans[x + y - 2 + min(i, j)] += cnt * S[x + y - 2][k - 1] * fact[k-1];
    	}
    }
    for (int i = min(n, m); i < n + m; i++) {
    	cout << (int) ans[i] << " ";
    }
    cout << endl;
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
