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
vi primes;
vi pvec;
vi mu;
const int maxN = 2e1+1;
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
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi cnt(maxN);
    for (int i = 0; i < n; i++) {
    	for (int j = 1; j * j <= a[i]; j++) {
    		if (a[i] % j == 0) {
    			cnt[j]++;
    			if (j * j != a[i]) cnt[a[i] / j]++;
    		}
    	}
    }
    vector<mi> p3(maxN, 1);
    vector<mi> p2(maxN, 1);
    for (int i = 1; i < maxN; i++) {
    	p2[i] = p2[i-1] * 2;
    	p3[i] = p3[i-1] * 3;
    }
    auto f = [&] (int g, int h, int z) {
    	int cz = (z >= maxN) ? 0 : cnt[z];
    	mi res = p3[cz] * p2[cnt[g] - cz] * p2[cnt[h] - cz];
    	res -= p2[cnt[g]] + p2[cnt[h]];
    	res += 1;
    	return res;
    };
    mi res = 0;
    for (int z = 1; z < maxN; z++) {
    	unordered_map<int, int> ma;
    	int cur = z;
    	for (int j = 2; j * j <= cur; j++) {
    		while (cur % j == 0) {
    			cur /= j;
    			ma[j] += 1;
    		}
    	}
    	if (cur != 1) {
    		ma[cur] += 1;
    	}
    	auto it = ma.begin();
    	vector<int> vec;
    	while (it != ma.end()) {
    		vec.push_back(it -> first);
    		++it;
    	}
    	for (int i = 0; i < (1 << (2 * vec.size())); i++) {
    		int g = z;
    		int h = z;
    		int q = z;
    		for (int j = 0; j < vec.size(); j++) {
    			if ((1 << (2 * j + 1)) & i) {
    				if (!(1 << (2 * j) & i)) {
    					q /= vec[j];
    				}
    			} else {
    				q /= vec[j];
    				if (!(1 << (2 * j) & i)) {
    					g /= vec[j];
    				} else {
    					h /= vec[j];
    				}
    			}
    		}
    		res += q * mu[g / q] * mu[h / q] * f(g, h, z);
    	}
    }
	//res += i * mu[j] * mu[k] * f(j * i, k * i);
    cout << (int) res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
