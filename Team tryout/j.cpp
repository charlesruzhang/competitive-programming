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
ll MOD = 998244353;
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
    int n, p;
    cin >> n >> p;
    MOD = p;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (n == 2) {
    	cout << 2 << endl;
    	return;
    }
    set<pii, greater<>> s;
    vi ans(n);
    for (int i = 0; i < n - 1; i++) {
    	mi q = a[i] * inv(a[i+1]);
    	mi cur = a[i];
    	int tot = 1;
    	int last = i;
    	while (1) {
    		cur *= q;
    		auto it = s.lower_bound({cur.v, n});
    		if (it -> first != cur.v || it -> second >= last) {
    			break;
    		} else {
    			if (last - 1 == it -> second) {
    				break;
    			}
    			last = it -> second;
    			tot++;
    		}
    	}
    	ans[i] += tot;
    	s.insert({a[i], i});
    }
    set<pii> s2;
    for (int i = 1; i < n; i++) {
    	s2.insert({a[i], i});
    }
    vi done(n);
    for (int i = 1; i < n; i++) {
    	if (done[i]) continue;
    	mi q = a[i] * inv(a[i-1]);
    	mi cur = a[i];
    	int tot = 1;
    	int last = i;
    	while (1) {
    		cur *= q;
    		auto it = s2.lower_bound({cur.v, -1});
    		if (it == s2.end() || it -> first != cur.v || it -> second <= last) {
    			break;
    		} else {
    			if (last + 1 == it -> second) {
    				done[last] = 1;
    			}
    			last = it -> second;
    			tot++;
    		}
    	}
    	ans[i-1] += tot;
    	s2.erase({a[i], i});
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
    	maxx = max(maxx, ans[i]);
    }
    mi x = a[0];
    mi y = a[2];
    mi z = y * inv(x);
    mi cur = y;
    int last = 2;
    int tot = 2;
    while (1) {
    	cur = cur * z;
    	auto it = s2.lower_bound({cur.v, n});
    	if (it == s2.end() || it -> first != cur.v || it -> second <= last) {
			break;
		} else {
			last = it -> second;
			tot++;
		}
    }
    maxx = max(maxx, tot);

    x = a[n - 1];
    y = a[n - 3];
    z = y * inv(x);
    cur = y;
    last = n - 3;
    tot = 2;
    while (1) {
    	cur = cur * z;
    	auto it = s.lower_bound({cur.v, -1});
    	if (it == s.end() || it -> first != cur.v || it -> second >= last) {
			break;
		} else {
			last = it -> second;
			tot++;
		}
    }
    maxx = max(maxx, tot);

    if (maxx >= (n + 1) / 2) {
    	cout << maxx << endl;
    } else {
    	cout << -1 << endl;
    }
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
