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
void solve() {
    vector<string> C(5);
    vi used(52);
    vi cnt(13);
    map<string, int> ma;
    vi p(13);
    vector<string> ch(13);
    for (int i = 0; i < 13; i++) {
        ch[i] += ('0' + i + 1);
    }
    ch[0] = "A";
    ch[9] = "10";
    ch[10] = "J";
    ch[11] = "Q";
    ch[12] = "K";
    for (int i = 0; i < 13; i++) {
        ma[ch[i]] = i;
    }
    vi suff(6);
    vi vec;
    for (int i = 0; i < 5; i++) {
        cin >> C[i];
        int t = ma[C[i]];
        used[4 * t + cnt[t]] = 1;
        cnt[t]++;
        vec.push_back(t+1);
    }
    sort(vec.begin(), vec.end());
    for (int i = 4; i >= 0; i --) {
        suff[i] = suff[i+1] + vec[i];
    }
    vector<vector<vector<vector<mi>>>> dp(66, vector<vector<vector<mi>>>(6, vector<vector<mi>>(66, vector<mi>(6))));
    dp[0][0][0][0] = 1;
    for (int i = 0; i < 52; i++) {
        if (used[i]) continue;
        int val = i / 4 + 1;
        for (int z = 4; z >= 0; z--) {
            for (int w = 5; w >= 0; w--) {
                for (int x = 65; x >= 0; x--) {
                    for (int y = 65; y >= 0; y--) {
                        if (x >= val && z) dp[x][z][y][w] += dp[x - val][z-1][y][w]; 
                        if (y >= val && w) dp[x][z][y][w] += dp[x][z][y-val][w-1];
                    }
                }
            }
        }
    }
    vector<mi> ans(6);
    for (int i = 1; i <= 4; i++) {
        mi L = 0;
        mi R = 0;
        mi tot = 0;
        for (int x = 0; x <= 65; x++) {
            for (int y = 0; y <= 65; y++) {
                if (x + suff[i] > y) L += dp[x][i][y][5];
                if (x + suff[i] < y) R += dp[x][i][y][5];
                tot += dp[x][i][y][5];
            }
        }
        mi itot = inv(tot);
        ans[i] += L * i * itot - R * i * itot;
    }    
    for (int i = 1; i <= 5; i++) {
        cout << (int) ans[i] << endl;
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
