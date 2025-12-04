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
int query(int n) {
	cout << n << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
 	int x = 0, y = 0;
 	for (int i = 0; i < 30; i++) {
 		if (i % 2) {
 			x += (1 << i);
 		} else {
 			y += (1 << i);
 		}
 	}
 	int a = query(x);
 	int b = query(y);
 	a -= 2 * x;
 	b -= 2 * y;
 	int xx = 0, yy = 0;
 	for (int i = 1; i < 30; i+=2) {
 		if (a & (1 << i)) {
 			xx += (1 << (i - 1));
 			yy += (1 << (i - 1));
 		} else if (a & (1 << (i-1))) {
 			xx += (1 << (i - 1));
 		}
 	}

 	for (int i = 2; i <= 30; i+=2) {
 		if (b & (1 << i)) {
 			xx += (1 << (i - 1));
 			yy += (1 << (i - 1));
 		} else if (b & (1 << (i-1))) {
 			xx += (1 << (i - 1));
 		}
 	}
 	cout << "!" << endl;
 	int m;
 	cin >> m;
 	cout << ((m | xx) + (m | yy)) << endl;

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
