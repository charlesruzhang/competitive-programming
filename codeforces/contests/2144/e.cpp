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
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    int maxx = 0;
    int l = -1;
    int r = -1;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (a[i] > maxx) {
    		maxx = a[i];
    		l = i;
    		r = i;
    	} else if (a[i] == maxx) {
    		r = i;
    	}
    }
    int mx = 0;
    vi v, w;
    for (int i = 0; i < n; i++) {
    	if (a[i] > mx) {
    		mx = a[i];
    		v.push_back(a[i]);
    	}
    }
    mx = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (a[i] > mx) {
    		mx = a[i];
    		w.push_back(a[i]);
    	}
    }
    vector<mi> dp(n, 1);
    int x = v.size();
    vvi e(x);
    for (int i = 0; i < x; i++) {
    	for (int j = 0; j < n; j++) {
    		if (a[j] == v[i]) {
    			e[i].push_back(j);
    		}
    	}
    }
    for (int i = 0; i < x; i++) {
    	int idx = 0;
    	mi tot = 0;
    	for (int j = 0; j < n; j++) {
    		if (a[j] <= v[i]) {
    			tot *= 2;
    		}
    		if (idx < e[i].size() && e[i][idx] == j) {
    			tot += dp[j];
    			idx++;
    		} else if (i != x - 1 && a[j] == v[i+1]) {
    			dp[j] = tot;
    		}
    	}
    }
    vector<mi> dp2(n, 1);
    int y = w.size();
    vvi f(y);

    for (int i = 0; i < y; i++) {
    	for (int j = n - 1; j >= 0; j--) {
    		if (a[j] == w[i]) {
    			f[i].push_back(j);
    		}
    	}
    }
    for (int i = 0; i < y; i++) {
    	int idx = 0;
    	mi tot = 0;
    	for (int j = n - 1; j >= 0; j--) {
    		if (a[j] <= w[i]) {
    			tot *= 2;
    		}
    		if (idx < f[i].size() && f[i][idx] == j) {
    			tot += dp2[j];
    			idx++;
    		} else if (i != y - 1 && a[j] == w[i+1]) {
    			dp2[j] = tot;
    		}
    	}
    }
    mi ans = 0;
    for (int i = 0; i < e[x-1].size(); i++) {
    	for (int j = i; j < e[x-1].size(); j++) {
    		int first = e[x-1][i];
    		int second = e[x-1][j];
    		ans += dp[first] * dp2[second] * powMod(2, second - first - 1);
    		//cout << first << " " << second << " " << (int) dp[first] << " " << (int) dp2[second] << endl;
    	}
    }
    cout << (int) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
