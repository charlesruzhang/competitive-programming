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
    stack<pii> us;
    stack<pii> ds;
    int invalid = 0;
    ll ans = n;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            while (!us.empty() && us.top().first > a[i]) {
                invalid = max(invalid, us.top().second);
                while (!us.empty()) {
                    us.pop();
                }
            }
            us.push({a[i], i});
        } else {
            while (!ds.empty() && ds.top().first < a[i]) {
                invalid = max(invalid, ds.top().second);
                while (!ds.empty()) {
                    ds.pop();
                }
            }
            ds.push({a[i], i});
        }
        ans += i - invalid;
    }
    cout << ans << endl;
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
