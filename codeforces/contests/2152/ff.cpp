#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    const int LOG = 20; // enough for n <= 2.5e5
    while (T--) {
        int n; long long z;
        cin >> n >> z;
        vector<long long> x(n+1);
        for (int i = 1; i <= n; ++i) cin >> x[i];

        // bad[i] = 1 if x[i+2] - x[i] <= z
        vector<int> B;
        if (n >= 3) {
            for (int i = 1; i <= n-2; ++i) {
                if (x[i+2] - x[i] <= z) B.push_back(i);
            }
        }
        int M = (int)B.size();

        // nxt[t] = first index in B with value >= B[t] + 3
        vector<int> nxt(M, M);
        for (int t = 0; t < M; ++t) {
            int target = B[t] + 3;
            int j = int(lower_bound(B.begin(), B.end(), target) - B.begin());
            nxt[t] = j;
        }

        // binary lifting over positions in B
        vector<array<int, LOG>> up(max(1, M)); // avoid 0-sized array
        if (M > 0) {
            for (int t = 0; t < M; ++t) up[t][0] = nxt[t];
            for (int k = 1; k < LOG; ++k) {
                for (int t = 0; t < M; ++t) {
                    int mid = up[t][k-1];
                    up[t][k] = (mid < M ? up[mid][k-1] : M);
                }
            }
        }

        auto deletions_in_range = [&](int l, int r)->int {
            if (r - l + 1 <= 2) return 0;
            if (M == 0) return 0;
            int t0 = int(lower_bound(B.begin(), B.end(), l) - B.begin());
            if (t0 >= M || B[t0] > r-2) return 0;
            int cnt = 1, cur = t0; // take B[cur] (delete at B[cur]+2)
            for (int k = LOG-1; k >= 0; --k) {
                int nx = up[cur][k];
                if (nx < M && B[nx] <= r-2) {
                    cur = nx;
                    cnt += 1<<k;
                }
            }
            return cnt;
        };

        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r;
            int del = deletions_in_range(l, r);
            cout << (r - l + 1) - del << '\n';
        }
    }
    return 0;
}
