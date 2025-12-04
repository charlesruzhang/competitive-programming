#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nh = 2;
const int maxn = 5555;

int n;
char a[maxn];

ll qpow(ll x, ll k, ll mod) {
    ll ans = 1;

    for (; k; k >>= 1, x = x * x % mod)
        if (k & 1) ans = ans * x % mod;

    return ans;
}

struct Hash {
    ll h[maxn][nh], inv[maxn][nh], mods[nh] = {(ll) 1e9 + 7, (ll) 1e9 + 9}, primes[nh] = {131, 137};

    void init_hash() {
        for (int i = 0; i < nh; i++) {
            ll p = 1, invp = qpow(primes[i], mods[i] - 2, mods[i]);

            h[0][i] = 0, inv[0][i] = 1;

            for (int j = 1; j <= n; j++) {
                p = p * primes[i] % mods[i];
                inv[j][i] = inv[j - 1][i] * invp % mods[i];
                h[j][i] = (h[j - 1][i] + p * a[j - 1] % mods[i]) % mods[i];
            }
        }
    }

    ll get_hash(int l, int r, int i) {
        ll sum = (h[r][i] - h[l - 1][i] + mods[i]) % mods[i];

        return sum * inv[l - 1][i] % mods[i];
    }
} h;

bool equals(int l1, int r1, int l2, int r2) {
    for (int i = 0; i < nh; i++)
        if (h.get_hash(l1, r1, i) != h.get_hash(l2, r2, i)) return 0;

    return 1;
}

int main() {
    scanf("%s", &a);
    n = strlen(a);

    h.init_hash();

    int ans = INT_MAX;

    for (int l = 1; l <= n; l++) {
        map<pair<ll, ll>, pair<int, int>> m;

        for (int i = 1; i + l - 1 <= n; i++) {
            pair<ll, ll> sh = {h.get_hash(i, i + l - 1, 0), h.get_hash(i, i + l - 1, 1)};

            if (m.find(sh) == m.end()) m[sh] = {i, 1};
            else if (m[sh].first <= i - l) m[sh].first = i, m[sh].second++;
        }

        for (auto [k, v] : m) {
            ans = min(ans, l + n - (l - 1) * v.second);
        }
    }

    printf("%d\n", ans);
}