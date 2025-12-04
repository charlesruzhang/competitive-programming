// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl pref(n + 1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    map<ll, int> ma;
    ll ans = 0;
    for (int d = 0; d <= n; d++) {
    	for (int i = 0; i + d <= n; i++) {
    		ll x = pref[i] + pref[i + d];
    		//cout << i << " " << i + d << " " << x << endl;
    		if (d) ans += d - 1 - ma[x];
    		if (d == 0) ma[x]++;
    		else ma[x]+=2;
    	}
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
