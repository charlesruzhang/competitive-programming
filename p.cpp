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
    while (scanf("%d %d",&n, &m) != EOF){
        int summ = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            summ += x;
        }

        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            summ -= x;
        }
        printf("%d\n",summ);
    }

    return 0;
}

signed main() {
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
