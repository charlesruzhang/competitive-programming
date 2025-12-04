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
int maxM = 1e4+5;
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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi p(n);
    iota(p.begin(), p.end(), 1);
    int flag = 1;
    for (int i = 0; i < n; i++) {
    	if (p[i] != a[i] && a[i] != -1) {
    		flag = 0;
    		break;
    	}
    }
    mi ans = 0;
    for (int i = 1; i <= n; i++) {
    	int l = 1;
    	int r = i + 1;
    	int x = 0;
    	mi tot = 1;
    	for (int j = 0; j < n; j++) {
    		if (a[j] == -1) {
    			x++;
    		} else if (a[j] > i) {
    			tot *= ncr(x, a[j] - r);
    			x -= a[j] - r;
    			r = a[j] + 1;
    			if (x < 0) {
    				tot = 0;
    				break;
    			}
    			l += x;
    			x = 0;
    		} else {
    			tot *= ncr(x, a[j] - l);
    			x -= a[j] - l;
    			l = a[j] + 1;
    			if (x < 0) {
    				tot = 0;
    				break;
    			}
    			r += x;
    			x = 0;
    		}
    	}
    	tot *= ncr(x, i - l + 1); 
    	if (flag) {
    		tot -= 1;
    	}
    	ans += tot;
    }
    if (flag) {
    	ans += 1;
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
