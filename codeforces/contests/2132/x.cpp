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
const int MOD = 1e9+7;
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
    mi result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}
int N = 2;
vector<vector<mi>> sq(vector<vector<mi>> M) {
    vector<vector<mi>> ans(N, vector<mi>(N, mi(0)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ans[i][j] += M[i][k] * M[k][j];
            }
        }
    }
    return ans;
}
vector<mi> mult(vector<vector<mi>> M, vector<mi> v) {
    vector<mi> ans(N, mi(0));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            ans[i]+= M[i][k] * v[k];
        }
    }
    return ans;
}
void solve() {
    int m, n;
    cin >> m >> n;
    N = m;
    vi s(m), l(m);
    for (int i = 0; i < m; i++) {
    	cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> l[i];
    }
    vector<vector<mi>> base(m, vector<mi>(m));
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < m; j++) {
    		base[i][j] = mi(s[i]) * l[j] + mi(s[j]) * l[i] + mi(s[i]) * s[j]; 
    	}
    }
    vector<mi> res(m);
    res[0] = 1;
    while (n > 0) {
        if (n & 1) res = mult(base, res);
        base = sq(base);
        n >>= 1;
    }
    mi ans = 0;
    for (int i = 0; i < m; i++) {
    	ans += res[i];
    }
    cout << (int) ans << endl;
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
