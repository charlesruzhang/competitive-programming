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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<mi> p2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
    	p2[i] = p2[i-1] * 2;
    }
    sort(a.begin(), a.end());
    int z = 0;
    mi ans = 0;
    for (int i = 0; i < n; i++) {
    	int xx = i - 1;
    	while (xx >= 0 && a[xx] == a[i]) {
    		xx--;
    	}
    	int x = n - xx - 2; // greater or equal;
    	while (z < n && a[z] * 2 <= a[i]) {
    		z++;
    	}
    	// z = # of always smaller.
    	int y = n - x - z - 1;
    	int q = z - 1;
    	for (int j = z; j <= xx; j++) {
    		// tot = n - z - 2;
    		mi cnt = ncr(n - j - 2, m - 2 - (n - i - 1));
    		while (q >= 0 && a[q] + a[j] >= a[i]) {
    			q--;
    		}
    		ans += cnt * p2[q + 1];
    	}
    	//cout << i << " " << (int) ans << endl;
    }
    cout << (int) (p2[n] - ans) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    int c;
    // ifstream in("sale4.in");
    // ofstream out("sale4.out");
    cin >> c;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
