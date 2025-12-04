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
    vl a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (i) b[i] = a[i-1] - a[i];
    }
    b[0] = a[n-1] - a[0];
    if (n == 1) {
    	cout << 0 << endl;
    	return;
    }
    vl y(n), x(n);
    for (int i = 1; i < n; i+=2) {
    	y[0]-= b[i];
    }
    for (int i = 1; i < n; i++) {
    	y[i] = b[i-1] - y[i-1];
    }
    for (int i = 2; i < 2 * n; i += 2) {
    	x[i % n] = x[(i-2) % n] + y[i % n];
    }
    ll minn = 0;
    for (int i = 0; i < n; i++) {
    	minn = min(minn, x[i]);
    }
    for (int i = 0; i < n; i++) {
    	cout << x[i] - minn << " ";
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
