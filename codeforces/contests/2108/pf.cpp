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
int maxM = 1e5+5;
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
    int k, n;
    cin >> k >> n;
    vector<vector<mi>> dp(k + 1, vector<mi>(18));
    dp[1][0] = 1;
    for (int i = 2; i <= k; i++) {
    	vi vec;
    	for (int j = 2; j * j <= i; j++) {
    		if (i % j == 0) {
    			vec.push_back(j);
    			if (j * j != i) vec.push_back(i / j);
    		}
    	}
    	vec.push_back(i);
    	for (int z : vec) {
    		for (int j = 1; j <= 17; j++) {
    			dp[i][j] += dp[i / z][j - 1];
    		}
    	}
    }
    vector<mi> ans(k+1);
    vector<mi> C(19);
    C[0] = 1;
    for (int i = 1; i <= min(n + 1, 18); i++) {
    	C[i] = C[i-1] * (n - i + 2) / i;
    }
    for (int z = 1; z <= k; z++) {
	    for (int i = 0; i <= 17; i++) {
	    	ans[z] += C[i + 1] * dp[z][i];
	    }
	}
	ans[1]-=1;
	for (int i = 1; i <= k; i++) {
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
