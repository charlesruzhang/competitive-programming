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
ll mod_mul(ll a, ll b, ll mod) {
    return ll((__int128)a * b % mod);
}

ll mod_pow(ll a, ll d, ll mod) {
    ll res = 1;
    while (d) {
        if (d & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll p : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL, 17LL, 19LL, 23LL, 29LL, 31LL, 37LL}) {
        if (n % p == 0) return n == p;
    }
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    // Known bases for testing 64-bit range
    for (ll a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if (a % n == 0) continue;
        ll x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (ll r = 1; r < s; ++r) {
            x = mod_mul(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll pollards_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (isPrime(n)) return n;
    auto f = [&](ll x, ll c) { return (mod_mul(x, x, n) + c) % n; };
    while (true) {
        ll y = uniform_int_distribution<ll>(0, n - 1)(rng);
        ll c = uniform_int_distribution<ll>(1, n - 1)(rng);
        ll m = 128;
        ll g = 1, r = 1, q = 1;
        ll x, ys;
        while (g == 1) {
            x = y;
            for (ll i = 0; i < r; ++i) y = f(y, c);
            ll k = 0;
            while (k < r && g == 1) {
                ys = y;
                ll lim = min(m, r - k);
                for (ll i = 0; i < lim; ++i) {
                    y = f(y, c);
                    q = mod_mul(q, ll(llabs(x - y)), n);
                }
                g = gcd(q, n);
                k += lim;
            }
            r <<= 1;
        }
        if (g == n) {
            g = 1;
            y = ys;
            while (g == 1) {
                y = f(y, c);
                g = gcd(llabs(x - y), n);
            }
        }
        if (g > 1 && g < n) return g;
    }
}

// Recursive factorization using Pollard's Rho
void factor(ll n, vector<ll> &res) {
    if (n == 1) return;
    if (isPrime(n)) {
        res.push_back(n);
    } else {
        ll d = pollards_rho(n);
        factor(d, res);
        factor(n / d, res);
    }
}
vi primes;
vi mu;
const int maxN = 1e6+1;
vi pvec;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    mu[1] = 1;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                if ((j / i) % i == 0) {
                    mu[j] = 0;
                }
                mu[j] *= -1;
            }
            mu[i] = -1;
        }
    }
    pvec.clear();
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
}
void solve() {
    int n;
    n = 1e5;
    sieve();
    vl a(n);
    vi cnt(1e6 + 1);
    reverse(pvec.begin(), pvec.end());
    int z = (2 * 3 * 5 * 7 * 11 * 13 * 17);
    for (int i = 0; i < n / 2; i++) {
        a[i] = 1ll * pvec[i] * pvec[i+1];
    }
    for (int i = n / 2; i < n; i++) {
        a[i] = 1ll * pvec[i - n / 2] * pvec[i - n / 2];
    }
    reverse(pvec.begin(), pvec.end());
    vl res;
    vi v;
    for (int i = 0; i < n; i++) {
         vi v;
        for (int j = 0; j < pvec.size(); j++) {
            if (pvec[j] > 10'000) break;
            int x = pvec[j];
            if (a[i] % (x * x) == 0) {
                v.push_back(x);
            }
            while (a[i] % x == 0) {
                a[i] /= x;
            }
        }
        int y = floor(sqrt(a[i]));
        if (y > 1 && 1ll * y * y == a[i]) {
            v.push_back(y);
        }
    	assert(v.size() <= 7);
    	int m = v.size();
    	int k = 1 << m;
    	for (int j = 0; j < (1 << m); j++) {
    		ll tot = 1;
    		for (int k = 0; k < m; k++) {
    			if ((j >> k) & 1) {
    				tot *= v[k];
    			}
     		}
     		assert(tot <= 1e6);
     		cnt[tot]++;
    	}
    }
    ll ans = 1ll * n * (n - 1) / 2;
    for (int i = 2; i <= 1e6; i++) {
    	ans += 1ll * mu[i] * cnt[i] * (cnt[i] - 1) / 2; 
    }
    cout << ans << endl;
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
