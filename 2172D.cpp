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
void solve() {
    int n, m;
    cin >> n >> m;
    vl a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<mi> iv(2 * n);
    for (int i = 1; i <= n; i++) {
    	iv[i] = inv(i);
    }
    vector<pll> V;
    vector<vector<mi>> dp(n, vector<mi>(n + 1));
    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
    }
    vi mark(n);
    vector<mi> ans(m + 1);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    	if (b[i]) ans[b[i]]+=1, mark[i] = 1;
    	if (b[i] == 0) {
    		V.push_back({a[i], i});
    	}
    }
    for (auto [x, idx]: V) {
        for (int i = idx + 1; i < n; i++) {
            if (a[i] % x) continue;
            if (b[i]) {
                mark[idx] = 1;
                break;
            }
        }
    }
    for (auto [x, idx]: V) {
        int cnt = 0;
        for (int i = idx + 1; i < n; i++) {
            if (a[i] % x) continue;
            if (!mark[i]) continue;
            if (b[i]) {
                for (int j = 1; j <= n; j++) {
                    ans[b[i]] += dp[idx][j] * iv[j + cnt] * j;
                }
                break;
            }
            for (int j = 1; j + cnt + 1 <= n; j++) {
                mi P = j * iv[j + cnt] * iv[j + cnt + 1];
                dp[i][j + cnt + 1] += P * dp[idx][j];
            }
            cnt++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << (int) ans[i] << " ";
    }
    cout << endl;
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
