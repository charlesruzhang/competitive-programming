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
    int n, m, p;
    cin >> n >> m >> p;

    MOD = p;

	mi im = inv(m);
	mi i2 = inv(2);
	mi im2 = im * im;

	vector<mi> P(n + 1, 1);
	vector<mi> Q(n + 1, 1);
	vector<mi> I1(n + 1, 1);
	vector<mi> I2(n + 1, 1);
	vector<mi> IIM(n + 1);

	for (int i = 1; i <= n; i++) {
		P[i] = P[i - 1] * im;
		Q[i] = Q[i - 1] * im2;
	}

	for (int i = 1; i <= n; i++) {
		I1[i] = I1[i - 1] + P[i];     // im^i
		I2[i] = I2[i - 1] + Q[i];     // im2^i
		IIM[i] = IIM[i - 1] + P[i] * i; // i * im^i
	}

	mi X = 0, Y = 0;
	for (int i = 1; i <= n; i++) {
		X += P[i / 2] * (n - i + 1);
		Y += Q[i / 2] * (n - i + 1);
	}

	mi ans = X * X + X - Y;

	for (int i = 1; i <= n; i++) {
		int x = min(i - 1, n - i);
		ans += 2 * IIM[x] - I1[x] * I1[x] + I2[x];
		//cout << i << " ? " << (int) ans << endl;
		x = min(i - 1, n - i - 1);
		if (i != n) ans += 2 * im * IIM[x] - (I1[x+1] - 1) * (I1[x+1] - 1) + I2[x+1] - 1;
		//cout << i << " ! " << (int) ans << endl;
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
