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
const ll MOD = 1e6+3;
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
int maxM = 1e6+3;
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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    int minn = INF;
    for (int i = 0; i < n; i++) {
    	int x = b[i];
    	int cnt = 0;
    	while (x > a[i]) {
    		if (x / 2 >= a[i]) {
    			x /= 2;
    			cnt++;
    		} else {
    			break;
    		}
    	}
    	minn = min(cnt, minn);
    }
    vvi V(minn+1);
    ll tot = minn;
    for (int i = 0; i < n; i++) {
    	int x = b[i];
    	for (int j = 0; j < minn; j++) {
    		if (x % 2) {
    			V[j].push_back(1);
    			tot++;
    		}
    		x /= 2;
    	}
    	V[minn].push_back(x - a[i]);
    	tot += x - a[i];
    }
    mi ans = 1;
    for (int i = 0; i <= minn; i++) {
    	mi res = 1;
    	ll summ = 0;
    	for (int x : V[i]) {
    		summ += x;
    		res *= ifact[x];
    	}
    	if (summ >= MOD) {
    		res = 0;
    	} else {
    		res *= fact[summ];
    	}
    	ans *= res;
    }
    cout << tot << " " << (int) ans << endl;
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