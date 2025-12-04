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
static const int MOD = 998244353;
static const int G = 3;

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

static void ntt(vector<mi>& a, bool invert_ntt) {
	int n = (int)a.size();
	static vector<int> rev;
	static vector<mi> roots{0, 1};

	if ((int)rev.size() != n) {
		int k = __builtin_ctz(n);
		rev.assign(n, 0);
		for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	}
	if ((int)roots.size() < n) {
		int k = __builtin_ctz((int)roots.size());
		roots.resize(n);
		while ((1 << k) < n) {
			mi e = pow(mi(G), (MOD - 1) >> (k + 1));
			for (int i = 1 << (k - 1); i < (1 << k); i++) {
				roots[2 * i] = roots[i];
				roots[2 * i + 1] = roots[i] * e;
			}
			k++;
		}
	}

	for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);

	for (int len = 1; len < n; len <<= 1) {
		for (int i = 0; i < n; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				mi u = a[i + j];
				mi v = a[i + j + len] * roots[len + j];
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
		}
	}

	if (invert_ntt) {
		reverse(a.begin() + 1, a.end());
		mi inv_n = inv(mi(n));
		for (auto& x : a) x *= inv_n;
	}
}

/*
ntt(a, invert)
input:  a.size() is power of two, coeffs mod MOD
output: if invert=false -> a becomes NTT(a)
        if invert=true  -> a becomes inverse NTT(a)
*/
static vector<mi> convolution(vector<mi> a, vector<mi> b) {
	if (a.empty() || b.empty()) return {};
	long long n = (long long)a.size(), m = (long long)b.size();
	if (n * m <= 256) {
		vector<mi> c(n + m - 1);
		for (int i = 0; i < (int)n; i++) for (int j = 0; j < (int)m; j++) c[i + j] += a[i] * b[j];
		return c;
	}
	int sz = 1;
	while (sz < (int)(n + m - 1)) sz <<= 1;
	a.resize(sz); b.resize(sz);
	ntt(a, false); ntt(b, false);
	for (int i = 0; i < sz; i++) a[i] *= b[i];
	ntt(a, true);
	a.resize(n + m - 1);
	return a;
}
/*
convolution(a, b)
input:  arrays of coefficients
output: coefficients of product, size = a.size()+b.size()-1
*/

static vector<mi> INV;
static void ensure_inv(int n) {
	if ((int)INV.size() > n) return;
	int old = max(2, (int)INV.size());
	if (INV.empty()) INV = {0, 1};
	INV.resize(n + 1);
	for (int i = old; i <= n; i++) INV[i] = mi(MOD - (long long)(MOD / i) * INV[MOD % i].v % MOD);
}

struct Poly {
	vector<mi> a;

	Poly() {}
	Poly(int n) : a(n) {}
	Poly(const vector<mi>& v) : a(v) { trim(); }

	int size() const { return (int)a.size(); }
	bool empty() const { return a.empty(); }
	mi operator[](int i) const { return i < (int)a.size() ? a[i] : mi(0); }
	mi& operator[](int i) { return a[i]; }

	void trim() { while (!a.empty() && a.back().v == 0) a.pop_back(); }
	/*
	trim()
	input:  polynomial (any size)
	output: removes trailing zeros
	*/

	Poly mod_xk(int k) const {
		k = min(k, size());
		return Poly(vector<mi>(a.begin(), a.begin() + k));
	}
	/*
	mod_xk(k)
	input:  polynomial p, integer k
	output: p mod x^k (keep coeffs [0..k-1])
	*/

	Poly mul_xk(int k) const {
		if (empty()) return Poly();
		vector<mi> r(k);
		r.insert(r.end(), a.begin(), a.end());
		return Poly(r);
	}
	/*
	mul_xk(k)
	input:  polynomial p, integer k
	output: p * x^k (shift up by k)
	*/

	Poly div_xk(int k) const {
		if (k >= size()) return Poly();
		return Poly(vector<mi>(a.begin() + k, a.end()));
	}
	/*
	div_xk(k)
	input:  polynomial p, integer k
	output: floor(p / x^k) (drop first k coeffs)
	*/
};

static Poly operator+(const Poly& p, const Poly& q) {
	Poly r(max(p.size(), q.size()));
	for (int i = 0; i < r.size(); i++) r.a[i] = p[i] + q[i];
	r.trim();
	return r;
}
/*
p + q
input:  polynomials p, q
output: sum
*/

static Poly operator-(const Poly& p, const Poly& q) {
	Poly r(max(p.size(), q.size()));
	for (int i = 0; i < r.size(); i++) r.a[i] = p[i] - q[i];
	r.trim();
	return r;
}
/*
p - q
input:  polynomials p, q
output: difference
*/

static Poly operator*(const Poly& p, const Poly& q) {
	return Poly(convolution(p.a, q.a));
}
/*
p * q
input:  polynomials p, q
output: product via NTT
*/

static Poly scalar_mul(const Poly& p, mi c) {
	Poly r = p;
	for (auto& x : r.a) x *= c;
	r.trim();
	return r;
}
/*
scalar_mul(p, c)
input:  polynomial p, scalar c
output: c*p
*/

