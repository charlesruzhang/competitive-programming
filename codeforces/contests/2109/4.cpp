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
vi mu;
vi small;
const int maxN = 2e5+1;
void sieve(ll &counter) {
    small.assign(maxN, 0);
    mu.assign(maxN, 0);

    vector<int> primes_list;
    mu[1] = 1;
    small[1] = 1;

    for (int i = 2; i < maxN; i++) {
        if (small[i] == 0) {
            small[i] = i;
            mu[i] = -1;
            primes_list.push_back(i);
        }
        for (int p : primes_list) {
            counter++;
            long long x = 1LL * i * p;
            if (x >= maxN) break;
            small[x] = p;
            if (i % p == 0) {
                mu[x] = 0;
                break;
            } else {
                mu[x] = -mu[i];
            }
        }
    }
}


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
    int n;
    cin >> n;
    vi a(n);
    ll counter = 0;

    sieve(counter);
    vector<int> freq(maxN), cnt(maxN);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int d = 1; d < maxN; d++) {
        for (int m = d; m < maxN; m += d) {
            cnt[d] += freq[m];
            counter++;
        }
    }
    vector<mi> p3(maxN, 1);
    vector<mi> p2(maxN, 1);
    for (int i = 1; i < maxN; i++) {
        p2[i] = p2[i-1] * 2;
        p3[i] = p3[i-1] * 3;
    }
    auto f = [&] (int g, int h, int z) {
        int cz = cnt[z];
        mi res = p3[cz] * p2[cnt[g] - cz] * p2[cnt[h] - cz];
        res -= p2[cnt[g]] * p2[cnt[h]];
        return res;
    };
    mi res = 0;
    mi summ = 0;
    for (int z = 1; z < maxN; z++) {
        vi s;
        int cur = z;
        while (cur != 1) {
            int x = small[cur];
            s.push_back(x);
            while (cur % x == 0) {
                counter++;
                cur /= x;
            }
        }
        for (int i = 0; i < (1 << (2 * s.size())); i++) {
            int g = z;
            int h = z;
            int q = z;
            for (int j = 0; j < s.size(); j++) {
                if ((1 << (2 * j + 1)) & i) {
                    if (!(1 << (2 * j) & i)) {
                        q /= s[j];
                    }
                } else {
                    q /= s[j];
                    if (!(1 << (2 * j) & i)) {
                        g /= s[j];
                    } else {
                        h /= s[j];
                    }
                }
                counter++;
            }
            res += q * mu[g / q] * mu[h / q] * f(g, h, z);
        }
    }
    for (int z = 1; z < maxN; z++) {
        mi summ = 0;
        for (int j = z; j < maxN; j += z) {
            counter++;
            summ += mu[j / z] * (p2[cnt[j]] - 1);
        }
        res += z * summ * summ;
    }
    cout << (int) res << endl;
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
