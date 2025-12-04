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
    auto find = [&] (int n, int k) {
    	// n pos, k coffee
    	// no two coffee adj
    	return ncr(n - k + 1, k);
    };
    vector<mi> fib(maxM);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < maxM; i++) {
    	fib[i] = fib[i-2] + fib[i-1];
    }
    int n, q;
    cin >> n >> q;
    vi a(n, -1);
    set<int> s;
    s.insert(-1);
    s.insert(n);
    mi ans = fib[n+2];
    vector<mi> bp(n+1);
    vector<mi> wp(n+1);
    vector<mi> bs(n+1);
    vector<mi> ws(n+1);
    bs[n] = ws[n] = 1;
    while (q--) {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	if (y == -1) {
    		if (a[x] != -1) {
    			s.erase(x);
    		}	
    		cout << (int) ans << endl;
    		continue;
    	} else {
    		if (a[x] != -1) {
    			s.erase(x);
    			bp[x] = wp[x] = 0;
    			bs[x] = ws[x] = 0;
    		}
    		auto it = s.lower_bound(x);
    		int r = *it;
    		--it;
    		int l = *it;
    		mi ww = 0, bb = 0, wb = 0, bw = 0;
    		int m = r - l;
    		if (r == n) {
	    		bp[x] += bp[l] * fib[m - 1];
    			bp[x] += wp[l] * fib[m];
    			wp[x] += bp[l] * fib[m];
    			wp[x] += wp[l] * fib[m+1];
    		} else {
	    		bp[x] += bp[l] * fib[m - 1];
    			bp[x] += wp[l] * fib[m];
    			wp[x] += bp[l] * fib[m];
    			wp[x] += wp[l] * fib[m+1];
    		}
    	}
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
