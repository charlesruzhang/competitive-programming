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
using mi = long double;
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
    ll k;
    cin >> k;
    ll x = k;
    if (k == 1) {
        cout << "100 0"<< endl;
        return;
    } else if (k == 2) {
        cout << "0 100" << endl;
        return;
    }
    if (k >= 1e9) {
        cout << "33.333333333 66.666666666" << endl;
        return;
    }
    k-=2;
    vector<vector<mi>> base(2, vector<mi>(2, mi(0)));
    base[0][0] = 0.5;
    base[0][1] = 0.5;
    base[1][0] = 1;
    vector<mi> res(2);
    res[0] = 100;
    res[1] = 0;
    vector<vector<mi>> base2 = base;
    vector<mi> res2(2);
    res2[0] = 0;
    res2[1] = 100;
    while (k > 0) {
        if (k & 1) res = mult(base, res);
        base = sq(base);
        k >>= 1;
    }
    k = x - 2;
    while (k > 0) {
        if (k & 1) res2 = mult(base2, res2);
        base2 = sq(base2);
        k >>= 1;
    }
    cout << setprecision(10) << res2[0] << " " << res[0] << endl;
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
