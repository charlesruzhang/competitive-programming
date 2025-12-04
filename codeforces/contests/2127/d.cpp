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
int maxM = 2e5+5;
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
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
}
void solve() {
    int n, m;
    cin >> n >> m;
    vvi e(n);
    vector<pii> vec;
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    	vec.push_back({u, v});
    }
    vi mark(n);
    for (int i = 0; i < n; i++) {
    	if (e[i].size() >= 2) {
    		mark[i] = 1;
    	}
    }
    vi cnt(n);
    for (auto [u, v] : vec) {
    	if (mark[u] && mark[v]) {
    		cnt[u] ++;
    		cnt[v]++;
    	}
    }
    int c2 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
    	if (cnt[i] == 2) {
    		c2++;
    	} else if (cnt[i] == 1) {
    		c1++;
    	} else if (cnt[i] >= 3) {
    		cout << 0 << endl;
    		return;
    	}
    }
    if (c2 > 0 && c1 != 2) {
    	cout << 0 << endl;
    	return;
    }
    vi cnt2(n);
    for (int i = 0; i < n; i++) {
    	if (e[i].size() == 1) {
    		int v = e[i][0];
    		cnt2[v]++;
    	}
    }
    mi ans = 4;
    if (c1 <= 1) ans = 2;
    for (int i = 0; i < n; i++) {
    	ans *= fact[cnt2[i]];
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
