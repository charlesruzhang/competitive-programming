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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&] (int m) {
        vi d(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int target = max(0, i - n + m);
            int cur = a[i] + i - cnt;
            if (target > i - cnt) {
                return false;
            }
            int last = cur - target + i;
            if (last < n) {
                d[last]++;
            }
            cnt += d[i];
        }
        return true;
    };
    int l = 1;
    int r = n;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
