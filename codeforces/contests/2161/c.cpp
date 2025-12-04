// By Auchenai01
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
const int INF = 1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    vi ans;
    ll tot = 0;
    ll A = 0;
    while (l <= r) {
        if (tot + a[r] >= x) {
            ans.push_back(a[r]);
            A += a[r];
            tot = (tot + a[r]) % x;
            r--;
        } else {
            ans.push_back(a[l]);
            tot = (tot + a[l]);
            l++;
        }
    }
    cout << A << endl;
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
