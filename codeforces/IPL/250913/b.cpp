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
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[min(k, a[i])]++;
    }
    vi pref(k+1);
    pref[k] = cnt[k];
    for (int i = k - 1; i >= 1; i--) {
    	pref[i] = pref[i+1] + cnt[i];
    }
    int ans = 1e9;
    for (int i = 1; i <= k; i++) {
    	ans = min(ans, pref[i] / (k - i + 1));
    }
    cout << ans << endl;
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
