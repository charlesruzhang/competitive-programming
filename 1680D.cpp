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
    vi v;
    ll summ = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
   	vl pref(n + 1);
   	vi tot(n + 1);
   	ll ans = 0;
   	for (int i = 0; i < n; i++) {
   		pref[i+1] = pref[i] + a[i]; 
   		tot[i + 1] = tot[i] + (a[i] == 0 ? 1 : 0);
   	}
   	int T = tot[n];
   	ll S = pref[n];
   	if (S > 1ll * T * k || S < -1ll * T * k) {
   		cout << -1 << endl;
   		return;
   	}
   	for (int i = 0; i < n; i++) {
   		for (int j = i; j < n; j++) {
   			ll summ = pref[j + 1] - pref[i];
   			ll x = tot[j + 1] - tot[i];
   			ll maxx = summ - S + (T - x) * k;
   			ll minn = summ - S - (T - x) * k;
   			ll amaxx = min(maxx, summ + x * k);
   			ll aminn = max(minn, summ - x * k);
   			ans = max(ans, amaxx + 1);
   			ans = max(ans, -aminn + 1);
   		}
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
