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
const ll MOD = 1e9+7;
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
	int maxM = 6e5+5;
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
    int n;
    cin >> n;
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    vi a(n+1);
    for (int i = 0; i <= n; i++) {
    	cin >> a[i];
    }
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
    	if (a[i] != -1) {
    		int x = a[i];
    		if (x == 0) continue;
    		if (x > n) {
    			cout << 0 << endl;
    			return;
    		}
    		if (a[x] != -1 && a[x] != i) {
    			cout << 0 << endl;
    			return;
    		}
    		a[x] = i;
    	}
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
    	if (a[i] == -1) {
    		cnt++;
    	}
    }
    vector<mi> dp(n+1);
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
    	dp[i] = dp[i-1] + (i - 1) * dp[i - 2];
    }
    auto f = [&] (int x) {
    	mi tot = 0;
    	for (int i = 0; i <= x; i++) {
    		tot += ncr(x, i) * dp[x - i];
    	}
    	return tot;
    };
    if (a[n] == -1) {
    	mi ans = 0;
    	ans += f(cnt - 1) + (cnt - 1) * f(cnt-2);
    	cout << (int) ans << endl;
    	return;
    }
    //cout << cnt << "?" << endl;
    mi ans = f(cnt);
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
