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
    vl a(n);
    ll minn = 1e18;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	minn = min(minn, a[i]);
    }
    vl v;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
    	if (a[i] == minn) {
    		cout << "YES" << endl;
    		return;
    	}
    	if (a[i] % minn == 0) {
    		v.push_back(a[i]);
    	}
    }
    if (v.empty()) {
    	cout << "NO" << endl;
    	return;
    }
    ll g = v[0];
    for (int i = 1; i < v.size(); i++) {
    	g = __gcd(g, v[i]);
    }
    if (g == minn) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
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
