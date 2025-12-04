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
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
int maxM = 7e5+5;
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
void comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
    
}
void solve() {
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == '?' ? 2 : s[i] - '0');
    }
    vi Z(n + 1);
    vi O(n + 1);
    vi U(n + 1);
    for (int i = 0; i < n; i++) {
        Z[i + 1] = Z[i] + (a[i] == 0);
        O[i + 1] = O[i] + (a[i] == 1);
        U[i+1] = U[i] + (a[i] == 2);
    }
    mi ans = 0;

    vi V(k - 1, 2);
    int z = 0;
    int o = 0;
    int u = k - 1;
    auto change = [&] (int i, int v) {
        if (v == 2 && V[i] < 2) return;
        if (V[i] == 0) {
            z--;
        } else if (V[i] == 1) {
            o--;
        } else {
            u--;
        }
        V[i] = v;
        if (V[i] == 0) {
            z++;
        } else if (V[i] == 1) {
            o++;
        } else {
            u++;
        }
    };
    vi vo(n+1), vz(n+1), vu(n+1, k - 1), last(n + 1, 2);
    for (int i = n - 1; i >= 0; i--) {
        if (vu[i + 1] == -1 || (a[i] < 2 && V[i % (k - 1)] < 2 && a[i] != V[i % (k - 1)])) {
            vo[i] = vz[i] = vu[i] = last[i] = -1;
        } else {
            change(i % (k - 1), a[i]);
            vo[i] = o;
            vz[i] = z;
            vu[i] = u;
            last[i] = V[(i + k - 2) % (k - 1)];
        }
    }
    for (int i = 1; i <= n - k; i++) {
        if (O[i] == 0 && a[i] != 0 && vu[i+1] != -1) {
            //cout << i << " " << vu[i+1] << " " << vo[i+1] << endl;
            if (last[i+1] == 2) {
                vu[i+1]--;
                vo[i+1]++;
            }
            if (last[i+1] != 0) {
                ans += ncr(vu[i + 1], k / 2 - vo[i + 1]);
                if (last[i+1] == 2) {
                    vu[i+1]++;
                    vo[i+1]--;
                }
            }
            
        }
        if (Z[i] == 0 && a[i] != 1 && vu[i+1] != -1) {
            if (last[i+1] == 2) {
                vu[i+1]--;
                vz[i+1]++;
            }
            if (last[i+1] != 1) {
                ans += ncr(vu[i + 1], k / 2 - vz[i + 1]);
                if (last[i+1] == 2) {
                    vu[i+1]++;
                    vz[i+1]--;
                }
            }
        }
        // cout << i << " " <<(int) ans << " " << last[i+1] << endl;
        // cout << i << " " << vu[i+1]<< " " << vo[i+1] << endl;
    }
    if (Z[n - k + 1] == 0) {
        for (int i = k / 2; i < k; i++) {
            int OO = O[n] - O[n - k + 1];
            ans += ncr(U[n] - U[n - k + 1], i - OO);
        }
    }
    if (O[n - k + 1] == 0) {
        for (int i = k / 2; i < k; i++) {
            int ZZ = Z[n] - Z[n - k + 1];
            ans += ncr(U[n] - U[n - k + 1], i - ZZ);
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
