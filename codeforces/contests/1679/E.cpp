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
    mi result(1);
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
    string s;
    cin >> s;
    int tq = 0;
    for (int i = 0 ; i < s.size(); i++) {
    	if (s[i] == '?') {
    		tq++;
    	}
    }
    int q;
    cin >> q;
    vector<vector<mi>> freq((1<<17), vector<mi>(18, mi(0)));
    for (int i = 0; i < n; i++) {
    	int j = 0;
    	int tot = 0;
    	int cur = 0;
    	int used = 0;
    	while ((i - j >= 0) && (i + j < n)) {
    		if (s[i-j] != '?' && s[i+j] != '?' && s[i-j] != s[i+j]) {
    			break;
    		} else if (s[i-j] == s[i+j] && s[i-j] == '?') {
    			tot++;
    			if (!j) used++;
    			else used+=2;
    		} else if (s[i-j] != s[i+j]) {
    			char ch = (s[i+j] == '?') ? s[i-j] : s[i+j];
    			int chh = ch - 'a';
    			cur |= (1 << chh);
    			used++;
    		}
    		j++;
    		for (int p = 1; p <= 17; p++) {
    			freq[cur][p] += powMod(mi(p), tot + (tq - used));
    		}
    	}
    	j = 0;
    	cur = 0;
    	tot = 0;
    	used = 0;
    	while ((i - j >= 0) && (i + 1 + j < n)) {
    		if (s[i-j] != '?' && s[i+j+1] != '?' && s[i-j] != s[i+j+1]) {
    			break;
    		} else if (s[i-j] == s[i+j+1] && s[i-j] == '?') {
    			tot++;
    			used+=2;
    		} else if (s[i-j] != s[i+j+1]) {
    			char ch = (s[i+j+1] == '?') ? s[i-j] : s[i+j+1];
    			int chh = ch - 'a';
    			cur |= (1 << chh);
    			used++;
    		}
    		j++;
    		for (int p = 1; p <= 17; p++) {
    			freq[cur][p] += powMod(mi(p), tot + (tq - used));
    		}
    	}
    }

    for (int j = 0; j < 17; j++) {
    	for (int i = 0; i < (1 << 17); i++) {
  			if (i & (1 << j)) {
	    		for (int p = 1; p <= 17; p++) {
	    			freq[i][p] += freq[i ^ (1 << j)][p];
	    		}
	    	}
    	}
    }
    while (q--) {
    	string dt;
    	cin >> dt;
    	int target = 0;
    	int M = dt.size();
    	for (char c: dt) {
    		int x = c - 'a';
    		target |= (1 << x);
    	}
    	cout << (int) freq[target][M] << endl;
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
