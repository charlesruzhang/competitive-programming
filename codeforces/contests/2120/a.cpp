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
    vi a(6);
    int x = 0, y = 0;
    for (int i = 0; i < 6; i++) {
    	cin >> a[i];
    	if (i % 2) {
    		y += a[i] * a[i - 1];
    	}
    }
    int z = sqrt(y);
    if (z * z != y || z != max(a[0], a[1])) {
    	cout << "NO" << endl;
    	return;
    }
    if (a[0] < a[1]) {
    	swap(a[0], a[1]);
    	swap(a[2], a[3]);
    	swap(a[4], a[5]);
    }
    if (a[2] == a[0]) {
		a[1] += a[3] + a[5];
		if (a[4] != a[0] || a[1] != a[0]) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	} else {
		if (a[3] != a[5]) {
			cout << "NO" << endl;
		} else {
			a[2] += a[4];
			if (a[2] != a[0] || a[1] + a[3] != a[0]) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
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
