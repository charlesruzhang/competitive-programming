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
    if (n <= 3) {
    	cout << "NO" << endl;
    	return;
    }
    cout << "YES" << endl;
    if (n == 4) {
    	cout << "1 * 2 = 2" << endl;
    	cout << "3 * 2 = 6" << endl;
    	cout << "6 * 4 = 24" << endl;
    	return;
    }
    if (n == 5) {

    	cout << "3 * 5 = 15" << endl;
    	cout << "4 * 2 = 8" << endl;
    	cout << "15 + 8 = 23" << endl;
    	cout << "23 + 1 = 24" << endl;
    	return;
    }
	cout << "1 + 2 = 3" << endl;
	cout << "3 - 3 = 0" << endl;
	cout << "0 * 5 = 0" << endl;
	for (int i = 7; i <= n; i++) {
		cout << "0 * " << i << " = 0" << endl;
	}
	cout << "4 * 6 = 24" << endl;
	cout << "0 + 24 = 24" << endl;
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
