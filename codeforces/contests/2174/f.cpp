#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int INV2 = 500000004; // (MOD+1)/2

long long mod_pow(long long a, long long e) {
    a %= MOD;
    if (a < 0) a += MOD;
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<int> mask(m + 1);
        for (int i = 1; i <= m; i++) cin >> mask[i];

        // Count vertices per color
        vector<int> s(m + 1, 0);
        for (int x : c) s[x]++;

        // n == 1: only one node, degree sum for every color is 0 => all masks must be 0
        if (n == 1) {
            bool ok = true;
            for (int i = 1; i <= m; i++) if (mask[i] != 0) ok = false;
            cout << (ok ? 1 : 0) << "\n";
            continue;
        }

        int L = n - 2;

        // Build list of (si, coef) for colors with si>0.
        // coef = (-1)^{r_i} for the "negative" term y^{-si}
        vector<pair<int,int>> items;
        items.reserve(min(m, n));
        for (int i = 1; i <= m; i++) {
            int si = s[i];
            int ri = mask[i] ^ (si & 1);
            if (si == 0) {
                // then t_i must be 0 -> require ri==0 else impossible
                if (ri == 1) { items.clear(); break; }
                continue;
            }
            int coef = (ri ? MOD - 1 : 1); // -1 or +1 mod MOD
            items.push_back({si, coef});
        }
        if (items.empty() && n > 1) {
            // Could be either "impossible" (we cleared) or "all si==0" (can't when n>1).
            // Detect impossible: if any si==0 with mask mismatch we would have broken.
            // If items is empty here, it means n>1 but no positive colors => impossible input, but ignore.
        }

        // If we broke due to impossible unused color with mask=1
        bool impossible = false;
        for (int i = 1; i <= m; i++) {
            if (s[i] == 0 && mask[i] == 1) { impossible = true; break; }
        }
        if (impossible) {
            cout << 0 << "\n";
            continue;
        }

        int k = (int)items.size();
        int OFF = n;
        int SZ = 2 * n + 1;

        vector<int> dp(SZ, 0), ndp(SZ, 0);
        dp[OFF] = 1;
        int cur = 0; // current max |A| reachable = sum processed si

        for (auto [si, coef] : items) {
            int newcur = cur + si;
            int left = OFF - cur, right = OFF + cur;
            // Fill exactly the new range; no need to clear the whole array.
            for (int idx = OFF - newcur; idx <= OFF + newcur; idx++) {
                long long val = 0;
                int idx1 = idx - si; // corresponds to choosing +si
                if (idx1 >= left && idx1 <= right) val += dp[idx1];
                int idx2 = idx + si; // corresponds to choosing -si
                if (idx2 >= left && idx2 <= right) {
                    if (coef == 1) val += dp[idx2];
                    else val += (MOD - dp[idx2]); // subtract
                }
                val %= MOD;
                ndp[idx] = (int)val;
            }
            // swap dp/ndp; dp outside range won't be read due to bounds checks
            dp.swap(ndp);
            cur = newcur;
        }

        long long S = 0;
        for (int idx = OFF - cur; idx <= OFF + cur; idx++) {
            int A = idx - OFF; // can be negative
            long long base = A % MOD;
            if (base < 0) base += MOD;
            long long p = mod_pow(base, L); // handles 0^0 as 1 when L=0
            S = (S + 1LL * dp[idx] * p) % MOD;
        }

        long long ans = S * mod_pow(INV2, k) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
