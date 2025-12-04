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
    multiset<int, greater<>> s;
    vi ans(n);
    s.insert(a[0]);
    for (int i = 1; i < n; i++) {
        auto it = s.begin();
        if (a[i] > *it) {
            int z = *it;
            if (z + a[i] % z == a[i]) {
                ans[i] = a[i];
            } else {
                while (it != s.end() && *it > z / 2) {
                    ans[i] = max(ans[i], a[i] % (*it) + (*it) % a[i]);
                    ++it;
                }
            }
        } else {
            ans[i] = max(ans[i-1], a[i] % (*it) + (*it) % a[i]);
        }
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
