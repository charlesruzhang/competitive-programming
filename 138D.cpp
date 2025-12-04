#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int MAX = 11;
const vector<ll> fac = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200, 1307674368000};

ll solve() {
    ll n, m;
    cin >> n >> m;
    ll prev = m;
    vector<ll> p(n+1);
    p[0] = 1;
    ll ans = 1;
    for (int i = 1; i < n+1; ++i) {
        ans = (ans * m) % MOD;
        p[i] = ans;
    }
    ll summ = 0;
    for (int i = 2; i < n+1; ++i) {
        if (m < fac[i]) {
            for (int j = i; j < n+1; ++j) {
                summ = (summ + p[i]) % MOD;
            }
            break;
        }

        prev = prev * ((m-1) / fac[i] + 1) % MOD;
        summ = (summ + p[i] - prev) % MOD;
        cout << i << "i= " << summ << endl;
    }
    cout << summ << endl;
    return 0;
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
