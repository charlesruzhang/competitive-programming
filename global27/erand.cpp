#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

struct Solver {
    static i64 ceil_div(i128 a, i128 b) {
        if (b < 0) a = -a, b = -b;
        if (a >= 0) return (i64)((a + b - 1) / b);
        return (i64)(a / b); // a<0: floor; but we only use with nonnegatives here
    }

    static i128 dmg_for(i64 U, i64 T, i64 k) {
        // U upgrades, front-loaded across T blocks with cap k each
        i64 q = min(T, U / k);
        i64 r = U - q * k;
        if (q == T) r = 0;
        // dmg = k * q*(2T - q + 1)/2 + r*(T - q)
        i128 term1 = (i128)k * (i128)q * ( (i128)2*T - q + 1 ) / 2;
        i128 term2 = (i128)r * ( (i128)T - q );
        return term1 + term2;
    }

    static i128 max_dmg_T(i64 T, i64 k) {
        // k * T*(T+1)/2
        return (i128)k * (i128)T * ( (i128)T + 1 ) / 2;
    }

    static i128 cost_for_T(i64 T, i64 z, i64 x, i64 y, i64 k) {
        if (T <= 0) return (i128)4e36; // huge
        if (max_dmg_T(T, k) < (i128)z) return (i128)4e36; // infeasible
        // binary search minimal U in [0, T*k] with dmg >= z
        i64 lo = 0, hi = min( (i128)T * k, (i128)z ); // never need more than z upgrades
        while (lo < hi) {
            i64 mid = lo + ( (hi - lo) >> 1 );
            if (dmg_for(mid, T, k) >= (i128)z) hi = mid;
            else lo = mid + 1;
        }
        i128 U = lo;
        return (i128)x * U + (i128)y * T;
    }

    static i64 solve_one(i64 z, i64 x, i64 y, i64 k) {
        // Edge cases
        if (z <= 0) return 0;
        if (k == 0) return -1; // cannot upgrade -> damage always 0 -> impossible

        // Ternary search over T in [1, z]
        i64 L = 1, R = z; // upper bound: 1 upgrade then z attacks costs x + y*z
        // Optional: push L up to a feasible lower bound
        auto feasible = [&](i64 T){ return max_dmg_T(T, k) >= (i128)z; };
        // enlarge L until feasible? Not needed for ternary; infeasible T returns huge

        while (R - L > 6) {
            i64 m1 = L + (R - L) / 3;
            i64 m2 = R - (R - L) / 3;
            i128 c1 = cost_for_T(m1, z, x, y, k);
            i128 c2 = cost_for_T(m2, z, x, y, k);
            if (c1 <= c2) R = m2 - 1;
            else L = m1 + 1;
        }
        i128 best = (i128)4e36;
        for (i64 T = L; T <= R; ++T) {
            best = min(best, cost_for_T(T, z, x, y, k));
        }
        if (best > (i128)3e36) return -1;
        return (i64)best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Tcs = 1;
    if (!(cin >> Tcs)) return 0;
    while (Tcs--) {
        long long z, x, y, k;
        cin >> z >> x >> y >> k;
        cout << Solver::solve_one(z, x, y, k) << '\n';
    }
    return 0;
}
