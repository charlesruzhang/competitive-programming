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
int N = 1e5 + 1;
vvi facts(N + 1);
vi primes;
const int maxN = N;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
            }
        }
    }
}
void comp() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j+=i) {
			facts[j].push_back(i);
		}
	}
}
vector<mi> S(N);
void solve() {
    int n = N;
    S[1] = 1;
    vector<mi> pref(n + 1);
    vector<mi> P(n + 1);
    mi R = 1;
    pref[1] = 1;
    P[1] = 1;
    vector<mi> res(n + 1);
    vector<mi> F(n + 1);
    vector<mi> T(n + 1);
    for (int i = 2; i <= n; i++) {
    	int sz = facts[i].size();
        vi PP;
        for (int x : facts[i]) {
            if (primes[x]) {
                PP.push_back(x);
            }
            F[x] = pref[x];
        }
        for (int pr : PP) {
            for (int x : facts[i]) {
                if (x % pr == 0) F[x] += F[x / pr];
            }
        }
    	for (int x : facts[i]) {
            mi tot = F[x] - P[x];
            T[x] = 2 * tot + 1;
    		P[x] += T[x];
    	}
        for (int pr : PP) {
            for (int j = sz - 1; j >= 0; j--) {
                int x = facts[i][j];
                if (x % pr == 0) T[x] -= T[x / pr];
            }
        }
    	for (int x: facts[i]) {
            pref[x] += T[x];
    		R += T[x];
    	}
        S[i] = R;
    }
} 
void solve2() {
    int n;
    cin >> n;
    cout << (int) S[n] << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    comp();
    solve();
    cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}
