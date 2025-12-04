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
    if (n == 2) {
    	cout << -1 << endl;
    	return;
    }
    if (n > 6) {
    	for (int i = 3; i <= n - 1; i++) {
    		cout << 2 << " " << i << endl;
    	}
    	cout << 1 << " " << 6 << endl;
    	cout << 1 << " " << n << endl;
    	return;
    }
    if (n == 3) {
    	cout << "1 3" << endl;
    	cout << "2 3" << endl;
    	return;
    }
    if (n == 4) {
    	cout << "1 2" << endl;
    	cout << "1 3" << endl;
    	cout << "1 4" << endl;
    	return;
    }
    if (n == 5) {
    	cout << "1 3" << endl;
    	cout << "5 3" << endl;
    	cout << "2 4" << endl;
    	cout << "2 5" << endl;
    	return;
    }
    if (n == 6) {
    	cout << "1 2" << endl;
    	cout << "1 3" << endl;
    	cout << "1 4" << endl;
    	cout << "2 5" << endl;
    	cout << "1 6" << endl;
    	return;
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
