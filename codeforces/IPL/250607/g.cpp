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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 1; i < n; i++) {
    	cin >> a[i];
    }
    a[0] = 1e9;
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int delta = 0;
    vi w(n);
    for (int i = 0; i < n; i++) {
    	while (i + delta < n && a[i] >= b[i+delta]) {
    		delta++;
    		if (i + delta >= n) {
    			break;
    		}
    	}
    	w[i] = delta;
    }
    ll tot = 1ll * m * delta;
    for (int i = 0; i < n; i++) {
    	if (w[i] == delta) {
    		int z = b[i + delta - 1] - 1;
    		tot -= min(z, m);
    		cout << tot << endl;
    		break;
    	}
    }
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
