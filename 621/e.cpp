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
const ll MOD = 1e9 + 7;
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
void solve() {
	int maxM = 1e4+5;
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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi vs(5001);
    vector<pii> b(n);
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	vs[x].push_back(y);
    	b[i] = {x, y};
    }
    vvi counter(5001);
    for (int i = 0; i < n; i++) {
    	counter[a[i]].push_back(i);
    }
    for (int i = 1; i <= 5000; i++) {
    	sort(vs[i].begin(), vs[i].end());
    }
    vi best(m);
    vi best2(m);
    vi flag(m), flag2(m);
    vector<mi> ans(m, 1);
    vector<mi> ans2(m, 1);
    for (int j = 1; j <= 5000; j++) {
    	vi pref(n+1);
    	for (int i = 0; i < n; i++) {
    		pref[i+1] = pref[i] + ((a[i] == j) ? 1 : 0);
    	}
    	vi pref2(5001);
    	int t = 1;
    	int idx = 0;
    	while (t <= 5000) {
    		if (idx < vs[j].size() && vs[j][idx] == t) {
    			pref2[t] = pref2[t-1] + 1;
    			idx++;
    		} else {
    			pref2[t] = pref2[t-1];
    		}
    		t++;
    		if (pref2[t]) {
    			cout << pref2[t] << " " << t << endl;
    		}
    	}

    	for (int i = 0; i < m; i++) {
	    	auto [x, y] = b[i];
	    	if (counter[x].size() < y) {
	    		best[i] -= 1e5;
	    		continue;
	    	}
		    int l = counter[x][y-1];
	    	if (x != j) {
		    	int z = pref2[pref[l+1]];
		    	int w = pref2[pref[n] - pref[l+1]];
		    	if (max(z, w) == 1) {
		    		best[i]++;
		    		int tot = 0;
		    		if (z == 1) tot++;
		    		if (w == 1) tot++;
		    		ans[i] *= tot;
		    	} else if (max(z, w) == 0) {
		    		continue;
		    	} else {
		    		if (z > w) swap(z, w);
		    		if (z == 0) {
		    			best[i]++;
		    		} else {
		    			best[i]+=2;
		    			ans[i] *= z * (w - 1);
		    			flag[i] = 1;
		    		}
		    	}
	    	} else {
		    	int w = pref2[pref[n] - pref[l+1]];
		    	if (y <= pref[n] - pref[l+1]) {
		    		w--;
		    	}
		    	if (w == 0) {
		    		best[i]++;
		    	} else {
		    		best[i]+=2;
		    		ans[i] *= w;
		    		flag[i] = 1;
		    	}
	    	}
	    }
	    for (int i = 0; i < m; i++) {
	    	auto [x, y] = b[i];
	    	if (counter[x].size() < y) {
	    		best2[i] -= 1e5;
	    		continue;
	    	}
	    	int r = counter[x][counter[x].size() - y];
	    	if (x != j) {
		    	int z = pref2[pref[r+1]];
		    	int w = pref2[pref[n] - pref[r+1]];
		    	if (z) flag2[i] = 1;
		    	if (max(z, w) == 1) {
		    		best2[i]++;
		    		int tot = 0;
		    		if (z == 1) tot++;
		    		if (w == 1) tot++;
		    		ans2[i] *= tot;
		    	} else if (max(z, w) == 0) {
		    		continue;
		    	} else {
		    		if (z > w) swap(z, w);
		    		if (z == 0) {
		    			best2[i]++;
		    		} else {
		    			best2[i]+=2;
		    			ans2[i] *= z * (w - 1);
		    		}
		    	}
	    	} else {
	    		int w = pref2[pref[r]];
		    	if (y <= pref[r]) {
		    		w--;
		    	}
		    	if (w == 0) {
		    		best2[i]++;
		    	} else {
		    		best2[i]+=2;
		    		ans2[i] *= w;
		    		flag2[i] = 1;
		    	}
	    	}	
	    }
    }
    int maxx = 0;
    mi res = 1;
    for (int i = 0; i < m; i++) {
    	cout << i << " " << best[i] << " " << flag[i] << " " << (int) ans[i] << endl;
    	if (best[i] > maxx) {
    		maxx = best[i];
    		if (flag[i]) {
    			res = ans[i] / 2;
    		} else {
    			res = ans[i];
    		}
    	} else if (best[i] == maxx) {
    		if (flag[i]) {
    			res += ans[i] / 2;
    		} else {
    			res += ans[i];
    		}
    	}
    }
    for (int i = 0; i < m; i++) {
    	cout << i << " " << best2[i] << " " << flag2[i] << " " << (int) ans2[i] << endl;
    	if (best2[i] > maxx) {
    		maxx = best2[i];
    		if (flag2[i]) {
    			res = ans2[i] / 2;
    		} else {
    			res = ans2[i];
    		}
    	} else if (best2[i] == maxx) {
    		if (flag2[i]) {
    			res += ans2[i] / 2;
    		} else {
    			res += ans2[i];
    		}
    	}
    }
    cout << maxx << " " << (int) res << endl;
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
