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
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1) {
    	cout << 1 << endl;
    	cout << 1 << endl;
    	return;
    }
    if (k == 1 || k == n) {
    	cout << -1 << endl;
    	return;
    }
    cout << 3 << endl;
    if (k % 2 == 0) {
    	cout << 1 << " " << k << " " << k+1 << endl;
    } else {
    	cout << 1 << " " << k - 1 << " " << k + 2 << endl;
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
