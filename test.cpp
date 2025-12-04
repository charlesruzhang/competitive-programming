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
int bit_length(unsigned long long x) {
    return x == 0 ? 0 : 64 - __builtin_clzll(x);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vl a(n);
    vl xorr(n+1);
    xorr[n] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<set<int,greater<int>>> g(32, set<int, greater<int>>());
    int maxb = 0;
    for (int i = n-1; i >= 0; i--) {
        xorr[i] = xorr[i+1] ^ a[i];
        int b = bit_length(a[i]);
        g[b].insert(i);
        maxb = max(maxb, b);
    }
    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        int b = bit_length(x);
        if (b > maxb) {
            cout << n << " ";
            continue;
        }
        int ans = n;
        int prevb = maxb;
        int curn = n;
        ll xii = x;
        while (b >= 0 && curn >= 0) {
            for (int i = prevb; i > b; i--) {
                auto it = g[i].lower_bound(curn);
                if (it == g[i].end()) {
                    continue;
                }
                int ff = *it;
                ans = min(ans, n - ff - 1);
            }
            if (b == 0) {
                break;
            }
            auto it = g[b].lower_bound(curn);
            if (it == g[b].end()) {
                break;
            }
            int ff = *it;
            ll xx = xorr[ff + 1] ^ xii;
            if (xx >= a[ff]) {
                x = xx ^ a[ff];
                curn = ff-1;
            } else {
                ans = min(ans, n-ff-1);
                break;
            }
            it++;
            if (it != g[b].end()) {
                int f2 = *it;
                ans = min(ans,n-f2-1);
            }
            prevb = b - 1;
            b = bit_length(x);
        }
        cout << ans << " ";
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