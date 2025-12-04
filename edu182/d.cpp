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
    int n, k;
    cin >> n >> k;
    vi a(n);
    ll tot = 0;
    vi cnt(4e5+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
        cnt[a[i]]++;
    }
    vi pref(4e5+1);
    for (int i = 1; i <= 4e5; i++) {
        pref[i] = pref[i-1] + cnt[i];
    }
    ll ans = -1e18;
    for (int i = 2; i <= 2e5; i++) {
        int sz = 0;
        ll tot = 0;
        for (int j = i; j <= 2e5 + i; j+=i) {
            int c = pref[j] - pref[j - i];
            sz += min(c, cnt[j / i]);
            tot += 1ll * c * (j / i);
        }
        tot -= 1ll * (n - sz) * k;
        ans = max(ans, tot);
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
