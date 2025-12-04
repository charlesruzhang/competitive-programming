#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
inline int mulmod(long long a, long long b) { return int((a * b) % MOD); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<uint32_t> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Problem guarantees Ai < 2^20, so we can fix B=20
    const int B = 20;
    const int lowBits = B / 2;          // 10
    const int highBits = B - lowBits;   // 10
    const int LO = 1 << lowBits;        // 1024
    const int HI = 1 << highBits;       // 1024

    // E[lo][H] flattened: idx = (H << lowBits) | lo
    vector<int> E(LO * HI, 1);
    auto idx = [&](int lo, int H) { return (H << lowBits) | lo; };

    for (int k = 0; k < N; ++k) {
        uint32_t m = A[k] & ((1u << B) - 1u);
        int lo = int(m & (LO - 1));
        int H0 = int(m >> lowBits);
        int val = int(A[k] % MOD);

        // Update: multiply into ALL supersets of H0 in this row,
        // done by scanning all masks and checking (H & H0) == H0.
        for (int H = 0; H < HI; ++H) {
            if ((H & H0) == H0) {
                E[idx(lo, H)] = mulmod(E[idx(lo, H)], val);
            }
        }

        // Query: product over all lo_sub ⊆ lo of E[lo_sub][H0],
        // done by scanning all masks and checking (lo & sub) == sub.
        long long ans = 1;
        for (int sub = 0; sub < LO; ++sub) {
            if ((sub & lo) == sub) {
                ans = (ans * E[idx(sub, H0)]) % MOD;
            }
        }

        cout << int(ans) << '\n';
    }
    return 0;
}
