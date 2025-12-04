// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll mod = 1e9+7;
const ll MOD = 1E9 + 7;
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
ll bigmod(ll a, ll p){
	ll ret = 1;
	while(p){
		if(p&1) ret = ret * a % mod;
		a = a * a % mod;
		p /= 2;
	}
	return ret;
}
vector<mi> dp(30);
vector<mi> prod(30);
vector<int> cnt(30);
vector<ll> pref(30);
void comp() {
	cnt[1] = pref[1] = 1; prod[1] = dp[1] = mi(1);
	for (int i = 2; i < 30; i++) { 
		cnt[i] = pref[i-1] + 1;
		pref[i] = pref[i-1] + cnt[i];
	}
	for (int i = 2; i < 30; i++) {
		dp[i] = mi(i) * prod[i-1];
		prod[i] = prod[i-1] * dp[i]; 
	}
}
void solve() {
	int n, k;
	cin >> n >> k;
	vi s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	int tot = k;
	mi ans = 1;
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		st.push(s[i]);
	}
	while (tot > 0) {
		int cur = st.top();
		st.pop();
		if (cur < 30 && tot > cnt[cur]) {
			ans *= dp[cur];
			tot -= cnt[cur];
		} else {
			for (int j = min(cur - 1, 30); j>= 1; j--) {
				st.push(j);
			}
			ans *= cur;
			tot--;
		}
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
