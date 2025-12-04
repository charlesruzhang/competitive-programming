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
    vi d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vi left(n), right(n);
    for (int i = 0; i < n; i++) {
        cin >> left[i] >> right[i];
    }
    vi l(n + 1), r(n + 1);
    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            if (l[i] + d[i] > right[i] || r[i] + d[i] < left[i]) {
                cout << "-1" << endl;
                return;
            }
        } else {
            if (l[i] > right[i] || r[i] + 1 < left[i]) {
                cout << "-1" << endl;
                return;
            }
        }
        if (d[i] == -1) {
            l[i+1] = max(l[i], left[i]);
            r[i+1] = min(r[i] + 1, right[i]);
        } else {
            l[i+1] = max(l[i] + d[i], left[i]);
            r[i+1] = min(r[i] + d[i], right[i]);
        }
    }
    vi ans(n+1);
    int cur = r[n];
    for (int i = n - 1; i >= 0; i--) {
        if (d[i] == -1) {
            ans[i] = max(0, cur - r[i]);
        } else {
            ans[i] = d[i];
        }
        cur -= ans[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout <<  endl;
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
