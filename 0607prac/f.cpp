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
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    map<int, int> ma;
    vi v(n, -1);
    for (int i = 0; i < n; i++) {
    	auto it = ma.find(a[i]);
    	if (it != ma.end()) {
    		v[it -> second] = i;
    		it -> second = i;
    	} else {
    		ma[a[i]] = i;
    	}
    }
    vi w(n);
    for (int i = 0; i < n; i++) {
    	if (v[i] != -1) w[v[i]]++;
    }
    vi pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + w[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (v[i] != -1) continue;
    	ans += (i + 1) - pref[i+1];
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
