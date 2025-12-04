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
    int n, t;
    cin >> n >> t;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	while (pref[i+1] - pref[j] > t) {
    		j++;
    	}
    	ans = max(ans, (ll)i - j + 1);
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
