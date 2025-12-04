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
const int MOD = 998244353;
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
    vector<string> s(n);
    vi l, r, p;
    vi val, tot;
    vector<mi> yes, no;
    l.push_back(-1);
    r.push_back(-1);
    p.push_back(-1);
    val.push_back(0);
    yes.push_back(mi(0));
    no.push_back(mi(0));
    tot.push_back(0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
    mi prev = 0;
    for (int i = 0; i < n; i++) {
    	int cur = 0;
    	for (int j = 0; j < s[i].size(); j++) {
    		int z = (s[i][j] == 'A') ? 0 : 1;
    		if (!z) {
    			if (l[cur] == -1) {
    				l[cur] = ++cnt;
    				l.push_back(-1);
    				r.push_back(-1);
    				p.push_back(cur);
				    val.push_back(0);
				    yes.push_back(mi(0));
				    no.push_back(mi(0));
				    tot.push_back(0);
    			}
    			cur = l[cur];
    		} else {
				if (r[cur] == -1) {
    				r[cur] = ++cnt;
    				r.push_back(-1);
    				l.push_back(-1);
    				p.push_back(cur);
				    val.push_back(0);
				    yes.push_back(mi(0));
				    no.push_back(mi(0));
				    tot.push_back(0);
    			}
    			cur = r[cur];
    		}
    	}
    	val[cur]+=1;
    	mi ans = 0;
    	while (cur != -1) {

    		int tl = (l[cur] == -1) ? 0 : tot[l[cur]];
    		int tr = (r[cur] == -1) ? 0 : tot[r[cur]];
    		tot[cur] = val[cur] + tl + tr;
    		mi left = (l[cur] == -1) ? 0 : yes[l[cur]];
    		mi right = (r[cur] == -1) ? 0 : yes[r[cur]];
    		mi nl = (l[cur] == -1) ? 1 : no[l[cur]];
    		mi nr = (r[cur] == -1) ? 1 : no[r[cur]];
    		no[cur] = nl * nr + left * nr + right * nl; 

    		yes[cur] = powMod(2, tot[cur]) - no[cur];

    		cur = p[cur];
    	}
    	ans += yes[0];
    	cout << (int) ans << endl;
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
