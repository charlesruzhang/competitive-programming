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
    int n;
    cin >> n;
    vi x(2 * n), y(2 * n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    	x[n + i] = x[i];
    	y[n + i] = y[i];
    }
    if (n % 2 == 1) {
    	cout << "no" << endl;
    	return;
    }
    for (int i = 0; i < n / 2; i++) {
    	ll dx = x[i+1] - x[i];
    	ll dy = y[i+1] - y[i];

    	ll dx2 = x[i+1+n/2] - x[i+n/2];
    	ll dy2 = y[i+1+n/2] - y[i+n/2];
    	if (1ll * dx * dy2 != 1ll * dy * dx2 || (__int128)dx * dx + dy * dy != (__int128)dx2*dx2+dy2*dy2) {
    		cout <<"NO" << endl;
    		return;
    	}
    }
    cout <<"YES" << endl;
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
