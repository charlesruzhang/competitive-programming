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
struct FlatMap {
    uint64_t mask = 0;
    vector<uint64_t> key;      // 8B
    vector<int>      val;      // 4B
    vector<uint8_t>  used;     // 1B
    size_t sz = 0;

    static inline uint64_t mix(uint64_t x){
        x ^= x >> 30; x *= 0xbf58476d1ce4e5b9ULL;
        x ^= x >> 27; x *= 0x94d049bb133111ebULL;
        x ^= x >> 31; return x;
    }
    void init(size_t need){
        // cap = next power of two >= ceil(need / load)
        const double load = 0.8;
        size_t cap = 1;
        size_t want = (size_t)ceil(need / load);
        while (cap < want) cap <<= 1;
        mask = cap - 1;
        key.assign(cap, 0);
        val.assign(cap, 0);
        used.assign(cap, 0);
        sz = 0;
    }
    // returns pointer to value if found else nullptr
    inline int* find_ptr(uint64_t k){
        uint64_t i = mix(k) & mask;
        while (used[i]){
            if (key[i] == k) return &val[i];
            i = (i + 1) & mask;
        }
        return nullptr;
    }
    // inserts {k, v} if absent; returns reference to stored value
    inline int& emplace_if_absent(uint64_t k, int v0){
        uint64_t i = mix(k) & mask;
        while (used[i]){
            if (key[i] == k) return val[i];
            i = (i + 1) & mask;
        }
        used[i] = 1; key[i] = k; val[i] = v0; ++sz; return val[i];
    }
};

void solve() {
    int n;
    cin >> n;
    vi a;
    vector<FlatMap> vm(3001);
	for (int len = 1; len <= n; ++len) {
		vm[len].init(n - len + 1);
	}
    int pm = 3;
    mi tot = 0;
    vi flag(n);
    vector<mi> tmp(n + 1);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	a.push_back(x);
    	ll cur = 0;
    	tmp[i+1] = 1;
    	mi summ = 1;
    	if (i >= 3) {
	    	int xx = a[i - 3] * 8 + a[i - 2] * 4 + a[i - 1] * 2 + a[i];
	    	if (xx == 3 || xx == 5 || xx == 14 || xx == 15) {
				flag[i-3] = 1;
			}
    	}
    	for (int j = i; j >= 0; j--) {
    		cur = cur * pm + a[j];
    		auto it = vm[i - j + 1].find_ptr(cur);
    		mi ans = summ;
    		if (it == nullptr) {
    			if (flag[j]) ans -= tmp[j+4];
    			vm[i-j+1].emplace_if_absent(cur, (int) ans);
    			tot += ans;
    		} else {
    			ans = *it;
    		}
			summ += ans;
			if (j + 4 <= i + 1) summ -= tmp[j+4];
    		tmp[j] = ans;
    	}
    	cout << (int) tot << '\n';
    }
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
