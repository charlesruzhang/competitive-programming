#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const ll MOD = 998244353;
const ll MAXX = 1000000;
const ld EPS = 1e-9;
vi vv;
ll solve() {
    int cur = 1000002 / 2;
    int l = 1;
    int r = 1000000;
    while (l < r) {
        printf("%d\n", cur);
        fflush(stdout);
        string s;
        cin >> s;
        if (s == ">=") {
            l = cur;
        } else {
            r = cur-1;
        }
        cur = (l + r + 1) / 2;
    }
    printf("! %d\n", cur);
    fflush(stdout);
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
