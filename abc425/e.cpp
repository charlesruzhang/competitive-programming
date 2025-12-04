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
ll MOD = 998244353;
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
vector<map<int, ll>> fact2(maxM);
map<int, int> ma;
ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = egcd(a, m, x, y);
    if (g != 1) return -1; // no inverse exists
    x %= m;
    if (x < 0) x += m;
    return x;
}
void comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
    	int cur = i;
    	for (auto [x, y]: ma) {
    		while (cur % x == 0) {
    			cur /= x;
    		}
    	}
        fact[i] = fact[i-1] * cur;
    }
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = modInverse((int)fact[i], MOD);
    }
    auto it = ma.begin();
    while (it != ma.end()) {
    	int x = it -> first;
    	for (int i = 1; i < maxM; i++) {
    		int cnt = 0;
    		int cur = i;
    		while (cur % x == 0) {
    			cnt++;
    			cur /= x;
    		}
    		fact2[i][x] = fact2[i-1][x] + cnt;
    	}
    	++it;
    }
}
ll powMod(ll base, long long exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}
void solve() {
	auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        //cout << (int) fact[n] << " " << (int) ifact[k] << " "<< (int) ifact[n-k] << endl;
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int summ = accumulate(a.begin(), a.end(), 0);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
    	mi tot = ncr(summ, a[i]);
    	auto it = ma.begin();
    	ll cur = 1;
    	while (it != ma.end()) {
    		int x = it -> first;
    		int c1 = fact2[summ][x];
    		int c2 = fact2[summ - a[i]][x];
    		int c3 = fact2[a[i]][x];
    		int d = c1 - c2 - c3;
    		cur = (cur * powMod(x, d)) % MOD;
    		++it;
    	}

    	//cout << i << " " << summ << " " << a[i] << " " << summ - a[i] << endl;
    	// cout << tot.v << endl;
    	//cout << cur << "%" << tot.v<< endl;
    	cur = (tot.v * cur) % MOD;
    	//cout << cur << "^^ " << endl;
    	ans = (ans * cur) % MOD;
    	summ -= a[i];
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    cin >> MOD;
    int x = MOD;
    for (int i = 2; i * i <= x; i++) {
    	int cnt = 0;
    	while (x % i == 0) {
    		x /= i;
    		cnt++;
    	}
    	if (cnt) ma[i] = cnt;
    }
    if (x > 1) {
    	ma[x] = 1;
    }
    comp();
    while (t--) {
        solve();
    }
    return 0;
}