static Poly deriv(const Poly& f) {
	if (f.size() <= 1) return Poly();
	Poly g(f.size() - 1);
	for (int i = 1; i < f.size(); i++) g.a[i - 1] = f.a[i] * mi(i);
	g.trim();
	return g;
}
/*
deriv(f)
input:  f = sum a_i x^i
output: f' = sum i*a_i x^(i-1)
*/

static Poly integr(const Poly& f) {
	Poly g(f.size() + 1);
	ensure_inv(f.size() + 1);
	for (int i = 0; i < f.size(); i++) g.a[i + 1] = f.a[i] * INV[i + 1];
	g.trim();
	return g;
}
/*
integr(f)
input:  f = sum a_i x^i
output: integral with constant term 0: F = sum a_i/(i+1) x^(i+1)
*/

static Poly inv_poly(const Poly& f, int n) {
	Poly r(1);
	r.a[0] = inv(f.a[0]);
	int m = 1;
	while (m < n) {
		int k = min(2 * m, n);
		Poly f0 = f.mod_xk(k);
		Poly rr = r * r * f0;
		Poly two_r = scalar_mul(r, mi(2));
		r = (two_r - rr).mod_xk(k);
		m = k;
	}
	r.trim();
	return r.mod_xk(n);
}
/*
inv_poly(f, n)
input:  f with f[0] != 0, integer n
output: g such that f*g ≡ 1 (mod x^n), size n
*/

static Poly ln_poly(const Poly& f, int n) {
	Poly df = deriv(f);
	Poly invf = inv_poly(f, n);
	Poly g = (df * invf).mod_xk(n - 1);
	return integr(g).mod_xk(n);
}
/*
ln_poly(f, n)
input:  f with f[0] = 1, integer n
output: ln(f) modulo x^n, constant term 0
*/

static Poly exp_poly(const Poly& f, int n) {
	Poly g(1);
	g.a[0] = 1;
	int m = 1;
	while (m < n) {
		int k = min(2 * m, n);
		Poly ln_g = ln_poly(g, k);
		Poly diff = (f.mod_xk(k) - ln_g);
		diff.a.resize(k);
		diff.a[0] += mi(1);
		g = (g * diff).mod_xk(k);
		m = k;
	}
	g.trim();
	return g.mod_xk(n);
}
/*
exp_poly(f, n)
input:  f with f[0] = 0, integer n
output: exp(f) modulo x^n, with constant term 1
*/

static Poly pow_poly(const Poly& f, long long k, int n) {
	if (n == 0) return Poly();
	if (k == 0) {
		Poly r(n);
		r.a[0] = 1;
		r.trim();
		return r;
	}
	int i = 0;
	while (i < f.size() && f.a[i].v == 0) i++;
	if (i == f.size()) return Poly();
	long long shift = 1LL * i * k;
	if (shift >= n) return Poly();
	mi c = f.a[i];
	Poly g = f.div_xk(i);
	g = scalar_mul(g, inv(c));
	Poly ln_g = ln_poly(g, n - (int)shift);
	ln_g = scalar_mul(ln_g, mi(k));
	Poly h = exp_poly(ln_g, n - (int)shift);
	h = scalar_mul(h, pow(c, k));
	h = h.mul_xk((int)shift).mod_xk(n);
	h.trim();
	return h;
}
/*
pow_poly(f, k, n)
input:  polynomial f, exponent k>=0, integer n
output: f^k modulo x^n
*/

static Poly rev_poly(const Poly& f) {
	Poly r = f;
	reverse(r.a.begin(), r.a.end());
	r.trim();
	return r;
}
/*
rev_poly(f)
input:  polynomial f
output: reversed coefficients
*/

static pair<Poly, Poly> divmod_poly(Poly a, Poly b) {
	a.trim(); b.trim();
	if (b.empty()) throw runtime_error("div by zero poly");
	if (a.size() < b.size()) return {Poly(), a};
	int n = a.size(), m = b.size();
	int k = n - m + 1;
	Poly ar = rev_poly(a);
	Poly br = rev_poly(b);
	Poly inv_br = inv_poly(br, k);
	Poly qr = (ar.mod_xk(k) * inv_br).mod_xk(k);
	Poly q = rev_poly(qr);
	Poly r = a - (b * q);
	r = r.mod_xk(m - 1);
	q.trim(); r.trim();
	return {q, r};
}
/*
divmod_poly(a, b)
input:  polynomials a, b (b != 0)
output: q, r such that a = b*q + r and deg(r) < deg(b)
*/

static Poly mod_poly(const Poly& a, const Poly& b) {
	return divmod_poly(a, b).second;
}
/*
mod_poly(a, b)
input:  polynomials a, b (b != 0)
output: a mod b
*/

static mi eval_poly(const Poly& f, mi x) {
	mi r = 0;
	for (int i = f.size() - 1; i >= 0; i--) r = r * x + f.a[i];
	return r;
}
/*
eval_poly(f, x)
input:  polynomial f, value x
output: f(x) mod MOD
*/

void solve() {
	int maxM = 1e6+5;
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
    int n, m;
    cin >> n >> m;
    vector<vector<mi>> dp(m + 1, vector<mi>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
    	for (int j = 0; j <= n; j++) {
    		for (int k = 0; k <= i; k++) {
    			dp[i][j] += ncr(j, k) * dp[i-1][j - k];
    		}
    	}
    }
    cout << (int) dp[m][n] << endl;
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
