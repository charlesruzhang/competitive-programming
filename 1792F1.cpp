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
}static constexpr int PRIMITIVE_ROOT = 3; // for MOD = 998244353

// powmod for raw ints (sometimes handy)
static long long mod_pow_ll(long long a, long long e){
    long long r = 1 % MOD;
    while(e){
        if(e&1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        e >>= 1;
    }
    return r;
}

// next power of two >= x
static int next_pow2(int x){
    return x <= 1 ? 1 : 1 << (32 - __builtin_clz((unsigned)(x-1)));
}

// Precompute roots up to the maximum power-of-two dividing MOD-1
struct NTTContext {
    int max_log;          // largest L with 2^L | (MOD-1)
    int max_len;          // 1<<max_log
    vector<mi> root;      // root[k] = primitive 2^max_log-th root ^ k
    vector<mi> iroot;     // inverse roots
    vector<int> rev;      // bit-reversal indices

    NTTContext(){
        // find max_log such that (MOD-1) divisible by 2^max_log
        int t = MOD - 1;
        max_log = __builtin_ctz((unsigned)t);
        max_len = 1 << max_log;

        root.resize(max_len);
        iroot.resize(max_len);

        mi primitive = mi(mod_pow_ll(PRIMITIVE_ROOT, (MOD - 1) >> max_log)); // g^((MOD-1)/2^L)
        mi iprimitive = inv(primitive);

        root[0] = 1; iroot[0] = 1;
        for(int i=1;i<max_len;++i){
            root[i]  = root[i-1]  * primitive;
            iroot[i] = iroot[i-1] * iprimitive;
        }
    }

    void ensure_rev(int n){
        if((int)rev.size() == n) return;
        rev.assign(n, 0);
        int lg = __builtin_ctz((unsigned)n);
        for(int i=0;i<n;i++){
            rev[i] = (rev[i>>1]>>1) | ((i&1)<<(lg-1));
        }
    }

    // in-place NTT; a.size() must be a power of two and <= max_len
    void ntt(vector<mi>& a, bool invert){
        int n = (int)a.size();
        ensure_rev(n);
        for(int i=0;i<n;i++) if(i < rev[i]) swap(a[i], a[rev[i]]);

        for(int len=2; len<=n; len<<=1){
            int half = len >> 1;
            int step = max_len / len; // map butterfly j to root[j*step]
            for(int i=0;i<n;i+=len){
                int idx = 0;
                if(!invert){
                    for(int j=0;j<half;++j, idx+=step){
                        mi u = a[i+j];
                        mi v = a[i+j+half] * root[idx];
                        a[i+j]       = u + v;
                        a[i+j+half]  = u - v;
                    }
                }else{
                    for(int j=0;j<half;++j, idx+=step){
                        mi u = a[i+j];
                        mi v = a[i+j+half] * iroot[idx];
                        a[i+j]       = u + v;
                        a[i+j+half]  = u - v;
                    }
                }
            }
        }
        if(invert){
            mi inv_n = mi(1) / mi(n);
            for(mi& x : a) x *= inv_n;
        }
    }
};

static NTTContext __ntt; // construct once

// small-size fallback (naive O(n*m))
template<class T>
static vector<mi> mul_small(const T& A, const T& B){
    if(A.empty() || B.empty()) return {};
    vector<mi> C(A.size()+B.size()-1, mi(0));
    for(size_t i=0;i<A.size();++i){
        mi ai = A[i];
        for(size_t j=0;j<B.size();++j){
            C[i+j] += ai * B[j];
        }
    }
    return C;
}

// convolution with vectors of mi directly
static vector<mi> convolution(const vector<mi>& A, const vector<mi>& B){
    int n1 = (int)A.size(), n2 = (int)B.size();
    if(!n1 || !n2) return {};
    if(min(n1,n2) <= 32) return mul_small(A,B); // tiny: naive is faster

    int need = n1 + n2 - 1;
    int n = next_pow2(need);
    if(n > __ntt.max_len){
        // If this triggers, MOD's 2-adicity is too small for your n.
        // Options: split-and-CRT or use multiple NTT-friendly primes.
        // For 998244353 (2^23), you’re safe up to size ~8.3M.
        // For simplicity here, fall back to naive (slow) to keep template self-contained.
        return mul_small(A,B);
    }

    vector<mi> fa(n, mi(0)), fb(n, mi(0));
    for(int i=0;i<n1;++i) fa[i] = A[i];
    for(int i=0;i<n2;++i) fb[i] = B[i];

    __ntt.ntt(fa, false);
    __ntt.ntt(fb, false);
    for(int i=0;i<n;++i) fa[i] *= fb[i];
    __ntt.ntt(fa, true);

    fa.resize(need);
    return fa;
}

// convenience overloads for int/ll input (modded into `mi`)
static vector<mi> convolution_int(const vector<int>& A, const vector<int>& B){
    vector<mi> a(A.size()), b(B.size());
    for(size_t i=0;i<A.size();++i) a[i] = mi((long long)A[i]);
    for(size_t i=0;i<B.size();++i) b[i] = mi((long long)B[i]);
    return convolution(a,b);
}
static vector<mi> convolution_ll(const vector<long long>& A, const vector<long long>& B){
    vector<mi> a(A.size()), b(B.size());
    for(size_t i=0;i<A.size();++i) a[i] = mi(A[i]);
    for(size_t i=0;i<B.size();++i) b[i] = mi(B[i]);
    return convolution(a,b);
}
// --- assumes your `mi` and `MOD` and an NTT `convolution(const vector<mi>&, const vector<mi>&)` exist ---

namespace poly {
    using V = vector<mi>;

    V trim(V a, int n){ if((int)a.size()>n) a.resize(n); return a; }
    V add(const V& a, const V& b){
        V c(max(a.size(), b.size())); 
        for(size_t i=0;i<c.size();++i){
            mi x = (i<a.size()?a[i]:mi(0));
            mi y = (i<b.size()?b[i]:mi(0));
            c[i] = x + y;
        } return c;
    }
    V sub(const V& a, const V& b){
        V c(max(a.size(), b.size())); 
        for(size_t i=0;i<c.size();++i){
            mi x = (i<a.size()?a[i]:mi(0));
            mi y = (i<b.size()?b[i]:mi(0));
            c[i] = x - y;
        } return c;
    }
    V mul(const V& a, const V& b){
        if(a.empty()||b.empty()) return {};
        return convolution(a,b);
    }
    V deriv(V a){
        if(a.empty()) return {};
        V b(max<int>(0,(int)a.size()-1));
        for(size_t i=1;i<a.size();++i) b[i-1] = a[i] * mi((long long)i);
        return b;
    }
    V integr(V a){
        V b(a.size()+1); b[0]=mi(0);
        static vector<mi> invs; 
        int need=(int)a.size();
        if((int)invs.size()<=need){
            int old = (int)invs.size();
            invs.resize(need+1);
            if(old==0){ invs[1]=mi(1); old=2; }
            for(int i=max(2,old); i<=need; ++i) invs[i] = mi(1)/mi(i);
        }
        for(size_t i=0;i<a.size();++i) b[i+1] = a[i] * invs[i+1];
        return b;
    }
    // series inverse: B = 1/A mod x^n, with A[0] != 0
    V inv(const V& a, int n){
        V b(1, mi(1) / a[0]);
        int m=1;
        while(m<n){
            m <<= 1;
            V a_cut = trim(a, m);
            V t = mul(mul(b,b), a_cut);
            t = trim(t, m);
            // b = b + b - t
            V nb(m);
            for(int i=0;i<m;++i){
                mi bi = (i<(int)b.size()? b[i] : mi(0));
                mi ti = (i<(int)t.size()? t[i] : mi(0));
                nb[i] = bi + bi - ti;
            }
            b.swap(nb);
        }
        return trim(b,n);
    }
    // series log: ln A, A[0]=1
    V log(const V& a, int n){
        V da = deriv(a);
        V ia = inv(a, n);
        V q = mul(da, ia);
        q = trim(q, n-1);
        return trim(integr(q), n);
    }
}

// compute dp[0..n] for your recurrence in O(n log n)
vector<mi> solve_dp(int n){
    using namespace poly;
    if(n==0) return {mi(1)};
    // F(0)=dp[0]=1
    int N = n+1; // we need coefficients up to x^n
    V F(1, mi(1)); // start with constant 1
    int m = 1;
    while(m < N){
        int target = min(N, m<<1);
        // extend F to target with zeros
        F.resize(target, mi(0));

        // H(F) = 2 ln F - F - x + 1  (truncate to target)
        V lnF = log(F, target);
        V two_lnF = lnF; for(auto& z: two_lnF) z += lnF[ &z - &two_lnF[0] ]; // fast 2*lnF
        // construct -x + 1
        V lin(target, mi(0)); if(target>0) lin[0]=mi(1); if(target>1) lin[1]-=mi(1);
        V H = sub(sub(two_lnF, F), sub(V{mi(0)}, lin)); // 2lnF - F - (x-1) == 2lnF - F + (1 - x)
        // H'(F) = 2/F - 1
        V invF = inv(F, target);
        V two_over_F = invF; for(auto& z: two_over_F) z += invF[ &z - &two_over_F[0] ]; // *=2
        V Hp = two_over_F; if(!Hp.empty()) Hp[0] -= mi(1);

        // delta = H / H'  => multiply by inv(H')
        V invHp = inv(Hp, target);
        V delta = mul(H, invHp);
        delta = trim(delta, target);

        // F_new = F - delta
        for(int i=0;i<target;++i) F[i] -= (i<(int)delta.size()? delta[i] : mi(0));

        m <<= 1;
    }
    // coefficients: F(x) = sum dp[k] x^k / k!, so dp[k] = coeff * k!
    // we only need dp[n], but let’s build dp[0..n].
    // Precompute factorials up to n.
    vector<mi> fact(n+1, mi(1));
    for(int i=1;i<=n;i++) fact[i] = fact[i-1] * mi(i);

    vector<mi> dp(n+1);
    for(int k=0;k<=n;k++){
        mi coeff = (k<(int)F.size()? F[k] : mi(0));
        dp[k] = coeff * fact[k];
    }
    return dp;
}

// ---- use it in your solve() ----
void solve(){
    int n; cin >> n;
    auto dp = solve_dp(n);
    // your base matches: dp[1]=1, dp[2]=2 under this recurrence
    cout << (int)(dp[n] - mi(2)) << '\n';
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
