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
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    if (a == b) {
    	cout << "YES" << endl;
    	return;
    }
    int z = 0, y = 0, x = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] % 2) {
    		z++;
    	} else {
    		x++;
    	}
    	if ((b[i] - a[i]) % 2) {
    		y++;
    	}
    }
    if (x % 2 && z % 2 == 0) {
    	cout << "NO" << endl;
    	return;
    }
    if (y > 1) {
    	cout << "NO" << endl;
    	return;
    }
    if (y == 1 && z % 2) {
    	cout << "YES" << endl;
    	return;
    } else if (y == 1) {
    	cout << "NO" << endl;
    	return;
    }
    if (x % 2) {
    	cout << "NO" << endl;
    } else {
    	cout << "YES" << endl;
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
